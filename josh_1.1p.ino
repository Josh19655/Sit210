void dot() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print(".");
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
}

void dash() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("-");
  delay(600);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
}

void letterSpace() {
  Serial.print(" ");
  delay(800);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  delay(2000);
  Serial.println("Blinking name: JOSH in Morse Code");
}

void loop() {
  // J = .---
  dot(); dash(); dash(); dash();
  letterSpace();

  // O = ---
  dash(); dash(); dash();
  letterSpace();

  // S = ...
  dot(); dot(); dot();
  letterSpace();

  // H = ....
  dot(); dot(); dot(); dot();
  letterSpace();

  Serial.println();
  delay(3000);
}
