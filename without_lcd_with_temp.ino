/* Electronoobs Bluetooth data receive with
 * Android and Arduino. Small example.
 * Remember to disconnect the Rx and Tx pins of the HC-06 when
 * uploading the code
 * 
 * Subscribe: http://www.youtube.com/c/ELECTRONOOBS
 * Tutorial: http://www.electronoobs.com/eng_arduino_tut20_2.php
 */
const int trigPin = 6; const int echoPin = 7; long duration, cm; 
int height = 9;
int value = height/5;
int count =0;  
int var = 0; 
const int buzzPin = 13;

/********************************************************************/
// First we include the libraries
#include <OneWire.h> 
#include <DallasTemperature.h>
/********************************************************************/
// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 2 
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
/********************************************************************/ 

void setup() {
  // initialize serial communication with HC-06:
  Serial.begin(9600);  pinMode(trigPin, OUTPUT);  pinMode(echoPin, INPUT);
 // Start up the library 
 sensors.begin();
}

void loop()
{
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds. // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);
  // Read the signal from the sensor: a HIGH pulse whose  // duration is the time (in microseconds) from the sending  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(echoPin, HIGH);
  // convert the time into a distance
  cm = (duration/2)/29.1; 
//  Serial.println(cm); 
  delay(3000);
  if(cm >= height)  
{ 
   if(var != 0) 
   { 
    count = 0; 
    var = 0;
   } 
   else 
   { 
    count++;
   }
  

   if(count ==4) 
   { 
      digitalWrite(buzzPin, HIGH); 
      delay(100); 
      digitalWrite(buzzPin, LOW); 
      delay(100);  
      digitalWrite(buzzPin, HIGH); 
      delay(100); 
      digitalWrite(buzzPin, LOW); 
      delay(500); 
      Serial.print("Reminder: Drink Water");
      delay(2000);
      
   }  
   else
    Serial.print("Water Level: 0%"); 
}
     
  else if(cm<height && cm >= height-value) 
  { 
    if(var != 20) 
   { 
    count = 0; 
    var = 20;
   } 
   else 
   { 
    count++;
   } 
  

    if(count ==4) 
   { 
      digitalWrite(buzzPin, HIGH); 
      delay(100); 
      digitalWrite(buzzPin, LOW); 
      delay(100);  
      digitalWrite(buzzPin, HIGH); 
      delay(100); 
      digitalWrite(buzzPin, LOW); 
      delay(500); 
      Serial.print("Reminder: Drink Water");
      delay(2000);

   } 
   else 
     Serial.print("Water Level: 20%"); 
  }
    
  else if(cm<height && cm >= height-(2*value))  
  { 
    if(var != 40) 
   { 
    count = 0; 
    var = 40;
   } 
   else 
   { 
    count++;
   } 
     

    if(count ==4) 
   { 
      digitalWrite(buzzPin, HIGH); 
      delay(100); 
      digitalWrite(buzzPin, LOW); 
      delay(100);  
      digitalWrite(buzzPin, HIGH); 
      delay(100); 
      digitalWrite(buzzPin, LOW); 
      delay(500); 
      Serial.print("Reminder: Drink Water");
      delay(2000);
   } 
   else 
    Serial.print("Water Level: 40%");
  }
   
  else if(cm<height && cm >= height-(3*value)) 
    { 
    if(var != 60) 
   { 
    count = 0; 
    var = 60;
   } 
   else 
   { 
    count++;
   } 
    

    if(count ==4) 
   { 
      digitalWrite(buzzPin, HIGH); 
      delay(100); 
      digitalWrite(buzzPin, LOW); 
      delay(100);  
      digitalWrite(buzzPin, HIGH); 
      delay(100); 
      digitalWrite(buzzPin, LOW); 
      delay(500); 
      Serial.print("Reminder: Drink Water");
      delay(2000);
   } 
   else 
    Serial.print("Water Level: 60%"); 
  }
  else if(cm<height && cm >= height-(4*value)) 
    { 
    if(var != 80) 
   { 
    count = 0; 
    var = 80;
   } 
   else 
   { 
    count++;
   } 
    

    if(count ==4) 
   { 
      digitalWrite(buzzPin, HIGH); 
      delay(100); 
      digitalWrite(buzzPin, LOW); 
      delay(100);  
      digitalWrite(buzzPin, HIGH); 
      delay(100); 
      digitalWrite(buzzPin, LOW); 
      delay(500); 
      Serial.println("Reminder: Drink Water");
      delay(2000);
   } 
   else 
    Serial.print("Water Level: 80%"); 
  }
  else if(cm>=0) 
    { 
    if(var != 100) 
   { 
    count = 0; 
    var = 100;
   } 
   else 
   { 
    count++;
   } 

   if(count ==4) 
   { 
      digitalWrite(buzzPin, HIGH); 
      delay(100); 
      digitalWrite(buzzPin, LOW); 
      delay(100);  
      digitalWrite(buzzPin, HIGH); 
      delay(100); 
      digitalWrite(buzzPin, LOW); 
      delay(500); 
      Serial.print("Reminder: Drink Water"); 
      delay(2000);
   } 
   else
    Serial.print("Water Level: 100%");
  }
//  else 
//   Serial.println(cm); 
//  if(cm < 20)
//  {
//    Serial.println(cm); delay(400);
//  }
//  else
//  {
//    Serial.println("Not in Range"); delay(400);
//  }
 // call sensors.requestTemperatures() to issue a global temperature 
 // request to all devices on the bus 
/********************************************************************/
 sensors.requestTemperatures(); // Send the command to get temperature readings 
/********************************************************************/
 Serial.print("Temperature is: "); 
 Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?  
   // You can have more than one DS18B20 on the same bus.  
   // 0 refers to the first IC on the wire 
   delay(3000); 
}
