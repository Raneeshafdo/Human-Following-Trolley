#include<Servo.h>
Servo myservo;
int pos = 0;
int count = 0;
char c;
String id;

int en1 = 7;
int en2 = 6;

const int in1 = 13;
const int in2 = 12;
const int in3 = 11;
const int in4 = 10;

const int trigPin = A2; // Trigger Pin of Ultrasonic Sensor
const int echoPin = A3; // Echo Pin of Ultrasonic Sensor

long duration;
int distance;

#define LEFT A0 // The number of the left infrared sensor pin
#define RIGHT A1 //The number of the Right infrared sensor pin

const int ledPin1 =  4;
const int ledPin2 =  3;

void setup() {

myservo.attach(8); 
Serial.begin (9600) ; // Starting Serial Communication
pinMode(2, OUTPUT); //initialising pin 2 as output for the RFID 
Serial.println("Please scan your RFID TAG");

for(pos = 90; pos <= 180; pos += 1){
myservo.write(pos);
delay(15);
}

for(pos = 180; pos >= 0;pos-= 1){
myservo.write(pos) ;
delay (15) ;
}

for(pos = 0; pos >= 90;pos-= 1){
myservo.write(pos) ;
delay (15) ;
}

 pinMode (en1, OUTPUT);
 pinMode (en2, OUTPUT);

 pinMode (in1, OUTPUT) ;
 pinMode (in2, OUTPUT) ;
 pinMode (in3, OUTPUT) ;
 pinMode (in4, OUTPUT) ;

 pinMode (trigPin, OUTPUT) ; // initialising pin A2 as output
 pinMode (echoPin, INPUT) ; // initialising pin A3 as input

 pinMode (RIGHT, INPUT) ; //initialize the infrared sensor sensor pin as an input:
 pinMode (LEFT, INPUT) ;
 
 pinMode (ledPin1, OUTPUT); //initialize the LED pin as an output:
 pinMode (ledPin2, OUTPUT);
 
 }

