/*
  Arduino Micromanipulator
  
  Controls a micromanipulator stage using Arduino using
  a joystick shield.
  
  Hardware:
  See accompanying image
  
  by Gopinath Danda
  credits Tom Igoe for JoystickMouseControl code

  this code is in the public domain
  
*/

const int xMot1 = 2;
const int xMot2 = 3;

const int yMot1 = 4;
const int yMot2 = 5;

int range = 12;
int reponseDelay = 5;
int threshold = range/4;
int center = range/2;

//boolean IsActive = false;
//int lastSwitchState = LOW;

void setup(){
  pinMode(xMot1, OUTPUT);
  pinMode(xMot2, OUTPUT);
  pinMode(yMot1, OUTPUT);
  pinMode(yMot2, OUTPUT);
}

void loop(){
  int xReading = readAxis(A0);
  int yReading = readAxis(A1);
  
  moveMotor(xReading, xMot1, xMot2);
  moveMotor(yReading, yMot1, yMot2);
  
}

int readAxis(int thisAxis){
  int reading = analogRead(thisAxis);
  reading = map(reading, 0, 1023, 0, range);
  int distance = reading - center;
  if(abs(distance) < threshold){
    distance = 0;
  }
  return distance;
}

void moveMotor(int reading, int mot1, int mot2){
  if(reading>threshold){
    digitalWrite(mot1, true);
    digitalWrite(mot2, false);
  }else if(reading<-threshold){
    digitalWrite(mot1, false);
    digitalWrite(mot2, true);
  }else{
    digitalWrite(mot1, false);
    digitalWrite(mot2, false);
  }
}
