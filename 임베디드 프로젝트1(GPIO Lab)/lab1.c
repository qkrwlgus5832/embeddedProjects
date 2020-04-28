#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#define LED0 24
#define LED1 4
#define LED2 11
#define LED3 0
#define LED4 21
#define LED5 7
#define LED6 22
#define SEG0 0x1
#define SEG1 0x2
#define SEG2 0x4
#define SEG3 0x8
#define SEG4 0x10
#define SEG5 0x20
#define SEG6 0x40

void blink(int a, int b) {
	if ((a&SEG0) !=0) {
		digitalWrite(LED0, HIGH);
	}


	if ((a&SEG1) != 0) {
		digitalWrite(LED1, HIGH);
	}
	if ((a&SEG2)  != 0) {
		digitalWrite(LED2, HIGH);
	}

	if ((a&SEG3) != 0) {
		digitalWrite(LED3, HIGH);
	}

	if ((a&SEG4)  != 0) {
		digitalWrite(LED4, HIGH);
	}
	if ((a&SEG5) != 0) {
		digitalWrite(LED5, HIGH);
	}

	if ((a&SEG6) != 0) {
		digitalWrite(LED6, HIGH);
	}

	delay(b);

	digitalWrite(LED0, LOW);
	digitalWrite(LED1, LOW);
	digitalWrite(LED2, LOW);
	digitalWrite(LED3, LOW);
	digitalWrite(LED4, LOW);
	digitalWrite(LED5, LOW);
	digitalWrite(LED6, LOW);
	delay(b);

}


void blink2(int a) {

	if ((a&SEG0) !=0) {
		digitalWrite(LED0, HIGH);
	}


	if ((a&SEG1) != 0) {
		digitalWrite(LED1, HIGH);
	}
	if ((a&SEG2)  != 0) {
		digitalWrite(LED2, HIGH);
	}

	if ((a&SEG3) != 0) {
		digitalWrite(LED3, HIGH);
	}

	if ((a&SEG4)  !=0) {
		digitalWrite(LED4, HIGH);
	}
	if ((a&SEG5) != 0) {
		digitalWrite(LED5, HIGH);
	}

	if ((a&SEG6) !=0) {
		digitalWrite(LED6, HIGH);
	}
}


int main(int argc, char *argv[]) {
	wiringPiSetup();
	int x;
	pinMode(LED0, OUTPUT);
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);

	pinMode(LED3, OUTPUT);
	pinMode(LED4, OUTPUT);
	pinMode(LED5, OUTPUT);
	pinMode(LED6, OUTPUT);
	digitalWrite(LED0, LOW);
	digitalWrite(LED1, LOW);

	digitalWrite(LED2, LOW);
	digitalWrite(LED3, LOW);

	digitalWrite(LED4, LOW);
	digitalWrite(LED5, LOW);
	digitalWrite(LED6, LOW);
	if (argc == 2 && strcmp(argv[1], "1") == 0) {
		blink(0x3f, 500);


		blink(0x6, 500);


		blink(0x5b, 500);

		blink(0x4f, 500);
		blink(0x66, 500);
		blink(0x6d, 500);
		blink(0x7d, 500);
		blink(0x27, 500);
		blink(0x7f, 500);
		blink(0x67, 500);
		blink(0x77, 500);
		blink(0x7c, 500);
		blink(0x39, 500);
		blink(0x5e, 500);

		blink(0x7b, 500);
		blink(0x71, 500);
	}
	else if (argc == 3 && strcmp(argv[1], "2") ==0 ) {
		sscanf(argv[2], "%x", &x);
		blink2(x);
	}
}

