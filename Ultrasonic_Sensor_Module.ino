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
const int trigPin1 = 6; 
const int echoPin1 = 5; 
const int trigPin2 = 8; 
const int echoPin2 = 7;

const int inputPin = 4;
const int outputPin0 = 9;  //Center ultrasonic bit 0
const int outputPin1 = 10;  //Center ultrasonic bit 1
const int outputPin2 = 11;  //Right ultrasonic bit 0
const int outputPin3 = 12;  //Right ultrasonic bit 1

// variables will change: 
int state = 0;        

unsigned long currentMillis = 0;    // stores the value of millis() in each iteration of loop() 
unsigned long previousServoMillis = 0; // the time when the servo was last moved 
int distance1;
int distance2;

void setup() { 
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output 
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input 
pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output 
pinMode(echoPin2, INPUT); // Sets the echoPin as an Input 
pinMode(inputPin, INPUT); 
pinMode(outputPin0, OUTPUT); // Sets the pin as an Output 
pinMode(outputPin1, OUTPUT); // Sets the pin as an Output 
Serial.begin(9600); // Starts the serial communication 
} 

int ultrasonic(int trigPin, int echoPin){
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  //Sets the trigPin on HIGH state for 10 micro seconds  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds 
  long duration = pulseIn(echoPin, HIGH); 
  // Calculating the distance 
  return duration*0.034/2; //calculate the distance in inches
  // Prints the distance on the Serial Monitor 
}

void loop() { 
  state = digitalRead(inputPin);
  while (state == LOW) {
    delay(1);
    state = digitalRead(inputPin); 
  }
  // Clears the trigPin 
  Serial.print("Distance1: "); 
  distance1 = ultrasonic(trigPin1,echoPin1);
  Serial.println(ultrasonic(trigPin1,echoPin1)); 
  Serial.print("Distance2: "); 
  distance2 = ultrasonic(trigPin2,echoPin2);
  Serial.println(ultrasonic(trigPin2,echoPin2));
  if ( distance1 < 2 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, LOW);
  } else if ( distance1 < 6 ) { 
    digitalWrite(outputPin0, HIGH);
    digitalWrite(outputPin1, LOW); 
  } else if ( distance1 < 12 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, HIGH); 
  } else if ( distance1 > 36 ) { 
    digitalWrite(outputPin0, HIGH);
    digitalWrite(outputPin1, HIGH); 
  } 
  if ( distance2 < 2 ) { 
    digitalWrite(outputPin2, LOW);
    digitalWrite(outputPin3, LOW);
  } else if ( distance2 < 6 ) { 
    digitalWrite(outputPin2, HIGH);
    digitalWrite(outputPin3, LOW); 
  } else if ( distance2 < 12 ) { 
    digitalWrite(outputPin2, LOW);
    digitalWrite(outputPin3, HIGH); 
  } else if ( distance2 > 36 ) { 
    digitalWrite(outputPin2, HIGH);
    digitalWrite(outputPin3, HIGH); 
  } 
} 
