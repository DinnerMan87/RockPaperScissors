//LEDS
const int rockLED = 5, paperLED = 6, scissorsLED = 7;
const int RLED = 9, GLED = 10, BLED = 11;

//Buttons
const int rockButton = 2, paperButton = 3, scissorsButton = 4;

//Other Devices
const int pMeter = A0, buzzer = 8;
//MISC
enum Choice{
  ROCK = 'rock',
  PAPER = 'paper',
  SCISSORS = 'scissors',
  NONE = 'none'
};

Choice choice = Choice::NONE;
bool choiceMade = false;
bool gameStarted = false;
int clientNumber = 1;

void setup() {
  pinMode(rockLED,     OUTPUT);
  pinMode(paperLED,    OUTPUT);
  pinMode(scissorsLED, OUTPUT);
  
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  
  pinMode(rockButton,     INPUT);
  pinMode(paperButton,    INPUT);
  pinMode(scissorsButton, INPUT);
  
  pinMode(pMeter, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}



void loop() {
  
  if (Serial.available() > 0) {
    String read = Serial.readStringUntil('\n');
    if (read == "start"){
    	gameStarted = true;
    }
    if (read == "stop"){
    	gameStarted = false;
      	String send = String(clientNumber.c_str()) + ":" + choice;
      	//Serial.write(send);
    	
    }
  }
  
  if (gameStarted){
      if (digitalRead(rockButton) == 1){
        choice = Choice::ROCK;
        choiceMade = true;
       	digitalWrite(rockLED, HIGH);

        digitalWrite(paperLED, LOW);
      	digitalWrite(scissorsLED, LOW);
      }
      else if (digitalRead(paperButton) == 1){
        choice = Choice::PAPER;
        choiceMade = true;
        digitalWrite(paperLED, HIGH);
        
        digitalWrite(rockLED, LOW);
      	digitalWrite(scissorsLED, LOW);
      }
      else if (digitalRead(scissorsButton) == 1){
        choice = Choice::SCISSORS;
        choiceMade = true;
        digitalWrite(scissorsLED, HIGH);
        
        digitalWrite(rockLED, LOW);
      	digitalWrite(paperLED, LOW);
      }
  }

  /*
  digitalWrite(rockLED, HIGH);
  digitalWrite(paperLED, HIGH);
  digitalWrite(scissorsLED, HIGH);

  analogWrite(RLED, 215);
  analogWrite(GLED, 105);
  analogWrite(BLED, 55);

  //tone(buzzer, 1000);

  Serial.print("\n\n\n\n\n\npMeter:");
  Serial.println(analogRead(pMeter));

  Serial.print("rockButton:");
  Serial.println(digitalRead(rockButton));

  Serial.print("paperButton:");
  Serial.println(digitalRead(paperButton));

  Serial.print("scissorsButton:");
  Serial.println(digitalRead(scissorsButton));

  delay(1000);
  */
}
