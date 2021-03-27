#include "Chassis.h"

void Chassis::driveDistance(float inches)
{
    int countFinal = inches*CPR/(PI*wheelDiameter); //calculate counts needed to cover distance
    encoders.getCountsAndResetLeft(); //Use left wheel to determine distance, set Encoder to zero
    motors.setEfforts(100,100);
    while(encoders.getCountsLeft()< countFinal) //check counts on left wheel
    {
        //wait
    }
    motors.setEfforts(0,0);
}

bool Chassis::doneDriving()
{
    targetCount = CPR = wheelDiameter;



    }
     
}

void Chassis::turnAngle(float degrees)
{
    int countFinal = degrees*CPR*wheelTrack/(360.0*wheelDiameter); // calculate counts needed to turn angle
    encoders.getCountsAndResetLeft(); //Use left wheel to determine angle, set Encoder to Zero
    motors.setEfforts(100, -100);
    while (encoders.getCountsLeft() < countFinal) //Check counts on left wheel
    {
        //wait
    }
    motors.setEfforts(0,0);
}

Chassis::Chassis()
{

};

void Chassis::pauseDriving()
//if the Paused button is is pressed, set motors to 0. 
{
    if( chassis.paused == true)
    {
        motors.setEfforts(100,100);
        motors.setEfforts(0,0);
    }
}

void Chassis::resumeDriving()
//if the Resume button is pressed, set motors back to (100,100)
{
    if(chassis.paused == false)
    {
        motors.setEfforts(0,0);
        motors.setEfforts(100,100;)
    }
}



