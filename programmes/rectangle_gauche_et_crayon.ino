#include <Servo.h>

Servo Servo_droit;
Servo Servo_gauche;
#define MOTEUR_G 12
#define MOTEUR_D 13
#define T1_1 1700//durée T1 sens horaire
#define T1_2 1300//durée T2 sens trigonométrique
#define T1_3 1500//durée T3 sens arret


int POINT_HAUT = 25;
int POINT_BAS = 100;
int position;
int LATENCE = 10;


Servo leve;

void setup() {
  // put your setup code here, to run once:

 analogReference(DEFAULT);
  Serial.begin(9660);
  Servo_droit.attach(MOTEUR_D);  
  Servo_gauche.attach(MOTEUR_G);


  leve.attach(10);
  leve.write(POINT_BAS);
  pinMode(2, INPUT);

/*pour robot bleu et gris (3 et 4)
Avancer(2000);
leve.write(POINT_HAUT); // pour lever le crayon
delay(10);
Pivote_droite(1000);
leve.write(POINT_BAS);
delay(10);
Avancer(1000);
leve.write(POINT_HAUT); // pour lever le crayon
delay(10);
Pivote_droite(1000);
leve.write(POINT_BAS);
delay(10);
Avancer(2000);
leve.write(POINT_HAUT); // pour lever le crayon
delay(10);
Pivote_droite(1000);
leve.write(POINT_BAS);
delay(10);
Avancer(1500);

arret();

*/

//pour robots rouge et jaune (1 et 2)
Avancer(2000);
leve.write(POINT_HAUT); // pour lever le crayon
delay(10);
Reculer(1200);
Pivote_gauche(1100);
Avancer(400);
leve.write(POINT_BAS);
delay(10);
Avancer(1500); 
leve.write(POINT_HAUT); // pour lever le crayon
delay(10);
Reculer(1200);
Pivote_gauche(1100);
Avancer(400);
leve.write(POINT_BAS);
delay(10);
Avancer(2000);
leve.write(POINT_HAUT); // pour lever le crayon
delay(10);
Reculer(1200);
Pivote_gauche(1100);
Avancer(400);
leve.write(POINT_BAS);
delay(10);
Avancer(1500);

arret();


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

void AngleDroitDroite(){
  leve.write(POINT_HAUT); // pour lever le crayon
  delay(10);
  Reculer(1200);
  Pivote_droite(1100);
  Avancer(400);
  leve.write(POINT_BAS);
  delay(10);
}

