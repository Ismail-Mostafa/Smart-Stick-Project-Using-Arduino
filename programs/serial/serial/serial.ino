void setup()
{
pinMode(10,INPUT);
Serial.begin(9600);
  
}

void loop()
{
  if(digitalRead(10)==LOW)
  {
   Serial.print(78); 
   //while(digitalRead(10)==LOW);  
  }
  
  
}
