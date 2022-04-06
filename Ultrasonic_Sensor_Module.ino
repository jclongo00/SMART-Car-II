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
const int trigPin3 = 2; 
const int echoPin3 = 3;

const int inputPin0 = 4; // 00 is no sesnors, 01 is front sensor, 10 is right sensor, 11 is left sensor
const int inputPin1 = 13;

const int outputPin0 = 9;  // 000 is less than 4", 001 is 4 < x < 8, 010 is 8 < x < 12, 011 is 12 < x < 16
const int outputPin1 = 10;  // 100 is 16 < x < 20, 110 is 20 < x < 36, 111 is greater than 36
const int outputPin2 = 11;  // 101 is the set number

// variables will change: 
int state = 0;        

unsigned long currentMillis = 0;    // stores the value of millis() in each iteration of loop() 
unsigned long previousServoMillis = 0; // the time when the servo was last moved 
int distance;

void setup() { 
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output 
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input 
pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output 
pinMode(echoPin2, INPUT); // Sets the echoPin as an Input 
pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output 
pinMode(echoPin3, INPUT); // Sets the echoPin as an Input 
pinMode(inputPin0, INPUT); 
pinMode(inputPin1, INPUT); 
pinMode(outputPin0, OUTPUT); // Sets the pin as an Output 
pinMode(outputPin1, OUTPUT); // Sets the pin as an Output 
pinMode(outputPin2, OUTPUT); // Sets the pin as an Output 
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
  return duration/29/2; //calculate the distance in inches
  // Prints the distance on the Serial Monitor 
}

void loop() { 
  digitalWrite(output0, HIGH);
  digitalWrite(output1, LOW);
  digitalWrite(output2, HIGH);
  state0 = digitalRead(inputPin0);
  state1 = digitalRead(inputPin1);
  
  if (state0 == LOW && state1 == LOW) { //No Sensors Activated
    
  } else if (state0 == HIGH && state1 == LOW) { // Front sensor only
    distance = ultrasonic(trigPin1,echoPin1);
    if ( distance < 4 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, LOW);
    digitalWrite(outputPin2, LOW);
  } else if ( distance < 8 ) { 
    digitalWrite(outputPin0, HIGH);
    digitalWrite(outputPin1, LOW); 
    digitalWrite(outputPin2, LOW);
  } else if ( distance < 12 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, HIGH); 
    digitalWrite(outputPin2, LOW);
  } else if ( distance < 16 ) { 
    digitalWrite(outputPin0, HIGH);
    digitalWrite(outputPin1, HIGH); 
    digitalWrite(outputPin2, LOW);
  } else if ( distance < 20 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, LOW); 
    digitalWrite(outputPin2, HIGH);
  } else if ( distance < 36 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, HIGH); 
    digitalWrite(outputPin2, HIGH);
  } else { 
    digitalWrite(outputPin0, HIGH);
    digitalWrite(outputPin1, HIGH); 
    digitalWrite(outputPin2, HIGH);
  }
  delay(1)
  } else if (state0 == LOW && state1 == HIGH) { // Right sensor only
    distance = ultrasonic(trigPin2,echoPin2);
    if ( distance < 4 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, LOW);
    digitalWrite(outputPin2, LOW);
  } else if ( distance < 8 ) { 
    digitalWrite(outputPin0, HIGH);
    digitalWrite(outputPin1, LOW); 
    digitalWrite(outputPin2, LOW);
  } else if ( distance < 12 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, HIGH); 
    digitalWrite(outputPin2, LOW);
  } else if ( distance < 16 ) { 
    digitalWrite(outputPin0, HIGH);
    digitalWrite(outputPin1, HIGH); 
    digitalWrite(outputPin2, LOW);
  } else if ( distance < 20 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, LOW); 
    digitalWrite(outputPin2, HIGH);
  } else if ( distance < 36 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, HIGH); 
    digitalWrite(outputPin2, HIGH);
  } else { 
    digitalWrite(outputPin0, HIGH);
    digitalWrite(outputPin1, HIGH); 
    digitalWrite(outputPin2, HIGH);
  }
  delay(1)
  } else if (state0 == HIGH && state1 == HIGH) { // Left sensor only
    distance = ultrasonic(trigPin3,echoPin3);
    if ( distance < 4 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, LOW);
    digitalWrite(outputPin2, LOW);
  } else if ( distance < 8 ) { 
    digitalWrite(outputPin0, HIGH);
    digitalWrite(outputPin1, LOW); 
    digitalWrite(outputPin2, LOW);
  } else if ( distance < 12 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, HIGH); 
    digitalWrite(outputPin2, LOW);
  } else if ( distance < 16 ) { 
    digitalWrite(outputPin0, HIGH);
    digitalWrite(outputPin1, HIGH); 
    digitalWrite(outputPin2, LOW);
  } else if ( distance < 20 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, LOW); 
    digitalWrite(outputPin2, HIGH);
  } else if ( distance < 36 ) { 
    digitalWrite(outputPin0, LOW);
    digitalWrite(outputPin1, HIGH); 
    digitalWrite(outputPin2, HIGH);
  } else { 
    digitalWrite(outputPin0, HIGH);
    digitalWrite(outputPin1, HIGH); 
    digitalWrite(outputPin2, HIGH);
  }
  delay(1)
  }
} 
