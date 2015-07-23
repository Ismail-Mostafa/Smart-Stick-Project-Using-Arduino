char phone[]={"01090011559"};
char msg[17]={'i','i',' ','n','e','e','d',' ','y','o','u','r',' ','h','e','l','p'};

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
  int i=0;
Serial.println("at+cmgf=1");
delay(500);  
Serial.print("at+cmgs=\"");
delay(500);
Serial.print(phone);
delay(500);
Serial.println("\"");
for(i=0;i<17;i++)
{
Serial.write(msg[i]);
delay(100);
}
Serial.write(0x1A);
Serial.write(0x1A);
Serial.write(0x1A);

}
void call()
{
Serial.print(  
  
}


void setup()
{
 Serial.begin(115200);
 pinMode(4,INPUT);
 Serial.println("at+csdvc=2");
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
