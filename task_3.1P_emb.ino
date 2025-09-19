#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println("BH1750 ready");
  } else {
    Serial.println("Error initialising BH1750");
  }
}
void loop() {
  float lux = lightMeter.readLightLevel();
  if (lux < 0) lux = 0;  
  Serial.print("Light: ");
  Serial.print(lux, 2);  
  Serial.println(" lx");
  delay(1000);  // 
}