int trig=12;
int echo=13;
int duration;
double cm=0;
void setup()
{
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);  
}
void loop()
{
  delay(1000);
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(5);
digitalWrite(trig, LOW);
duration=pulseIn(echo,HIGH);
cm=duration/56;
Serial.print("cm=");
Serial.print(cm);
Serial.write(13);

  
  
}
