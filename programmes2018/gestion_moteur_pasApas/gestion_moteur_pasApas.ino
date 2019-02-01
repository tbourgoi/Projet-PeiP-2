#include <Servo.h>

Servo leve;


void setup() {
    Serial.begin(9660);
    Serial.print("initialisé");
    leve.attach(10);
}

void loop() {
  for (int position = 0; position <= 180; position++) {
    leve.write(position);
    delay(15);
  }
  
  // Fait bouger le bras de 180° à 10°
  for (int position = 180; position >= 0; position--) {
    leve.write(position);
    delay(15);
  }
}
