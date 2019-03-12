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
//pour robots bleu et rose
Avancer(2000);
Pivote_droite(1000);
Avancer(1000);
Pivote_droite(1000);
Avancer(2000);
Pivote_droite(1000);
Avancer(1500);

arret();

//pour robots rouge et jaune
/*Avancer(2000);
Pivote_droite(1050);
Avancer(1000);
Pivote_droite(1050);
Avancer(2000);
Pivote_droite(1050);
Avancer(1500);

arret();
*/
}

void loop()
{
  
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
