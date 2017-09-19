// make sure to include the servo library
#include <Servo.h>


// initialize ADC read-in variable
int value;
// initialize servo object
Servo myservo;


void setup()
{
  // put your setup code here, to run once:
  
  // configure the servo motor to pin 1.0
  myservo.attach(P1_0);
  // configure the potentiometer ADC input to pin 1.1
  pinMode(P1_1, INPUT);
}


void loop()
{
  // put your main code here, to run repeatedly:
  
  // read in the potentiometer voltage
  value = analogRead(P1_1);
  // map the ADC return to the servo degrees (0 to 179)
  value = map(value, 0, 1023, 0, 179);
  // set the servo to the new position
  myservo.write(value);

  delay(10);
}