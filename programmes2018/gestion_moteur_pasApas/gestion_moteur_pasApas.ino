
#include <Servo.h>

Servo leve;

int borneMin = 25;
int borneMax = 100;
int position;
void setup() {
    Serial.begin(9660);
    Serial.print("initialisé");
    leve.attach(10);
    leve.write(borneMin);
}

void loop() {
 /*
  for (int position = borneMin ; position <= borneMax; position++) {
    leve.write(position);
    delay(25);
  }
  
  // Fait bouger le bras de 180° à 10°
  for (int position = borneMax; position >= borneMin; position--) {
    leve.write(position);
    delay(25);
  }*/
}
