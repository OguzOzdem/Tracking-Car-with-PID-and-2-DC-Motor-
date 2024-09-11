
#include <deprecated.h>
#include <require_cpp11.h>

#define trigPin 12
#define echoPin 11

int speed=100;
float derivate,integral=0;
float pow;
double error;
double lasterror = error;
float kp=0.1;
float kd = 0.2;
float ki = 0.1;
double ref = 20;
double distance;
double time; 
double last_time =0;
double dt;

void setup() 
{
Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);

pinMode(2,OUTPUT);
pinMode(10,OUTPUT);
pinMode(3,OUTPUT);

pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);


delay(10000);
  
  
}

void loop() 
{
Serial.print( "Started ");
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
time = pulseIn(echoPin, HIGH);
distance = (time/2) * 0.0343;

if(distance == 0) 
{
  stop();
}
Serial.print("Distance:");
Serial.println(distance);

double now = millis();
dt = (now - last_time)/1000.00;
last_time = now;



error = ref-mesafe;

integral = integral+ (error*dt);

derivate = (error-lasterror)/dt;

lasterror = error;

power = (kp*error)+(kd*derivate)+(integral*ki);



if(error>3) 
{
forward(power);
} 
else if(error<0)
{
back(power);
}
else
{
stop();
}


}

