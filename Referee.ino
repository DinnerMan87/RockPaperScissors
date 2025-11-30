// C++ code
//

enum GameState{  
  IDLE,
  PREPARE, //Select between rock paper or scissors
  RESULT
};


const int twoPlayer = 6;
bool gameStarted = false;

String playerOne = "?";
String playerTwo = "?";
String computer  = "?";

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
  	Serial.begin(9600);
  
}

int oldMils, newMils = -1;
void loop(){
  	if (digitalRead(twoPlayer) && !gameStarted){
  		Serial.write("start\n");
  		gameStarted = true;
    	oldMils = millis();
  	}
  
  	while(gameStarted){
  		newMils = millis();
      	if (newMils - oldMils > 300){
    		Serial.write("stop\n");
      		gameStarted = false;
	    }
      
      	
  	}
  
}
