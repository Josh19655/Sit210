#include <WiFiNINA.h>
#include "ThingSpeak.h"
#include "DHT.h"

#define DHTPIN 3           
#define DHTTYPE DHT11

char ssid[] = "HP";             
char pass[] = "joshkhangura";      

WiFiClient client;

unsigned long myChannelNumber = 3079532;                
const char * myWriteAPIKey = "LC0SAG19R9IHO5T3";        

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  dht.begin();
  WiFi.begin(ssid, pass);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  
  ThingSpeak.begin(client);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Sensor error!");
    return;
  }

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);

  int status = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (status == 200) {
    Serial.println("Data sent to ThingSpeak");
  } else {
    Serial.println("Error sending data. HTTP code: " + String(status));
  }

  delay(15000);  
}