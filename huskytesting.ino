#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

HUSKYLENS huskylens
//HUSKYLENS green line >> SDA; blue line >> SCL

void setup() {
	Serial.begin(115200);
	Wire.begin();
	while (!huskylens.begin(Wire))
	{
		Serial.println(F("Begin failed!"));
		Serial.println(F("1. Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>I2C"));
		Serial.println(F("2. Please recheck the connection"));
		delay(100);
	}
}

void loop() {
	if(!huskylens.request()) Serial.println(F("Fail to request objects from HUSKYLENS!"));
	else if(!huskylens.isLearned()) Serial.println(F("Object not learned!"));
	else if(!huskylens.available()) Serial.println(F("Object disappeard!));
	else
	{
		HUSKYLENSResult result = huskylens.read();
		if (result.command == COMMAND_RETURN_BLOCK)
		{
			Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter









