#include "HUKSYLENS.h"
#include "SoftwareSerial.h"
#include <PIDLoop.h>
#include <ZumoMotors.h>

HUKSYLENS huskylens; //create instance of Huskylens
ZumoMotors motors;

// this limits how fast Zumo travels forward (400 is max possible for Zumo)
#define MAX_TRANSLATE_VELOCITY  250

void huskySetup() 
{
	Wire.begin();			//initialize i2c communication
	//error handling
    while (!huskylens.begin(Wire))
    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUKSYLENS (General Settings>>Protocol Type>>I2C)"));
        Serial.println(F("2.Please recheck the connection."));
        delay(100);
    }
}

void zumoSetup()
{
	PIDLoop panLoop(350, 0, 600, true);
	PIDLoop tiltLoop(500, 0, 700, true);
	PIDLoop rotateLoop(300, 600, 300, false);
	PIDLoop translateLoop(400, 800, 300, false);
	motors.setLeftSpeed(0);
	motors.setRightSpeed(0);
}

void setup()
{
	Serial.begin(115200);
	huskySetup();
	zumoSetup();
}



void loop()
{
	
}






