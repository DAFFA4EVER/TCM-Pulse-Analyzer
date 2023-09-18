/*  PulseSensor Starter Project and Signal Tester
 *  The Best Way to Get Started With, or See the Raw Signal of, your PulseSensor.com™ & Arduino.
 *
 *  Here is a link to the tutorial
 *  https://pulsesensor.com/pages/code-and-guide 
 *
 *  WATCH ME (Tutorial Video):
 *  https://www.youtube.com/watch?v=RbB8NSRa5X4
 *
 *
-------------------------------------------------------------
1) This shows live human Heartbeat Pulse for three sensors.
2) Live visualization in Arduino's Cool "Serial Plotter".
3) Blink an LED on each Heartbeat for each sensor.
4) This is the direct Pulse Sensor's Signal.
5) A great first-step in troubleshooting your circuit and connections.
6) "Human-readable" code that is newbie-friendly."

*/

// Variables
int PulseSensorPurplePin1 = A0;  // Pulse Sensor 1 - PURPLE WIRE connected to ANALOG PIN A0
int PulseSensorPurplePin2 = A1;  // Pulse Sensor 2 - PURPLE WIRE connected to ANALOG PIN A1
int PulseSensorPurplePin3 = A2;  // Pulse Sensor 3 - PURPLE WIRE connected to ANALOG PIN A2

int LED1 = 12;  // LED for Pulse Sensor 1
int LED2 = 13;  // LED for Pulse Sensor 2
int LED3 = 11;  // LED for Pulse Sensor 3

int Signal1;  // Holds the incoming raw data for Sensor 1.
int Signal2;  // Holds the incoming raw data for Sensor 2.
int Signal3;  // Holds the incoming raw data for Sensor 3.

int Threshold = 580;  // Determine which Signal to "count as a beat" and which to ignore.

// The SetUp Function:
void setup() {
  pinMode(LED1, OUTPUT);  // LED for Sensor 1
  pinMode(LED2, OUTPUT);  // LED for Sensor 2
  pinMode(LED3, OUTPUT);  // LED for Sensor 3
  Serial.begin(9600);     // Set up Serial Communication at a certain speed.
}

// The Main Loop Function
void loop() {
  loop1();  // Call the loop1 function
  loop2();  // Call the loop2 function
  loop3();  // Call the loop3 function
}

// Sensor 1 Loop
void loop1() {
  Signal1 = analogRead(PulseSensorPurplePin1);  // Read the value from Pulse Sensor 1.

  Serial.print("Sensor 1: ");
  Serial.print(Signal1);  // Send the Signal value of Sensor 1 to Serial.

  if (Signal1 > Threshold) {
    digitalWrite(LED1, HIGH);  // Turn on LED for Sensor 1.
  } else {
    digitalWrite(LED1, LOW);  // Turn off LED for Sensor 1.
  }
}

// Sensor 2 Loop
void loop2() {
  Signal2 = analogRead(PulseSensorPurplePin2);  // Read the value from Pulse Sensor 2.

  Serial.print("\tSensor 2: ");
  Serial.print(Signal2);  // Send the Signal value of Sensor 2 to Serial.

  if (Signal2 > Threshold) {
    digitalWrite(LED2, HIGH);  // Turn on LED for Sensor 2.
  } else {
    digitalWrite(LED2, LOW);  // Turn off LED for Sensor 2.
  }
}

// Sensor 3 Loop
void loop3() {
  Signal3 = analogRead(PulseSensorPurplePin3);  // Read the value from Pulse Sensor 3.

  Serial.print("\tSensor 3: ");
  Serial.print(Signal3);  // Send the Signal value of Sensor 3 to Serial.

  if (Signal3 > Threshold) {
    digitalWrite(LED3, HIGH);  // Turn on LED for Sensor 3.
  } else {
    digitalWrite(LED3, LOW);  // Turn off LED for Sensor 3.
  }

  Serial.println();  // Print a new line to separate readings in the Serial Plotter.
  delay(50);
}
