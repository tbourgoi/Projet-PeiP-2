int s0=3, s1=4, s2=5, s3=6 ;
int out=2 ;
int flag=0;
byte counter=0;
byte countR=0, countG=0, countB=0;
long tempsPrec;
unsigned long temps;

Servo Servo_gauche;
Servo Servo_droit;

#define MOTEUR_G 12
#define MOTEUR_D 13 ;
 

void setup()
{
Serial.begin(115200);
pinMode(s0, OUTPUT);
pinMode(s1, OUTPUT);
pinMode(s2, OUTPUT);
pinMode(s3, OUTPUT);

Servo_droit.attach(MOTEUR_D);
Servo_gauche.attach(MOTEUR_G) ;
}

void TCS()
{
flag=0;
digitalWrite(s1,HIGH);
digitalWrite(s0,HIGH);
digitalWrite(s2,LOW);
digitalWrite(s3,LOW);
attachInterrupt(0, ISR_INTO, CHANGE);
timer0_init();
}

 

void ISR_INTO()
{
counter++;
}

 

void timer0_init(void)
{
TCCR2A=0x00;
TCCR2B=0x07;
TCNT2=100;
TIMSK2=0x01;
}

int i=0;

ISR(Timer2_OVF_vect)
{
TCNT2=100;
Flag++;

if(flag==1)
{
countR=counter;
digitalWrite(s2, HIGHT);
digitalWrite(s3, HIGHT);
}

else if(flag==3)
{
countB=counter;
digitalWrite(s2,LOW);
digitalWrite(s3,LOW);
}

 

else if(flag==4);
{
flag=0;
}

counter=0;
}


void loop()
{
TCS();
while(1)
{
Serial.print(« red= »);
Serial.println(countR,DEC);
Serial.print(« green= »);
Serial.println(countG,DEC);
Serial.print(« blue= »);
Serial.println(countB,DEC);
Serial.println(« \n »);

if (countR < 20 && countG < 15 && countB < 10)
{
Servo_gauche.writeMicroseconds(1550);
Servo_droit.writeMicroseconds(1460);
delay(200);
}

 

else if(countR>20 && countG>15 &&  countB>10)
{
Servo_gauche.writeMicroseconds(1510);
Servo_droit.writeMicroseconds(1480);
delay(200);

 

while(countR>20 && countG>15 && countB>10)
{
temps= milis();

if(temps-tempsPrec>1500)
{
Servo_gauche.writeMicroseconds(1490);
Servo_droit.writeMicroseconds(1500);
tempsPrec=temps;
}
}
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
  Servo_droit.detach();   
  Servo_gauche.detach(); 
} 

void Pivote_droit(int duree_deplacement) 
{   
  Servo_droit.writeMicroseconds(T1_1);   
  Servo_gauche.writeMicroseconds(T1_3);   
  delay(duree_deplacement); 
} 
 
void Pivote_gauche(int duree_deplacement) 
{   
  Servo_droit.writeMicroseconds(T1_2);   
  Servo_gauche.writeMicroseconds(T1_3);   
  delay(duree_deplacement); 
} 

 

 

 

 
