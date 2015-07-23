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
void setup()
{
  port.begin(9600);
//*******************************
  if (!easyvr.detect())
  {
    for (;;);
  }
//*********************************

  easyvr.setPinOutput(EasyVR::IO1, LOW);
  easyvr.setTimeout(5);
  easyvr.setLanguage(EasyVR::ENGLISH);
  group = 1;
  useCommands = 1;
}




void loop()
{
  easyvr.setPinOutput(EasyVR::IO1, HIGH); // LED on (listening)
  if (useCommands)
  {
    group=1;
    easyvr.recognizeCommand(group);
  }


  do
  {
  }
  while (!easyvr.hasFinished());
  
  easyvr.setPinOutput(EasyVR::IO1, LOW); // LED off

    idx = easyvr.getCommand();
    if (idx >= 0)
    {
      //////////////////////////////////////
      /////////////////////////////////////
      ////////////////////////////////////////
      //////////////////////////////////////
      /////////////////////////////////////
      ///////////////////////////////////////
      if(easyvr.getCommand()== 0)
      {
        digitalWrite(8,HIGH);
      }
       if(easyvr.getCommand()== 3)
      {
        digitalWrite(8,LOW);
      }
  }
} 


