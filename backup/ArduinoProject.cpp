#include "ArduinoProject.h"
#include <stdio.h>

const int YELLOW_LED = 50;
const int GREEN_LED = 52;
const int RED_LED = 48;
const int TEMP = A1;
const int FREQ = A0;
const int LIGHT = A2;
int BLINK_INTERVAL = 0;
int ACTUAL_TEMP = 0;
int menorValorTemp = 9999;
int valorSensorTemp = 0;

void setup() {
	pinMode(GREEN_LED, OUTPUT);
	pinMode(YELLOW_LED, OUTPUT);
	pinMode(RED_LED, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	Serial.print("Frequencia :");
	BLINK_INTERVAL = analogRead(FREQ);
	Serial.println(BLINK_INTERVAL);
	blink(GREEN_LED);
	blink(YELLOW_LED);
	blink(RED_LED);
	blink(YELLOW_LED);
	menorValorTemp = 9999;
	for (int i = 1; i <= 8; i++) {
		valorSensorTemp = analogRead(TEMP);
		valorSensorTemp *= 0.54;
		if (valorSensorTemp < menorValorTemp) {
			menorValorTemp = valorSensorTemp;
		}
	}

	Serial.print("Temperatura :");
	Serial.println(menorValorTemp);
	Serial.print("LUZ :");
	Serial.println(analogRead(LIGHT));
	Serial.println("");

}

void blink(int pin) {
	digitalWrite(pin, HIGH);
	delay(BLINK_INTERVAL);
	digitalWrite(pin, LOW);
}

