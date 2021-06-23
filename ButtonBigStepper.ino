int Button=0;
int buttonPin=2;
int buttonNew;
int buttonOld=1;
int dt=100;
int LEDPin = 13;

const float StepsPerRev = 200;
int StepsRequired;

#include <Stepper.h>
Stepper stepper_NEMA17(StepsPerRev, 8, 9, 10, 11);

void setup() {
Serial.begin(9600); 
Serial.println(Button);
pinMode (buttonPin, INPUT);
pinMode (LEDPin, OUTPUT);
} 

void loop() {
buttonNew=digitalRead(buttonPin);
if (buttonOld==0 && buttonNew==1){
  if (Button==0){
    digitalWrite(LEDPin, HIGH);
    StepsRequired  =  StepsPerRev / 2; 
    stepper_NEMA17.setSpeed(10);   
    stepper_NEMA17.step(StepsRequired);
    digitalWrite(LEDPin, LOW);
    Button=1;
    Serial.print("Button = " + Button);
  }
  else{
    Button=0;
    digitalWrite(LEDPin, HIGH);
    StepsRequired  =  StepsPerRev / 2; 
    stepper_NEMA17.setSpeed(10);   
    stepper_NEMA17.step(StepsRequired);
    digitalWrite(LEDPin, LOW);
    Serial.print("Button = " + Button);
  }
}
buttonOld=buttonNew;
Serial.println(buttonOld);
delay(dt);
}
