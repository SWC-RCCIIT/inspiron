#include <dht.h>

#define dataPin A0// Defines pin number to which the sensor is connected
const int currentPin = A2;
int sensitivity = 66;
int adcValue= 0;
int offsetVoltage = 2500;
double adcVoltage = 0;
double currentValue = 0;
dht DHT; // Creats a DHT object

void setup() {
  

  Serial.begin(9600);
  delay(2000);

}



void loop() {
  adcValue = analogRead(currentPin);
  adcVoltage = (adcValue / 1024.0) * 5000;
  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);

  int readData = DHT.read11(dataPin); // Reads the data from the sensor

  float t = DHT.temperature; // Gets the values of the temperature

  
  int i=analogRead(A1);

  float v=(i*0.00488*21)+0.6;

  
 

  // Printing the results on the serial monitor

 

  Serial.print(t);

  Serial.print("    ");

  Serial.print(v);

  Serial.print("    ");

  Serial.println(adcValue,3);
  delay(2000);

 

  

}
