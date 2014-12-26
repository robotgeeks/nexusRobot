#include <pb_encode.h>
#include <pb_decode.h>
#include <nexusMsg.pb.h>

#define MSG_LENGTH 256

enum State
{
  NONE,
  MSG_RCV,
  MSG_SND
};

State state = NONE;

uint8_t msgBuffer[MSG_LENGTH] = {0};
char inpBuffer[MSG_LENGTH] = {0};

void setup() 
{
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  Serial.println("Communication driver started.");
}

void loop() 
{
  switch(state)
  {
    case MSG_RCV:
    {
      Serial.println(inpBuffer); 
      state = NONE;
      break;
    }
    case MSG_SND:
    {
      Serial.println(inpBuffer); 
      state = NONE;
      break;
    }
    default :
    {
      Serial.println("Unknown state");
    }
  }
}

void serialEvent() 
{
  char* cursor = inpBuffer;
  while(Serial.available()) 
  {
    // get the new byte:
    *cursor = (char)Serial.read(); 
    ++cursor; 
  }
  *cursor = '\0';
  state = MSG_RCV;
}

bool encode(NexusMsg& sndMsg, uint8_t* sndBuff)
{
  pb_ostream_t stream = pb_ostream_from_buffer(sndBuff, MSG_LENGTH);
  bool status = pb_encode(&stream, NexusMsg_fields, &sndMsg);
  
  if (!status)
  {
    return false;
  }
  return true;
}

bool decode(uint8_t* rcvBuff, NexusMsg& rcvMsg)
{
   pb_istream_t stream = pb_istream_from_buffer(rcvBuff, MSG_LENGTH);
   bool status = pb_decode(&stream, NexusMsg_fields, &rcvMsg);
        
   if (!status)
   {
     return false;
   }
 
   return true;  
}

