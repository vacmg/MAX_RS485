

#include "MAX_RS485.h"

MAX_RS485::MAX_RS485(const uint8_t rxPin, const uint8_t txPin, const uint8_t receiverEnablePin, const uint8_t driveEnablePin) : SoftwareSerial(rxPin, txPin)
{
  this->rePin = receiverEnablePin;
  this->dePin = driveEnablePin;
  this->txDelay = 10;
  this->rxDelay = 1;
}


void MAX_RS485::setModeToReceiver()
{
  flush();
  delay(rxDelay);
  digitalWrite(rePin, LOW);
  digitalWrite(dePin, LOW);
}


void MAX_RS485::setModeToTransmitter()
{
  delay(txDelay);
  digitalWrite(rePin, HIGH);
  digitalWrite(dePin, HIGH);
}


long MAX_RS485::getChangeToTransmitterDelay()
{
  return txDelay;
}


long MAX_RS485::getChangeToReceiverDelay()
{
  return rxDelay;
}


void MAX_RS485::setDelays(long txDelay, long rxDelay)
{
  this->txDelay = txDelay;
  this->rxDelay = rxDelay;
}


void MAX_RS485::begin(const long speed, const unsigned long timeout)
{
  SoftwareSerial::begin(speed);
  SoftwareSerial::setTimeout(timeout);

  pinMode(dePin, OUTPUT);
  pinMode(rePin, OUTPUT);
  setModeToReceiver();
}


size_t MAX_RS485::write(const char *string)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::write(string);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::write(const uint8_t *buffer, size_t size)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::write(buffer, size);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::write(const char *buffer, size_t size)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::write(buffer, size);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::print(const __FlashStringHelper *ifsh)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::print(ifsh);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::print(const String &s)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::print(s);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::print(const char string[])
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::print(string);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::print(char c)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::print(c);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::print(unsigned char b, int base)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::print(b, base);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::print(int n, int base)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::print(n, base);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::print(unsigned int n, int base)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::print(n, base);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::print(long n, int base)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::print(n, base);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::print(unsigned long n, int base)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::print(n, base);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::print(double n, int digits)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::print(n, digits);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::print(const Printable& x)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::print(x);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::println(const __FlashStringHelper *ifsh)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::println(ifsh);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::println(const String &s)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::println(s);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::println(const char string[])
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::println(string);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::println(char c)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::println(c);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::println(unsigned char b, int base)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::println(b, base);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::println(int n, int base)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::println(n, base);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::println(unsigned int n, int base)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::println(n, base);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::println(long n, int base)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::println(n, base);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::println(unsigned long n, int base)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::println(n, base);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::println(double n, int digits)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::println(n, digits);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::println(const Printable& x)
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::println(x);
  setModeToReceiver();
  return res;
}


size_t MAX_RS485::println()
{
  size_t res;
  setModeToTransmitter();
  res = SoftwareSerial::println();
  setModeToReceiver();
  return res;
}
