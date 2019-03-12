#include <Servo.h>

Servo Servo_droit;
Servo Servo_gauche;
#define MOTEUR_G 12
#define MOTEUR_D 13
#define T1_1 1700//durée T1 sens horaire
#define T1_2 1300//durée T1 sens trigonométrique
#define T1_3 1500//durée T1 sens arret

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
Servo_droit.attach(MOTEUR_D);  
Servo_gauche.attach(MOTEUR_G);

//cas ou le robot détecte un autre robot avec le capteur IR gauche
Pivote_droite(1050);
Avancer(1000);
Pivote_gauche(1250);
Avancer(2000);

//cas ou le robot détecte un autre robot avec le capteur IR droit
Pivote_gauche(1050);
Avancer(1000);
Pivote_droite(1250);
Avancer(2000);

//cas ou le robot détecte une ligne noire
Pivote_droite(2500);


}

void loop() {
  // put your main code here, to run repeatedly:

}

void Avancer (int duree_deplacement)
{
Servo_droit.writeMicroseconds(T1_2);
Servo_gauche.writeMicroseconds(T1_1);
delay (duree_deplacement);
}

void Reculer(int duree_deplacement)
{
  Servo_droit.writeMicroseconds(T1_1);
  Servo_gauche.writeMicroseconds(T1_2);
  delay (duree_deplacement);
}  

void arret(void)
{  
  Servo_droit.writeMicroseconds(T1_3);   
  Servo_gauche.writeMicroseconds(T1_3);   
}

/* les fonction pivote_gauche et
 pivote_droit font tounrer le robot à 90° 
 pour 1250 à gauche et 1050 à droite
 */
void Pivote_droite(int duree_deplacement)
{  
  Servo_droit.writeMicroseconds(T1_3);  
  Servo_gauche.writeMicroseconds(T1_1);  
  delay(duree_deplacement);
}
 
void Pivote_gauche(int duree_deplacement)
{  
  Servo_droit.writeMicroseconds(T1_2);  
  Servo_gauche.writeMicroseconds(T1_3);  
  delay(duree_deplacement);
}
