int sensorPin1 = 5; // select the input pin for LDR
int sensorPin2 = 2; // select the input pin for LDR
int sensorPin3 = 3; // select the input pin for LDR

int ledPin1 = 4; // select the input pin for LDR
int ledPin2 = 6; // select the input pin for LDR
int ledPin3 = 7; // select the input pin for LDR

int sensorValue = 0; // variable to store the value coming from the sensor
int sensorPin = A0; // select the input pin for LDR

void setup() {
  Serial.begin(9600); //sets serial port for communication
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(sensorPin3, INPUT);
}
void loop() {
  sensorValue = analogRead(sensorPin); // read the value from the sensor
  Serial.println(sensorValue); //prints the values coming from the sensor on the screen

  delay(100);
  if (sensorValue < 90) {
    checkObject(sensorPin1,ledPin1);
    checkObject(sensorPin2,ledPin2);
    checkObject(sensorPin3,ledPin3);
  }
  else {
    digitalWrite(ledPin1, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin2, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin3, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  delay(500);
}

void checkObject(int sensorPin,int ledPin) {
  int objectDetected = digitalRead(sensorPin);
  Serial.print(sensorPin);
  Serial.print("-");
  Serial.println(objectDetected);
  if (objectDetected == 0) {
    digitalWrite(ledPin,HIGH);
  }
  else {
    digitalWrite(ledPin,LOW);
  }
}
