// Project 40 - Building and Controlling a Tank Robot
int m1speed=6; // digital pins for speed control
int m2speed=5;
int m1direction=7; // digital pins for direction control
int m2direction=4;

void setup()
{
 pinMode(m1direction, OUTPUT);
 pinMode(m2direction, OUTPUT);
 delay(5000);
}

void goForward(int duration, int pwm)
{
 digitalWrite(m1direction,HIGH); // forward 
 digitalWrite(m2direction,HIGH); // forward
 analogWrite(m1speed, pwm); // speed
 analogWrite(m2speed, pwm);
 delay(duration);
 analogWrite(m1speed, 0); // speed
 analogWrite(m2speed, 0); 
}

void goBackward(int duration, int pwm)
{
 digitalWrite(m1direction,LOW); // backward 
 digitalWrite(m2direction,LOW); // backward 
 analogWrite(m1speed, pwm); // speed
 analogWrite(m2speed, pwm);
 delay(duration);
 analogWrite(m1speed, 0); // speed
 analogWrite(m2speed, 0); 
}

void rotateRight(int duration, int pwm)
{
 digitalWrite(m1direction,HIGH); // forward 
 digitalWrite(m2direction,LOW); // backward
 analogWrite(m1speed, pwm); // speed
 analogWrite(m2speed, pwm);
 delay(duration);
 analogWrite(m1speed, 0); // speed
 analogWrite(m2speed, 0); 
}

void rotateLeft(int duration, int pwm)
{
 digitalWrite(m1direction,LOW); // backward 
 digitalWrite(m2direction,HIGH); // forward
 analogWrite(m1speed, pwm); // speed
 analogWrite(m2speed, pwm);
 delay(duration);
 analogWrite(m1speed, 0); // speed
 analogWrite(m2speed, 0); 
}

void loop()
{
 goForward(5000, 255); 
 rotateLeft(5000, 255);
 goForward(5000, 255); 
 rotateRight(5000, 255);
 goForward(5000, 255); 
 goBackward(5000, 255);
 delay(2000);
}
