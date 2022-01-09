/*
 Project Name  : CARBON MONOXIDE POISONING PREVENTION SYSTEM 
 Revision Date : 27.12.2021
 Author        : Yasemin Karakaya
 //------------------------------------------------------------------------------------------
 Purpose       : Many people die every year due to gas poisoning. 
                 Thanks to this system, we can warn people more easily and ventilate the environment easily.

 //------------------------------------------------------------------------------------------
 System  Input :    
                    1) MQ-2 Sensor    : To measure the gas amount of the environment.
                    2)Button          : To run the system.
 System Output :
                    1)Buzzer          : To alert with sound.
                    2)Green Led       : To indicate the system is active or not, to indicate that gas density is less in the environment.
                    3)Red Led         :To indicate that gas density is high in the environment.
  //------------------------------------------------------------------------------------------
     servo-motors:
                  1) Door             : To open the door, when gas density is high, To close the door, when gas density is less.   
                  2) window           : To open the window, when gas density is high, To open the window, when gas density is less.
  //-----------------------------------------------------------------------------------------
  System Work  :   It reacts according to the amount of gas taken with the help of mq2 gas sensor. 
                   When the button is pressed, the system is ready for operation.
                   When the environment is clean, the green LED lights up. The gas density is understood by the mq2 gas sensor.
                   If the gas density is high in the environment, the red led lights up, the buzzer sounds to warn the environment, 
                   the window and door are opened with the servo motor to ventilate the environment.
                   When the gas density decreases, it returns to its original state.


  //-----------------------------------------------------------------------------------------
 */



  //------------------------------------------------------------------------------------------
#include <Servo.h>             // Library required for the servo motor to work.
  // DEFINITIONS
  
int button =13;                 // Button is connected to Digital 13 pin.
 int redLed = 9;                // Red led is connected to Digital 9 pin.
int greenLed = 10;              // Green led is connected to Digital 10 pin.
int buzzer = 11;                // Buzzer is connected to Digital 11 pin.
int mq_2 = A0;                  // MQ-2 sensor connected to Analog 0 pin. MQ-2 sensor takes the gas from the environment. 
int sensorThres = 220;          // Your threshold value
//---------------------------------------------------------------------------------------------

Servo door;                     // a servo motor object named door.
Servo window;                   // a servo motor object named window.

// SETUP CODE AREA
void setup() {
  window.attach(2);             // The data pin of the servo motor(window) is connected to Digital 3 pin.
  door.attach(5);               // The data pin of the servo motor(door) is connected to Digital 3 pin.
  pinMode(button, INPUT);       // Button defined as INPUT.
  pinMode(redLed, OUTPUT);      // Red led defined as OUTPUT.
  pinMode(greenLed, OUTPUT);    // Green led defined as OUTPUT.
  pinMode(buzzer, OUTPUT);      // Buzzer defined as OUTPUT.
  pinMode(mq_2, INPUT);         // MQ-2 defined as INPUT.
  digitalWrite(greenLed, HIGH); // When button is ON,green led is HIGH.
  Serial.begin(9600);           // Sets the band rate for serial data transmission.
}
//--------------------------------------------------------------------------------------------------

// MAIN CODE AREA
void loop() {
  int analogSensor = analogRead(mq_2);   // Read the analog sensor value.
  
   
   

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);  // Write the value to the serial monitor
     // Checks if it has reached the threshold value
  if(digitalRead(button) ==1){ // If button is equal to 1, the codes work.
  
    if (analogSensor > sensorThres)  // If anolog sensor is greater than sensor thres, buzzer is ON,redLed is ON,greenLed is OFF.
                                     // the angle of the door and window is equal to 80 degree,
  {
    window.write(80);                // The angle of the window is 80.
    delay(100);                      // Wait for a 100 miliseconds.
    door.write(80);                  //The angle of the door is 80.
    delay(100);                      // Wait for a 100 miliseconds.
    digitalWrite(redLed, HIGH);      // redLed is ON
    digitalWrite(greenLed, LOW);     // greenLed is OFF.
    digitalWrite(buzzer,8000);       // Buzzer is ON
    
  }
  else                               // If analog sensor is not greater then sensor thres,buzzer is OFF,green led is ON,red led is OFF.
                                     // The angle of the door and window is equal to 200 degree,
  { window.write(200);               // The angle of the window is 200.
    delay(100);                      // Wait for a 100 miliseconds.
    door.write(200);                 // The angle of the door is 200.
    delay(100);                      // Wait for a 100 miliseconds.
    digitalWrite(redLed, LOW);       // redLed is OFF.
    digitalWrite(greenLed, HIGH);    // greenLed is ON.
    noTone(buzzer);                  // Buzzer is OFF.
    
    delay(100);                     // Wait for a 100 miliseconds.
   
  }}
  delay(100);                       // Wait for a 100 miliseconds.
} 
