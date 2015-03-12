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
	Serial.print("\nFrequencia :");
	BLINK_INTERVAL = analogRead(FREQ);
	Serial.print(BLINK_INTERVAL);
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

/*

testar isso aqui

Serial.println('/n'); // print as an ASCII-encoded decimal
Serial.println('/n', DEC); // print as an ASCII-encoded decimal
Serial.println('/n', HEX); // print as an ASCII-encoded hexadecimal
Serial.println('/n', OCT); // print as an ASCII-encoded octal
Serial.println('/n', BIN); // print as an ASCII-encoded binary

*/
	Serial.print("\nTemperatura :");
	Serial.print(menorValorTemp);
	Serial.print("\nLUZ :");
	Serial.print(analogRead(LIGHT));
	Serial.print("\n\n---------------------------------------");

}

void blink(int pin) {
	digitalWrite(pin, HIGH);
	delay(BLINK_INTERVAL);
	digitalWrite(pin, LOW);
}

