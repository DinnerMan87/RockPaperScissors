#include <Servo.h>
//Computer Arduino Code
//11-29-2025 at 6:02 PM couldn't get servo motor to work

const int buttonPinThink = 2; //Thinking Button Mode next to RGB LED
int buttonStateThink;
int lastButtonStateThink = LOW;
unsigned long lastDebounceTimeThink = 0;
unsigned long debounceDelayThink = 50;

const int buttonPinRandom = 3; //Random Button Mode next to buzzer
int buttonStateRandom;
int lastButtonStateRandom = LOW;
unsigned long lastDebounceTimeRandom = 0;
unsigned long debounceDelayRandom = 50;

int ledR = 7; //rock led = yellow
int ledP = 6; //paper led = green
int ledS = 5; //scissors led = blue
int ledStateR = LOW;
int ledStateP = LOW;
int ledStateS = LOW;

const int buzzerPin = 4; //pin for buzzer
long int hz = 1000; //frequency for buzzer

const int potentPin = A0; //analog pin for the potentiometer

const int redPin = 12; //pin for red on the RBG LED
const int greenPin = 11; //pin for green on the RGB LED
const int bluePin = 8; //pin for blue on the RBG LED

Servo servo1; //set up instance of Servo motor
int servoPin = 13; //pin for Servo motor

int gameSelection = 0; //data sent from Referee of whether its two player or player vs computer
                       //0=nothing selected, 1=two players, 2=player vs think
int stage = 0; //data sent from Referee of stage the game is on
int numOfRounds = 0; //data sent from Referee of rounds played so far
int prevMoves[20]; //data sent from Referee of previous moves player made
                   //0=no moves played, 1=rock. 2=paper, 3=scissors
int winner = 0; //data sent from Referee of who the winner is
                //0=no winner, 1=playerOne, 2=playerTwo, 3=computer

int computerMode = 0; //player selection of making computer "think" or play randomly
                      //0=nothing selected, 1=random, 2=thinking
int computerSelection = 0; //data sent to Referee of the choice computer makes
                           //0=no selection, 1=rock, 2=paper, 3=scissors

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPinRandom, INPUT);
  pinMode(buttonPinThink, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledP, OUTPUT);
  pinMode(ledS, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  servo1.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  hz = analogRead(potentPin);
  //tests for hardware
  //tone(buzzerPin, hz);
  //digitalWrite(ledR, HIGH);
  //digitalWrite(ledP, HIGH);
  //digitalWrite(ledS, HIGH);
  //int readingR = digitalRead(buttonPinRandom);
  //Serial.println(readingR);
  //int readingT = digitalRead(buttonPinThink);
  //Serial.println(readingT);
  //analogWrite(redPin, 180);
  //analogWrite(greenPin, 0);
  //analogWrite(bluePin , 0);
  //servo1.write(0);
  //delay(1000);
  //servo1.write(90);
  //delay(1000);
  //servo1.write(180);
  //delay(1000);
  if (stage == 0) {
    if(Serial.available()){
      stage = Serial.read();
      gameSelection = Serial.read();
    }
  } else if (stage == 1 && gameSelection == 2) {
    if(Serial.available()){
      stage = Serial.read(); 
    }
    
  } else if (stage == 2 && gameSelection == 2) {

  } else if (stage == 3 && gameSelection == 2) {

  } else if (stage == 4 && gameSelection == 2) {

  }
}