void loop () {

while(Serial.available()>0)
  {
    c = Serial.read();
   count++;
   id += c;
   if(count == 12)  
    {
      Serial.print(id);
      //break;
     
      if(id=="ABC123456789") 
      {
        Serial.println(" Valid TAG");
        digitalWrite(2, HIGH);
      }
      else
      {
      digitalWrite(2, LOW);
      Serial.println(" Invalid TAG");
      }
    }
  }

 digitalWrite (trigPin, LOW) ;
 delay (2) ;
 digitalWrite (trigPin, HIGH) ;
 delay (10) ;
 digitalWrite (trigPin, LOW) ;

 duration = pulseIn (echoPin,HIGH) ;
 distance = (duration*0.034/2) ;
 Serial.print ("Distance: ");
 Serial.println (distance) ;

 int Right_Value=digitalRead(RIGHT) ;
 int Left_Value=digitalRead(LEFT) ;

// Forward

if((id=="ABC123456789") && (distance == 50) && (Right_Value==1) && (Left_Value==1))
{
 digitalWrite (in1,HIGH) ;
 digitalWrite (in2,LOW) ;
 digitalWrite (in3,HIGH) ;
 digitalWrite (in4,LOW) ;

    analogWrite(en1, 150);
    analogWrite(en2, 150);
}

else if((id=="ABC123456789") && (distance == 50) && (Right_Value==0) && (Left_Value==0))
{
 digitalWrite (in1,HIGH) ;
 digitalWrite (in2,LOW) ;
 digitalWrite (in3,HIGH) ;
 digitalWrite (in4,LOW) ;

    analogWrite(en1, 150);
    analogWrite(en2, 150);
}

else if((id=="ABC123456789") && (distance>30 && distance<50) && (Right_Value==1) && (Left_Value==1)) //Forward slow
{
 digitalWrite (in1,HIGH) ;
 digitalWrite (in2,LOW) ;
 digitalWrite (in3,HIGH) ;
 digitalWrite (in4,LOW) ;

    analogWrite(en1, 100);
    analogWrite(en2, 100);
}

else if((id=="ABC123456789") && (distance>30 && distance<50) &&(Right_Value==0) && (Left_Value==0))
{
 digitalWrite (in1,HIGH) ;
 digitalWrite (in2,LOW) ;
 digitalWrite (in3,HIGH) ;
 digitalWrite (in4,LOW) ;

    analogWrite(en1, 100);
    analogWrite(en2, 100);
}

else if((id=="ABC123456789") && (distance > 50) && (Right_Value==1) && (Left_Value==1)) //Forward fast
{
 digitalWrite (in1,HIGH) ;
 digitalWrite (in2,LOW) ;
 digitalWrite (in3,HIGH) ;
 digitalWrite (in4,LOW) ;

    analogWrite(en1, 200);
    analogWrite(en2, 200);
}

else if((id=="ABC123456789") && (distance > 50) && (Right_Value==0) && (Left_Value==0))
{
 digitalWrite (in1,HIGH) ;
 digitalWrite (in2,LOW) ;
 digitalWrite (in3,HIGH) ;
 digitalWrite (in4,LOW) ;

    analogWrite(en1, 200);
    analogWrite(en2, 200);
}
 
//Back

else if((id=="ABC123456789") && (Right_Value==1) && (Left_Value==1) && (distance<10))
{
 digitalWrite (in1,LOW) ;
 digitalWrite (in2,HIGH) ;
 digitalWrite (in3,LOW) ;
 digitalWrite (in4,HIGH) ;

    analogWrite(en1, 150);
    analogWrite(en2, 150);
}

else if((id=="ABC123456789") && (Right_Value==0) && (Left_Value==0) && (distance<10))
{
 digitalWrite (in1,LOW) ;
 digitalWrite (in2,HIGH) ;
 digitalWrite (in3,LOW) ;
 digitalWrite (in4,HIGH) ;
 
    analogWrite(en1, 150);
    analogWrite(en2, 150);
}

//Stop

else if((id=="ABC123456789") && (Right_Value==1) && (Left_Value==1) && (distance>10 && distance<30))
{
 digitalWrite (in1,LOW) ;
 digitalWrite (in2,LOW) ;
 digitalWrite (in3,LOW) ;
 digitalWrite (in4,LOW) ;

    analogWrite(en1, 0);
    analogWrite(en2, 0);
}

else if((id=="ABC123456789") && (Right_Value==0) && (Left_Value==0) && (distance>10 && distance<30))
{
 digitalWrite (in1,LOW) ;
 digitalWrite (in2,LOW) ;
 digitalWrite (in3,LOW) ;
 digitalWrite (in4,LOW) ;

    analogWrite(en1, 0);
    analogWrite(en2, 0);
}

else if((id=="ABC123456789") && (Right_Value==1) && (Left_Value==0) && (distance>10 && distance<30))
{
 digitalWrite (in1,LOW) ;
 digitalWrite (in2,LOW) ;
 digitalWrite (in3,LOW) ;
 digitalWrite (in4,LOW) ;

    analogWrite(en1, 0);
    analogWrite(en2, 0);
}

else if((id=="ABC123456789") && (Right_Value==0) && (Left_Value==1) && (distance>10 && distance<30))
{
 digitalWrite (in1,LOW) ;
 digitalWrite (in2,LOW) ;
 digitalWrite (in3,LOW) ;
 digitalWrite (in4,LOW) ;

    analogWrite(en1, 0);
    analogWrite(en2, 0);
}

// Right turn

else if((id=="ABC123456789") && (Right_Value==0) && (Left_Value==1))
{
 digitalWrite (in1,HIGH) ;
 digitalWrite (in2,LOW) ;
 digitalWrite (in3,LOW) ;
 digitalWrite (in4,HIGH) ;

    analogWrite(en1, 150);
    analogWrite(en2, 150);
}
 
//Left turn

else if((id=="ABC123456789") && (Right_Value==1) && (Left_Value==0))
{
 digitalWrite (in1,LOW) ;
 digitalWrite (in2,HIGH) ;
 digitalWrite (in3,HIGH) ;
 digitalWrite (in4,LOW) ;

    analogWrite(en1, 150);
    analogWrite(en2, 150);
}
{
 int sensorState1 = digitalRead (LEFT);//Read the state of the Left infrared sensor
 
 if (sensorState1 == HIGH) //If the infrared sensor detects any object or obstacle
 {
  digitalWrite(ledPin1, HIGH); //Turn LED ON
  }
 else //If the infrared sensor does not detect any object or obstacle, then sensorState state is LOW
 {
  digitalWrite(ledPin1, LOW); //Turn LED OFF
  }
 int sensorState2 = digitalRead (RIGHT);//Read the state of the Right infrared sensor

 if (sensorState2 == HIGH)
 {
  digitalWrite(ledPin2, HIGH);
  }

 else
 {
  digitalWrite(ledPin2, LOW);
  } 
}
}
