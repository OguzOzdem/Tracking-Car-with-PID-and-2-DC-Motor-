int forward(int power)
{
Serial.print( "Forward: ");
power = abs(power*9);
Serial.println(power);


digitalWrite(2,HIGH);
digitalWrite(10,LOW);
digitalWrite(3,power);

digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,power);
}
  
int back(int power)
{
Serial.print( "back: ");
power = abs(power*9);
Serial.println(power);

digitalWrite(10,HIGH);
digitalWrite(2,LOW);
digitalWrite(3,power);

digitalWrite(5,HIGH);
digitalWrite(4,LOW);
digitalWrite(6,power);

}

int stop()
{
Serial.print("Stop!");
digitalWrite(10,LOW);
digitalWrite(2,LOW);
digitalWrite(3,0);

digitalWrite(5,LOW);
digitalWrite(4,LOW);
digitalWrite(6,0);



}
