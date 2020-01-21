#include <dht.h>

#define dataPin A0// Defines pin number to which the sensor is connected

dht DHT; // Creats a DHT object

void setup() {

  Serial.begin(9600);

}

void loop() {

  int readData = DHT.read11(dataPin); // Reads the data from the sensor

  float t = DHT.temperature; // Gets the values of the temperature

  float h = DHT.humidity; // Gets the values of the humidity

  int i=analogRead(A1);

  float v=(i*0.00488*21)+0.6;

  int k=analogRead(A2);

  float p=(k*0.00488*21)-0.5;

 

  // Printing the results on the serial monitor

 

  Serial.print(t);

  Serial.print("    ");

  Serial.print(v);

  Serial.print("    ");

  Serial.println(p);

 

  delay(2000); // Delays 2 secods, as the DHT11 sampling rate is 0.5Hz

}
