// TUNING VARIABLE
// Range: 0 to 10
float scale = 0.9; // Increase for less lights, decrease for more lights

const int analogInPin = A0; // Analog input pin connected to P1_0 (ADC)
const int green_led = P2_0; // Green LED connected to P2_0
const int yellow_led = P2_1; // Yellow LED connected to P2_1
const int red_led = P2_2; // Red LED connected to P2_2

int voltage = 0;  // Read value from the analog input pin


void setup()
{
  // put your setup code here, to run once:
  
  // Declare the 3 LED pins as outputs
  pinMode(green_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  
  // Initialize the LEDs to be off
  digitalWrite(green_led, LOW);
  digitalWrite(yellow_led, LOW);
  digitalWrite(red_led, LOW);
}

void loop()
{
  // put your main code here, to run repeatedly:
  
  // Read the voltage from the ADC input
  voltage = analogRead(analogInPin);
  
  
  if (voltage > scale*100) // Light all 3 LEDs
  {
    digitalWrite(green_led, HIGH);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(red_led, HIGH);
  }
  else if (voltage > scale*66) // Light 2 LEDs (green/yellow)
  {
    digitalWrite(green_led, HIGH);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(red_led, LOW);
  }
  else if (voltage > scale*33) // Light 1 LED (green)
  {
    digitalWrite(green_led, HIGH);
    digitalWrite(yellow_led, LOW);
    digitalWrite(red_led, LOW);
  }
  else // Turn off all 3 LEDs
  {
    digitalWrite(green_led, LOW);
    digitalWrite(yellow_led, LOW);
    digitalWrite(red_led, LOW);
  }
}