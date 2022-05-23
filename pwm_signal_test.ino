#define rcPin1 6   // Pin 8 Connected to CH1 of Transmitter;
#define rcPin2 7  // Pin 9 Connected to CH2
#define rcPin3 8 
#include <DualVNH5019MotorShield.h>

int ch1 = 0;  // Receiver Channel 1 PPM value
int ch2 = 0;  // Receiver Channel 2 PPM value
int ch3 = 0;
//const int deadzone =1450-1480

void setup() {
  pinMode(rcPin1, INPUT);
  pinMode(rcPin2, INPUT);
  pinMode(rcPin3, INPUT);
  Serial.begin(9600);
  
 
}

void loop() {

// Read in the length of the signal in microseconds
  ch1 = pulseIn(rcPin1, HIGH, 20000);  // (Pin, State, Timeout)
  ch2 = pulseIn(rcPin2, HIGH, 20000);
  ch3 = pulseIn(rcPin3, HIGH, 20000);
  
  /*int up = map(ch1,1000,1450,0,255);
  int down = map(ch1,1500,2000,0,-255); */
  

  int updown = map(ch2,1500,1900,0,255);
  int leftright = map(ch1,1000,2000,0,255);
  int weapon = map(ch1,1000,2000,0,255);
  
  Serial.print("Channel #1: ");
  Serial.println(ch2);
  Serial.print("Channel #2: ");
  Serial.println(ch1); 
  Serial.print("Channel #3: ");
  Serial.println(ch3);
  Serial.println("------------");
  
  Serial.print("Map #1: ");
  Serial.println(updown);
  Serial.print("Map #2: ");
  Serial.println(leftright); 
  Serial.print("Map #3: ");
  Serial.println(weapon);
  Serial.println("------------");
  delay(1000);
 
  

  /*if (ch1<1000 && ch1>=1450) {
    digitalWrite (3,HIGH);
    digitalWrite (4,LOW);
    analogWrite(5,up);
  }else{
    digitalWrite (3,LOW);
    digitalWrite (4,HIGH);
    analogWrite(6,down); 
  } */
}
  

