/*
  Purpose of this program is to know how to use and understand the funcion of a DC motors with a joystick.
  DC motor connects to input pin 1 and input 2 of the L293D chip.
  L293D is a H-bridge dual motor driver IC.
  The direction of DC motor is being controlled using the X axis of the joystick.
  Joystick connects to analog pin A1 of the ardunio.
  Joystick ground connects to analog pin A2, 5V pin connects to analog pin A3.
*/

#define GROUND_JOY_PIN A3  //joystick ground pin will connect to Arduino analog pin A3
#define VOUT_JOY_PIN A2  //joystick +5 V pin will connect to Arduino analog pin A2

int speedPin = 5; //speed pin connected to enable 1,2 on L293D chip
int dir1 = 4; //DC motor connected to input 1 of L293D chip
int dir2 = 3; //DC motor connected to input 2 of L293D chip
int mSpeed;
int jPin = A1; //X axis reading from joystick will go into analog pin A1
int jVal;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(speedPin, OUTPUT); //pin 5 used as output
  pinMode(dir1, OUTPUT); //pin 4 used as input
  pinMode(dir2, OUTPUT); //pin 3 used as input
  pinMode(jPin, INPUT); //pin A1 used as output

  pinMode(VOUT_JOY_PIN, OUTPUT) ; //pin A3 used as output
  pinMode(GROUND_JOY_PIN, OUTPUT) ; //pin A2 used as output
  digitalWrite(VOUT_JOY_PIN, HIGH) ; //set pin A2 to high (+5V)
  digitalWrite(GROUND_JOY_PIN, LOW) ; //set pin A3 to low (ground)

}

void loop() {
  // put your main code here, to run repeatedly:

  int jVal = analogRead(jPin);  //read joystick input on pin A1

  //Clockwise (CW)
  if (jVal < 512) {
    digitalWrite(dir1, LOW); //set pin 4 to low
    digitalWrite(dir2, HIGH); //set pin 3 to high
    mSpeed = -255. / 512.*jVal + 255.; //speed adjustment
    analogWrite(speedPin, mSpeed);
    Serial.print(jVal); //print the value from A1
    Serial.println(" CW = input from joystick"); //print " CW = input from joystick"

  }

  //Counter clock wise (CCW)
  if (jVal >= 512) {
    digitalWrite(dir1, HIGH); //set pin 4 to high
    digitalWrite(dir2, LOW);//set pin 3 to low
    mSpeed = (255. / 512.) * jVal - 255.; //speed adjustment
    analogWrite(speedPin, mSpeed);
    Serial.print(jVal); //print the value from A1
    Serial.println(" CCW = input from joystick"); //print " CCW = input from joystick"

  }

}
