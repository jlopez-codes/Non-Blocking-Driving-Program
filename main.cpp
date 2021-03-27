#include <Romi32U4.h>
#include <Timer.h>
#include <Chassis.h>
#include <IRDecoder.h>
#include <RemoteConstants.h>


typedef enum
{
  START,
  DRIVING,
  TURNING,
} States;

States state = START;

Chassis chassis; //Chassis Class calling object chassis
Romi32U4Motors motors; //Romi32U4Motors Class calling object motors
Romi32U4Encoders encoders; //Romi32U4Encoders  Class calling object encoders
Timer blinkingTimer(250); //Timer Class calling object blinkingTimer
IRDecoder decoder(14); //IRDecoder Class calling object decoder

char lightOn = 0; //char = character
const float LED_PIN =13; //cont value doesn't change
bool paused = false;

void checkRemote(){ //method calling function in loop
    int16_t code = decoder.getKeyCode();
    switch (code){
    case remoteVolMinus:
    paused = true;
    break;
    case remoteVolPlus:
    paused = false;
    break;
    }
}

void doDriving() //method calling function in loop
{
  switch (state) //switch between the state
  {
  case START: //start off with state START
    chassis.driveDistance(12); //chassis drives 12 inches
    state = DRIVING; //go to the next state
    break; //breaking out of state
  case DRIVING:
    //doLED();
    motors.setEfforts(100, 100); //set motor to full speed
    if (chassis.doneDriving()) //boolean if(chassis.doneDriving()==True)
    {
      chassis.turnAngle(90); //turn the chassis 90 degrees
      state = TURNING; //should i put a break statement inside the if-statement
      //break; //double check
    }
    break;
  case TURNING:
    motors.setEfforts(100, -100); //negative means counterclockwise, we want right to turn
    if (chassis.doneDriving())
    {
      chassis.driveDistance(12);
      state = DRIVING;
      break; //double check
    }
    break;
  }
}


//LED 
void doLED()
{
  if (blinkingTimer.isExpired()) 
  {
    lightOn = !lightOn; //just turn off the LED when it's expired
    digitalWrite(LED_PIN, lightOn); //sending lightOn a 0 or a 1
  }
}


void setup()
{
  Serial.begin(9600);
    decoder.init();
}

void loop()
{
  checkRemote();
  doDriving();
  doLED();

}
