char phone[]={"01090011559"};
char msg[]={"i need your help !!"};

void playsound1m()
{
Serial.println("at+csdvc=2");
delay(400);
Serial.println("at+fscd=D:");
delay(400);
Serial.println("at+fscd=Audio");
delay(400);
Serial.println("at+ccmxplay=\"1.mp3\"");
delay(400);
}
void playsound2m()
{
Serial.println("at+csdvc=2");
delay(400);
Serial.println("at+fscd=D:");
delay(400);
Serial.println("at+fscd=Audio");
delay(400);
Serial.println("at+ccmxplay=\"2.mp3\"");
delay(400);
}
void playsound3m()
{
Serial.println("at+csdvc=2");
delay(400);
Serial.println("at+fscd=D:");
delay(400);
Serial.println("at+fscd=Audio");
delay(400);
Serial.println("at+ccmxplay=\"3.mp3\"");
delay(400);
}
void playsoundt()
{
Serial.println("at+csdvc=2");
delay(400);
Serial.println("at+fscd=D:");
delay(400);
Serial.println("at+fscd=Audio");
delay(400);
Serial.println("at+ccmxplay=\"tifa.mp3\"");
delay(400);
}

void send_msg()
{
Serial.println("at+cmgf=1");
delay(200);  
Serial.print("at+cmgs=\"");
delay(200);
Serial.print(phone);
delay(200);
Serial.println("\"");
Serial.print(msg);
delay(200);
Serial.write(0x1A);
Serial.write(0x1A);
Serial.write(0x1A);

}


void setup()
{
 Serial.begin(115200);
 pinMode(4,INPUT);
delay(4000); 
 playsound1m();
 delay(4000);
 send_msg();
 
}

void loop()
{
  boolean x;
  x=digitalRead(4);
  if(x==1)
  {
   
  }
  
  
}
