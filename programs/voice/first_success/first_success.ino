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
  if (bridge.check())
  {
    cli();
    bridge.loop(0, 1, 12, 13);
  }
  // run normally
  //Serial.begin(9600);
  //Serial.print("hello");
  port.begin(9600);
//*******************************
  if (!easyvr.detect())
  {
    //Serial.println("EasyVR not detected!");
    for (;;);
  }
//*********************************

  easyvr.setPinOutput(EasyVR::IO1, LOW);
  //Serial.println("EasyVR detected!");
  easyvr.setTimeout(5);
  easyvr.setLanguage(EasyVR::ENGLISH);
  group = 1;
  useCommands = 1;
}

const char* ws0[] =
{
  "ROBOT",
};
const char* ws1[] =
{
  "ACTION",
  "MOVE",
  "TURN",
  "RUN",
  "LOOK",
  "ATTACK",
  "STOP",
  "HELLO",
};
const char* ws2[] =
{
  "LEFT",
  "RIGHT",
  "UP",
  "DOWN",
  "FORWARD",
  "BACKWARD",
};
const char* ws3[] =
{
  "ZERO",
  "ONE",
  "TWO",
  "THREE",
  "FOUR",
  "FIVE",
  "SIX",
  "SEVEN",
  "EIGHT",
  "NINE",
  "TEN",
};
const char** ws[] = { ws0, ws1, ws2, ws3 };

//bool checkMonitorInput()
//{
//  if (Serial.available() <= 0)
//    return false;
//  
//  // check console commands
//  int16_t rx = Serial.read();
//  if (rx == 'b')
//  {
//    useCommands = false;
//    set++;
//    if (set > 3)
//      set = 0;
//  }
//  if (rx == 'c')
//  {
//    useCommands = true;
//    do
//    {
//      group=1;
//      if (group > EasyVR::PASSWORD)
//        group = 1;
//    } while (!((mask >> group) & 1));
//  }
//  if (rx == 's')
//  {
//    int16_t num = 0;
//    delay(5);
//    while ((rx = Serial.read()) >= 0)
//    {
//      if (isdigit(rx))
//        num = num * 10 + (rx - '0');
//      else
//        break;
//      delay(5);
//    }
//    if (rx == '.')
//    {
//      easyvr.stop();
//      easyvr.playSound(num, EasyVR::VOL_DOUBLE);
//    }
//  }
//  if (rx >= 0)
//  {
//    easyvr.stop();
//    Serial.flush();
//    return true;
//  }
//  return false;
//}

void loop()
{
  //checkMonitorInput();
  easyvr.setPinOutput(EasyVR::IO1, HIGH); // LED on (listening)
  if (useCommands)
  {
    group=1;
    //Serial.print("Say a command in Group ");
    //Serial.println(group);
    easyvr.recognizeCommand(group);
  }


  do
  {
//    if (checkMonitorInput())
//      return;
  }
  while (!easyvr.hasFinished());
  
  easyvr.setPinOutput(EasyVR::IO1, LOW); // LED off

    idx = easyvr.getCommand();
    if (idx >= 0)
    {
      //Serial.print("Command: ");
      //Serial.print(easyvr.getCommand());
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
 
      if (easyvr.dumpCommand(group, idx, name, train))
      {
       // Serial.print(" = ");
       // Serial.println(name);
      }}

    else // errors or timeout
    {
      if (easyvr.isTimeout())
       // Serial.println("Timed out, try again...");
      int16_t err = easyvr.getError();
   
    }
  }


