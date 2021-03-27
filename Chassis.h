#pragma once

#include <Romi32U4.h>

class Chassis //define class 
{
public: //add public methods and data
    void driveDistance(float inches); 
    bool doneDriving(); //did the robot finish its task?
    void turnAngle(float angle);
    void pauseDriving();
    void resumeDriving();
//    void checkRemote();
    Chassis();


private:
    Romi32U4Motors motors;
    Romi32U4Encoders encoders;
    int leftEffort, rightEffort;
    const unsigned CPR = 1440;
    const float wheelDiameter = 2.8;
    const float wheelTrack = 5.75;
    long targetCount;



};
