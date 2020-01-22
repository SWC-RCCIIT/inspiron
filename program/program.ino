#include <dht.h>

dht DHT;

#define DHT11_PIN A0
char m;
float linear(float a,float b)
{
float  c=(0.19454252*a)+(0.07786602*b)-0.9862709255780508;
  return c;
}

void setup()
{
  Serial.begin(9600);
 
}

void loop()
{
 
 
  int i=analogRead(A1);
  int j=analogRead(A2);
  float v=i*0.004888*21;
  float q=j*0.004888*21;
 
 
 
 
  int chk = DHT.read11(DHT11_PIN);
 
 
 
   float expectvalue=linear(v,DHT.temperature);
   if(v>13||DHT.temperature>37)
   {
    Serial.print("INVALID");
   }
   else
   {
   
   
  Serial.print("TEAMP: ");
  Serial.print(DHT.temperature, 1);
   Serial.print("   ");
   Serial.print("VOLT: ");
    Serial.print(v);
    Serial.print(" AMPS: ");
    Serial.print(q);
    Serial.print("   ");
    Serial.print("EXPECT: ");
    Serial.print(expectvalue,5);
    Serial.print("   ");
    Serial.print("STATUS: ");
    if(abs(expectvalue)-q<0.4)
    Serial.println("OK");
    
    else if(abs(expectvalue)-q>0.5)
    
    Serial.println("NOTGOOD");
    
    else if(abs(expectvalue)-q>0.7)
    
      Serial.println("ABNORMAL");
    
    else if(abs(expectvalue)-q>1.0)
    Serial.println("FAULT");
   
   
   }
    delay(2000);
}
