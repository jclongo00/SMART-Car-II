/* 
* Ultrasonic_Sensor_Module
* 
* Description: The program will take in the ultrasonic sensors as inputs and steer the car into the parking spot front on safely. 
*  // variable for when the program will run (1) or not (0)

long duration; 
int distance;
* Date: 10/19/2021 
* by Jacob Longo 
* 
*/ 

// defines pins numbers 

const int inputPin0 = 2;
const int inputPin1 = 3;
const int inputPin2 = 4;
const int inputPin3 = 5;

const int outputPin0 = 6;  //000 is nothing
const int outputPin1 = 7; 
const int outputPin2 = 8;  

void setup() {
pinMode(inputPin0, INPUT); 
pinMode(inputPin1, INPUT); 
pinMode(inputPin2, INPUT); 
pinMode(inputPin3, INPUT); 

pinMode(outputPin0, OUTPUT); // Sets the pin as an Output 
pinMode(outputPin1, OUTPUT); // Sets the pin as an Output 
pinMode(outputPin2, OUTPUT); // Sets the pin as an Output 
Serial.begin(9600); // Starts the serial communication 
}

void loop() {
  delay(500);
  if ( digitalRead(inputPin0) == LOW || digitalRead(inputPin1) == LOW) { // when front ultrasonic is less than 4"
    Serial.println("00");
  } else if ( digitalRead(inputPin0) == HIGH || digitalRead(inputPin1) == LOW ) { // front ultrasonic is between 4" and 8"
    Serial.println("01");
  } else if ( digitalRead(inputPin0) == LOW || digitalRead(inputPin1) == HIGH ) { // front ultrasonic is between 8" and 12"
    Serial.println("10");
  } else { // when front ultrasonic is more than 12"
    Serial.println("11");
  } 
}
