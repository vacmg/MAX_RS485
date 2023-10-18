
#ifndef MAX_RS485_H
#define MAX_RS485_H

#ifndef ARDUINO_ARCH_AVR
  #error “This library only supports boards with an AVR or SAM processor.”
#endif

#include <Arduino.h>
#include <SoftwareSerial.h>

class MAX_RS485: public SoftwareSerial
{
  private:
    uint8_t rePin;
    uint8_t dePin;
	
    long txDelay;
    long rxDelay;

    void setModeToReceiver();
    void setModeToTransmitter();

  public:
    MAX_RS485(const uint8_t rxPin, const uint8_t txPin, const uint8_t receiverEnablePin, const uint8_t driveEnablePin);

    void begin(const long speed, const unsigned long timeout);
	
    long getChangeToTransmitterDelay();
    long getChangeToReceiverDelay();
    void setDelays(long txDelay, long rxDelay);

    // Modified write & print functions
    size_t write(const char *string);
    size_t write(const uint8_t *buffer, size_t size);
    size_t write(const char *buffer, size_t size);

    size_t print(const __FlashStringHelper *ifsh);
    size_t print(const String &s);
    size_t print(const char string[]);
    size_t print(char c);
    size_t print(unsigned char b, int base = DEC);
    size_t print(int n, int base = DEC);
    size_t print(unsigned int n, int base = DEC);
    size_t print(long n, int base = DEC);
    size_t print(unsigned long n, int base = DEC);
    size_t print(double n, int digits = 2);
    size_t print(const Printable& x);

    size_t println(const __FlashStringHelper *ifsh);
    size_t println(const String &s);
    size_t println(const char string[]);
    size_t println(char c);
    size_t println(unsigned char b, int base = DEC);
    size_t println(int n, int base = DEC);
    size_t println(unsigned int n, int base = DEC);
    size_t println(long n, int base = DEC);
    size_t println(unsigned long n, int base = DEC);
    size_t println(double n, int digits = 2);
    size_t println(const Printable& x);
    size_t println();
};

#endif
