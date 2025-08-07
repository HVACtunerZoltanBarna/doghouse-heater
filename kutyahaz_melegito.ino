#include<avr/wdt.h>

float temprad;
float temproom;
float diff;
int reading;
#define tempPin1 A0 //temprad
#define tempPin2 A1 //temproom
#define maxtemp 95
#define roommintemp 18
#define resolution 0.3
byte a=0;

void setup()
{
analogReference(INTERNAL);
Serial.begin(9600);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
wdt_enable (WDTO_8S);// az állási idő behatárolása
}


void loop()
{
reading = analogRead(tempPin1);
temprad = reading / 9.31;
reading = analogRead(tempPin2);
temproom = reading / 9.31;


Serial.println(temprad);
Serial.println(temproom);

if (temprad<maxtemp){
diff=roommintemp-temproom;
//Serial.println(diff);
if (diff>=0) {
    a = diff/(float)resolution;
    a=constrain(a,0,6);}
else a=0;
}
else a=0;
power(a);
Serial.println(a);
for(int i=0; i<60;i++){
delay(1000);
wdt_reset();
}
}

void power(byte a){
  switch (a){
  case 0:
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    break;
  case 1:
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    break;
  case 2:
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    break; 
  case 3:
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    break; 
  case 4:
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    break; 
  case 5:
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    break; 
  case 6:
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    break; 
    
  }
  }
