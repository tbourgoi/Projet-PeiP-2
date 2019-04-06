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


//pour robots rouge et jaune (1 et 2)
/*lettre_P();
lettre_O();
lettre_L();// problème liaison on Y trop bas
lettre_Y();
lettre_T();
lettre_E();
lettre_C();
lettre_H();
*/
logo_polytech();

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

void AngleDroitGauche(){
  leve.write(POINT_HAUT); // pour lever le crayon
  delay(10);
  Reculer(1200);
  Pivote_gauche(1100);
  Avancer(400);
  leve.write(POINT_BAS);
  delay(10);
}

void logo_polytech(){
  Avancer(750);
  leve.write(POINT_HAUT); // pour lever le crayon
  delay(10);
  Reculer(1000);
  Pivote_droite(1100);
  Avancer(400);
  leve.write(POINT_BAS);
  delay(10);
  Pivote_gauche(3500);
}

void cercle(){
  Pivote_droite(4200);
}


void lettre_P(){

leve.write(POINT_HAUT); 
delay(10);
Avancer(300);
Pivote_gauche(1100);
leve.write(POINT_BAS);
delay(10);
Avancer(3000);
leve.write(POINT_HAUT); 
delay(10);
Reculer(1500);
leve.write(POINT_BAS);
delay(10);
Pivote_gauche(2000);
leve.write(POINT_HAUT); 
delay(10);
Pivote_gauche(100);
Avancer(2200);
Pivote_gauche(1100);
Avancer(1700);

}

void lettre_O(){
  leve.write(POINT_HAUT); 
  delay(10);
  Avancer(300);
  Pivote_gauche(1100);
  Avancer(1500);
  leve.write(POINT_BAS);
  delay(10);
  Pivote_droite(4200);
  leve.write(POINT_HAUT); 
  delay(10);
  Reculer(1500);
  Pivote_droite(1200);
  Avancer(1300);
}

void lettre_L(){
  leve.write(POINT_HAUT); 
  delay(10);
  Avancer(300);
  Pivote_gauche(1100);
  Avancer(100);
  leve.write(POINT_BAS);
  delay(10);
  Avancer(2700);
  leve.write(POINT_HAUT); 
  delay(10);
  Reculer(2500);
  AngleDroitDroite();
  Avancer(200);
  leve.write(POINT_BAS);
  delay(10);
  Avancer(1100);
  leve.write(POINT_HAUT); 
  delay(10);
  Avancer(100);
  
}

void lettre_Y(){
	leve.write(POINT_HAUT); 
  delay(10);
  Avancer(300);
  Pivote_gauche(1100);
  Avancer(100);
  leve.write(POINT_BAS);
  delay(10);
  Avancer(1700);
  leve.write(POINT_HAUT); 
  delay(10);

  
  Reculer(900);
  Pivote_gauche(450);
  Avancer(550);
  leve.write(POINT_BAS);
  delay(10);
  Avancer(750);
  leve.write(POINT_HAUT); 
  delay(10);
  
  Reculer(1750);
  Pivote_droite(900);
  Avancer(450);
  leve.write(POINT_BAS);
  delay(10);
  Avancer(750);
  leve.write(POINT_HAUT); 
  delay(10);
  Reculer(750);
  Pivote_gauche(450);
  Reculer(2500);
  Pivote_droite(1100);
  Avancer(500);
}

void lettre_T(){
  leve.write(POINT_HAUT); 
  delay(10);
  Avancer(300);
  Pivote_gauche(1100);
  leve.write(POINT_BAS);
  delay(10);
  Avancer(2500);
  leve.write(POINT_HAUT);
  delay(10);
  Reculer(1200);
  Pivote_gauche(1100);
  Avancer(1250);
  leve.write(POINT_BAS);
  delay(10);
  Reculer(1800);
  leve.write(POINT_HAUT); 
  delay(10);
  Avancer(750);
  Pivote_gauche(1100);
  Avancer(2000);
  Pivote_gauche(1100);
  Avancer(1100);
}

void lettre_E(){
  leve.write(POINT_HAUT); 
  delay(10);
  Avancer(300);
  Pivote_gauche(1100);
  Avancer(600);
  leve.write(POINT_BAS);
  delay(10);
  Avancer(1900);
  AngleDroitDroite();
  Avancer(750);
  leve.write(POINT_HAUT); 
  delay(10);
  Reculer(1850);
  Pivote_droite(1100);
  Avancer(1400);

  AngleDroitGauche();
  Avancer(750);
  leve.write(POINT_HAUT); 
  delay(10);
  Reculer(1850);
  Pivote_droite(1100);
  Avancer(1400);
  
  AngleDroitGauche();
  Avancer(750);
  leve.write(POINT_HAUT); 
  delay(10);
  Avancer(200);
  //Reculer(1850);
  //Pivote_droite(1100);
  //Avancer(100);
  //Pivote_gauche(1050);
  //Avancer(1000);
  
  
}

void lettre_C(){
  leve.write(POINT_HAUT); 
  delay(10);
  Avancer(300);
  Pivote_gauche(1100);
  Avancer(500);
  leve.write(POINT_BAS);
  delay(10);
  Avancer(2000);
  AngleDroitDroite();
  Avancer(750);
  leve.write(POINT_HAUT); 
  delay(10);
  Reculer(1850);
  Pivote_droite(1100);
  Avancer(2300);
  
  AngleDroitGauche();
  Avancer(750);
  leve.write(POINT_HAUT); 
  delay(10);
  //Reculer(1850);
  //Pivote_droite(1100);
  //Avancer(100);
  //Pivote_gauche(1050);
  Avancer(900);
}

void lettre_H(){
  leve.write(POINT_HAUT); 
  delay(10);
  Avancer(300);
  Pivote_gauche(1100);
  Avancer(100);

  leve.write(POINT_BAS);
  delay(10);
  Avancer(2500);
  leve.write(POINT_HAUT);
  delay(10);
  Reculer(1250);

  AngleDroitDroite();
  Avancer(1100);;

  AngleDroitDroite();
  leve.write(POINT_HAUT);
  delay(10);
  Reculer(1250);

  leve.write(POINT_BAS);
  delay(10);
  Avancer(2500);

  leve.write(POINT_HAUT);
  delay(10);
  Pivote_gauche(1100);
  Avancer(800);
}
