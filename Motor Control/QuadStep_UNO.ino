/*
  SparkFun Electronics 2011
  Aaron Weiss, aaron at sparkfun dot com
  Beer-ware License: You can do whatever you want with this sketch.
                     If we meet someday, you can buy me a beer.
                     
  QuadSetpper Example Sketch. For use with an Arduino Mega2560 and 
  a 1.8 degree bipolar stepper motor.

  You must connect the STP pin for each motor as shown below.
  For rest of the pins, you choose where they go. 

  Motor1 STP pin: mega pin 11
  Motor2 STP pin: mega pin 5
  Motor3 STP pin: mega pin 6
  Motor4 STP pin: mega pin 46
  
  Library Usage: 
  
  motor_pins(x,y,z,l,m,n)
  x: motor channel number
  y: enable pin assignment
  z: direction pin assignment
  l: MS1 pin assignment
  m: MS2 pin assignment
  n: MS3 pin assignment
  
  motor_go(x,y,z,l)
  x: motor channel number
  y: step size: 1, 2, 4, 8, or 16
  z: increments for given step size
     for full step: 1 increment = 1.8deg
     for half step: 1 increment = 0.9deg and so on
     negative numbers rotate in the opposite direction
  l: torque/speed (0-10), 0 is high speed/low torque/low current
                          10 is low speed/high torque/high current (2.0A max)
                      
  stall(x)
  x: motor channel number
*/

// include the motor library
#include <quadstep.h>
#include <Arduino.h>
#include "quadstep.h"

// create an instance of the class motor
quadstep quadstep;

void setup() {
  // define PORTB and PORTD for UNO (Remainder commented out for using only two motors on UNO)
  DDRB = B11111111;
  DDRD = B11111111;
  // assign the pin connections motor_pins(motornum,en,dir,ms1,ms2,ms3)
  //quadstep.motor_pins(1,A1,36,A8,A9,A10); //ch 1 MEGA pins
  //quadstep.motor_pins(2,10,9,8,7,4);      //ch 2 MEGA pins
  //quadstep.motor_pins(3,22,23,24,25,26);  //ch 3 MEGA pins
  //quadstep.motor_pins(4,27,28,29,30,31);  //ch 4 MEGA pins
  quadstep.motor_pins(1,13,12,10,9,8);      //ch 1 UNO pins
  quadstep.motor_pins(2,7,5,4,3,2);         //ch 3 UNO pins
}

//1.8deg = 1step
void loop() {
  
  // step motor 1 for 200 increments CW
  quadstep.motor_go(2,1,-300,2);
  delay(100);
  // step motor 1 for 200 increments CCW
  quadstep.motor_go(1,1,300,2);
  delay(100);
   // step motor 2 for 200 increments CW
  quadstep.motor_go(1,1,-50,2);
  delay(100);
  // step motor 2 for 200 increments CCW
  quadstep.motor_go(2,1,50,2);
  delay(100);
   // step motor 2 for 200 increments CCW
  quadstep.motor_go(2,1,-200,2);
  delay(100);
   // step motor 2 for 200 increments CCW
  quadstep.motor_go(1,1,200,2);
  delay(100);
   // step motor 2 for 200 increments CCW
  quadstep.motor_go(1,1,-50,2);
  delay(100);
   // step motor 2 for 200 increments CCW
  quadstep.motor_go(2,1,50,2);
  delay(100);
   // reset position
  quadstep.motor_go(2,1,450,2);
  delay(0);
   // step motor 2 for 200 increments CCW
  quadstep.motor_go(1,1,-400,2);
  delay(1000);
  // holds the motor in one position with full torque/current
  //motor.stall(4);
  //delay(500); 
}
