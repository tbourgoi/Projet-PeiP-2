
#include <Servo.h>

Servo leve;

int pointHaut = 25;
int pointBas = 100;
int position;
int latence = 10;

void setup() {
    Serial.begin(9660);
    Serial.print("initialisé");
    leve.attach(10);
    leve.write(pointBas);
	  pinMode(6, INPUT);
	
}

void loop() {
  /*leve.write(pointBas);
  delay(1000);*/
  
  for (int position = pointHaut ; position <= pointBas && digitalRead(6) == LOW ; position++) {
    leve.write(position);
    delay(latence);
  }
  
  // Fait bouger le bras de 180° à 10°
  for (int position = pointBas; position >= pointHaut && digitalRead(6) == LOW; position--) {
    leve.write(position);
    delay(latence);
  }

  if (digitalRead(6) == HIGH){
	  position = pointBas;
	  leve.write(pointBas);
    //Serial.println("bouton appuyé");
    //delay(1000);
  }

}
