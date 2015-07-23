char phone[]={"01090011559"};
char msg[17]={'i','i',' ','n','e','e','d',' ','y','o','u','r',' ','h','e','l','p'};
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
  char count=0;
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
  #include "SoftwareSerial.h"
  SoftwareSerial port(12,13);
#else // Arduino 0022 - use modified NewSoftSerial
  #include "WProgram.h"
  #include "NewSoftSerial.h"
  NewSoftSerial port(12,13);
#endif

#include "EasyVR.h"

EasyVR easyvr(port);

int8_t set = 0;
int8_t group = 1;
uint32_t mask = 0;  
uint8_t train = 0;
int control=0;
char name[32];
bool useCommands = true;
int idx;
EasyVRBridge bridge;
int trig=3;
int echo=4;
///////////////////////////////////////////////////
///////////////////////////////////////////////////
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



void setup()
{
 Serial.begin(115200);
 pinMode(4,INPUT);
 Serial.println("at+csdvc=2");
delay(4000); 
 playsound1m();
 delay(4000);
 send_msg();
 /////////////////////////////////////
 /////////////////////////////////////
   port.begin(9600);
   pinMode(8,OUTPUT);
  pinMode(7,INPUT);
////*******************************
//  if (!easyvr.detect())
//  {
//    for (;;);
//  }
////*********************************

  easyvr.setPinOutput(EasyVR::IO1, LOW);
  easyvr.setTimeout(5);
  easyvr.setLanguage(EasyVR::ENGLISH);
  group = 1;
  useCommands = 1;
 
}

void loop()
{
  char rec=0;
  boolean x;
  if(Serial.available()>=1)
  {

  rec=Serial.read();
  if(rec=='G')
  {
  Serial.println("ATA");
  delay(2000);
  //Serial.write('R');
  }
//  {count=1;Serial.write('R');}
//  if(rec=='I')
//  {if(count==1){digitalWrite(8,HIGH);count=2;Serial.write('I');}}
//  if(rec=='N')
//  {if(count==2){count=3;Serial.write('N');}}
//  if(rec=='G')
//  {if(count==3){count=4;Serial.write('G');}}
//  if(count>=3)
//  {playsound1m();
//  count=0;
//  }
  //Serial.println("ATA") 
  }
//  x=digitalRead(7);
//  
//  if(x==HIGH)
//  {
//  easyvr.setPinOutput(EasyVR::IO1, HIGH); // LED on (listening)
//  if (useCommands)
//  {
//    group=1;
//    easyvr.recognizeCommand(group);
//  }
//
//
//  do
//  {
//  }
//  while (!easyvr.hasFinished());
//  
//  easyvr.setPinOutput(EasyVR::IO1, LOW); // LED off
//
//    idx = easyvr.getCommand();
//    if (idx >= 0)
//    {
//      //////////////////////////////////////
//      /////////////////////////////////////
//      ////////////////////////////////////////
//      //////////////////////////////////////
//      /////////////////////////////////////
//      ///////////////////////////////////////
//      if(easyvr.getCommand()== 2)
//      {
//        digitalWrite(8,HIGH);
//        Serial.println("atd01004460228;");
//      }
//       if(easyvr.getCommand()== 3)
//      {
//        digitalWrite(8,LOW);
//        Serial.println("atd01090011559;");
//      }}}
  
  
}
