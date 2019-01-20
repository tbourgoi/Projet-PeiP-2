#include <Servo.h>

#define MOTEUR_G 12
#define MOTEUR_D 13
#define T1_1 1700//durée T1 sens horaire
#define T1_2 1300//durée T1 sens trigonométrique
#define T1_3 1500//durée T1 sens arret

#define IR_DROIT 1
#define IR_GAUCHE 0
#define LEDD_PIN_G 11
#define LEDD_PIN_D 10

#define DISTANCE 10

Servo Servo_droit;
Servo Servo_gauche;

void setup() {
  // put your setup code here, to run once:
  analogReference(DEFAULT);
  Serial.begin(9660);
  Servo_droit.attach(MOTEUR_D);  
  Servo_gauche.attach(MOTEUR_G);
pinMode(IR_DROIT, INPUT);
pinMode(IR_GAUCHE, INPUT);
pinMode(LEDD_PIN_G, OUTPUT);
digitalWrite(LEDD_PIN_G, LOW);
pinMode(LEDD_PIN_D, OUTPUT);
digitalWrite(LEDD_PIN_D, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  int infra_droit=analogRead(IR_DROIT);
  int volt_droit=map(infra_droit, 0, 1023, 0, 5000);
  int cm_droit=(21.61/(volt_droit-0.1696))*1000;

  Serial.println(cm_droit);
  
  int infra_gauche=analogRead(IR_GAUCHE);
  int volt_gauche=map(infra_gauche, 0, 1023, 0, 5000);
  int cm_gauche=(21.61/(volt_gauche-0.1696))*1000;
  
  Serial.println(cm_gauche);

  if(cm_droit<=DISTANCE)
  {
    digitalWrite(LEDD_PIN_D, HIGH);
    Reculer(300);
    digitalWrite(LEDD_PIN_D, LOW);
    Pivote_gauche(1000);
  } 
else 
{  
     if(cm_gauche<=DISTANCE)
    {
      digitalWrite(LEDD_PIN_G, HIGH);
      Reculer(300);
      digitalWrite(LEDD_PIN_G, LOW);
      Pivote_droit(1000);
    }
    else {
      Avancer(1000);
      Pivote_droit(4100); //tour complet pour un cercle robot rouge et jaune
      // Pivote_droite(4450); tour complet pour robot bleu et le rose
    }
  }
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
//  Servo_droit.detach();   
//  Servo_gauche.detach(); 
  Servo_droit.writeMicroseconds(T1_3);   
  Servo_gauche.writeMicroseconds(T1_3);   

} 


void Pivote_droit(int duree_deplacement) 
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
