// Purpose: To echo the state of button inputs on a bar graph.
// Reference:
http://darcy.rsgc.on.ca/ACES/TEI3M/1920/Tasks.html#BinaryButtonEcho
// Author: A. Goldman
// Date: Oct. 19, 2019
// Status: Working

uint8_t gnd = A0; // Assigns A0 as the ground pin, SR 8
uint8_t clockPin = A1; // Assigns A1 as the clock pin, SR 11
uint8_t powerPin = A2; // Assigns A2 as the power pin, SR 16
uint8_t dataPin = A3; // Assigns A3 as the data pin, SR 14
uint8_t latchPin = A4; // Assigns A4 as the latch pin, SR 12
uint8_t outputEnable = A5; // Assigns A5 as the output enable pin, SR 13
uint8_t binary1 = 2; // Assigns button 1, binary 1, to pin 2
uint8_t binary2 = 3; // Assigns button 2, binary 2, to pin 3
uint8_t binary4 = 4; // Assigns button 3, binary 4, to pin 4
uint8_t binary8 = 5; // Assigns button 4, binary 8, to pin 5
uint8_t binary16 = 6; // Assigns button 5, binary 16, to pin 6
uint8_t binary32 = 7; // Assigns button 6, binary 32, to pin 7
uint8_t binary64 = 8; // Assigns button 7, binary 64, to pin 8
uint8_t binary128 = 9; // Assigns button 8, binary 128, to pin 9
uint8_t binarySum; // Creates variable to hold input values

void setup() {
Serial.begin(9600); // Activates the serial monitor
pinMode(gnd, OUTPUT); // Assigns gnd as an output pin
pinMode(clockPin, OUTPUT); // Assigns clockPin as an output pin
pinMode(powerPin, OUTPUT); // Assigns powerPin as an output pin
pinMode(dataPin, OUTPUT); // Assigns dataPin as an output pin
pinMode(latchPin, OUTPUT); // Assigns latchPin as an output pin
pinMode(outputEnable, OUTPUT); // Assigns outputEnable as an output pin
pinMode(binary1, INPUT); // Assigns binary1 as an input pin
pinMode(binary2, INPUT); // Assigns binary2 as an input pin
pinMode(binary4, INPUT); // Assigns binary4 as an input pin
pinMode(binary8, INPUT); // Assigns binary8 as an input pin
pinMode(binary16, INPUT); // Assigns binary16 as an input pin
pinMode(binary32, INPUT); // Assigns binary32 as an input pin
pinMode(binary64, INPUT); // Assigns binary64 as an input pin
pinMode(binary128, INPUT); // Assigns binary128 as an input pin
digitalWrite(gnd, LOW); // Sets gnd low
digitalWrite(powerPin, HIGH); // Sets powerPin high
digitalWrite(outputEnable, LOW); // Sets outputEnable low
}

void loop() {
if (digitalRead(binary1) == HIGH) { // If binary1 is pressed,
binarySum = binarySum + 1; // add 1 to the sum
}
if (digitalRead(binary2) == HIGH) { // If binary2 is pressed,
binarySum = binarySum + 2; // add 2 to the sum
}
if (digitalRead(binary4) == HIGH) { // If binary4 is pressed,
binarySum = binarySum + 4; // add 4 to the sum
}
if (digitalRead(binary8) == HIGH) { // If binary8 is pressed,
binarySum = binarySum + 8; // add 8 to the sum
}
if (digitalRead(binary16) == HIGH) { // If binary16 is pressed,
binarySum = binarySum + 16; // add 16 to the sum
}
if (digitalRead(binary32) == HIGH) { // If binary32 is pressed,
binarySum = binarySum + 32; // add 32 to the sum
}
if (digitalRead(binary64) == HIGH) { // If binary64 is pressed,
binarySum = binarySum + 64; // add 64 to the sum
}
if (digitalRead(binary128) == HIGH) { // If binary128 is pressed,
binarySum = binarySum + 128; // add 128 to the sum
}
digitalWrite(latchPin, LOW); // Latch pin low; begin to receive data
shiftOut(dataPin, clockPin, MSBFIRST, binarySum); // Shifts data bite in
digitalWrite(latchPin, HIGH); // Latch pin high; present data on outputs
Serial.println(binarySum); // Prints current sum on serial monitor
binarySum = 0; // Sets sum back to 0
}
