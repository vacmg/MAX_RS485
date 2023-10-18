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
  Serial.println(F("Ready to send millis()"));
} 
 
void loop() 
{ 
  if(rs485.available()) // Check for incoming data
  {
    Serial.println(F("A messge has arrived"));
    if(rs485.find(HEADER)) // Use the header to check for valid data
    {
      Serial.print(F("Answering with:\tmillis() = "));
      long data = millis();
      Serial.println(data);

      rs485.print(HEADER); // Answer with the header //RS485 is automatically set to transmitter mode to print the data and back to receiver mode once it has been sent
      rs485.print(data); // And the message itself
    }
  }
  delay(10); // There is no need to go full speed
}
