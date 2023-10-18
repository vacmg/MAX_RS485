/**
 * This example shows how to send & receive a message between 2 modules
 */

#include <MAX_RS485.h>

const int ledPin =  13;  // Built-in LED
const int receiverEnablePin =  5;  // HIGH = Driver / LOW = Receptor
const int driveEnablePin =  4;  // HIGH = Driver / LOW = Receptor
const int rxPin = 6; // Serial data in pin
const int txPin = 3; // Serial data out pin

char HEADER[] = "H_"; // This string is prepended to the message and used to discard leftover bytes from previous messages

MAX_RS485 rs485(rxPin, txPin, receiverEnablePin, driveEnablePin); // module constructor

void setup() 
{
  Serial.begin(9600); 
  Serial.setTimeout(100);

  rs485.begin(9600,100); // first argument is serial baud rate & second one is serial input timeout (to enable the use of the find function)

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  delay(1000);
  Serial.println(F("Press enter (\n) to ask for server's millis()"));
}

void serialEvent()
{
  if(Serial.find('\n')) // After pressing enter in the serial monitor (sent new-line (\n) character)
  {
    Serial.print(F("Sending millis request...\t"));
    
    digitalWrite(ledPin, HIGH); // Light the built-in LED during write operations
    rs485.print(HEADER); //RS485 is automatically set to transmitter mode to print the data and back to receiver mode once it has been sent
    digitalWrite(ledPin, LOW); 


    if(rs485.find(HEADER)) // Use the header to check for valid data
    {
      Serial.println(rs485.parseInt()); 
    }
    else
    {
      Serial.println(F("TIMEOUT"));
    }
  }
  
}
 
void loop() 
{ 
  
}
