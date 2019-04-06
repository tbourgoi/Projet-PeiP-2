#include <TimerOne.h>
#define s0 3
#define s1 4
#define s2 5
#define s3 6
#define OUT 2

int g_count=0;
int g_array[3];
int g_flag=0;
float g_SF[3];




void TSC_init()//initialise les données (celles concernant les pins, leds..)
{
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(OUT,INPUT);
  digitalWrite(s0,LOW);
  digitalWrite(s1,HIGH);
}




void filtreColor(int level1, int level2)
{
  if(level1!=0)
  {
    level1=HIGH;
  }
  if(level2!=0)
  {
    level2=HIGH;
  }
  digitalWrite(s2,level1);
  digitalWrite(s3,level2);
}




void conteur()
{
  g_count++;
}



void rappel()
{
  switch(g_flag)
  {
    case 0:
      Serial.println("-> début");
      balanceBlanc(LOW,LOW);//filtre sans rouge 
      break;

    case 1:
      Serial.print("->Fréquence de R=");
      Serial.println(g_count);
      g_array[0]=g_count;
      balanceBlanc(HIGH,HIGH); //filtre sans vert
      break;

    case 2:
      Serial.print("->Fréquence de G=");
      Serial.println(g_count);
      g_array[1]=g_count;
      balanceBlanc(LOW,HIGH); //filtre sans bleu
      break;

    case 3:
      Serial.print("->Fréquence de B=");
      Serial.println(g_count);
      Serial.println("->fin");
      g_array[2]=g_count;
      balanceBlanc(HIGH,LOW); //pas de filtre 
      break;
    default:
      g_count=0;
      break;    
    
  }
}

void balanceBlanc(int level0, int level1)// balance des blancs
{ 
  g_count=0;
  g_flag ++;
  filtreColor(level0, level1);
  Timer1.setPeriod(1000000);
  
}

void setup() {
  TSC_init();
  Serial.begin(9600);
  Serial.println("initialisé");
  Timer1.initialize();
  Timer1.attachInterrupt(rappel);
  attachInterrupt(0, conteur, RISING);
  delay(4000);

  for (int i = 0; i < 3; i++) {
	  Serial.println(g_array[i]);
  }

   g_SF[0] = 255.0 / g_array[0];  // valeur R   
   g_SF[1] = 255.0 / g_array[1] ; // valeur G   
   g_SF[2] = 255.0 / g_array[2] ; // valeur B   
   Serial.println(g_SF[0]);   
   Serial.println(g_SF[1]);   
   Serial.println(g_SF[2]); 
  

}

void loop() {
  g_flag=0;
  for (int i = 0; i < 3; i++) {
	  Serial.println(int(g_array[i] * g_SF[i]));
  }
  delay(4000);
  }
