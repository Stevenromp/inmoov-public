
#include <Wire.h>

TwoWire Wire1;

//Serial.println is my logger.. replace this by Serial.println or something..

 Serial.println(0, "I2C scanner. Scanning bus 0...");
        for (byte i = 8; i < 127; i++)
        {
            Wire.beginTransmission(i);
            if (Wire.endTransmission() == 0)
            {
                Serial.println(0, "Found address: " + String(i));
                // check address
                if ((i == 32) or (i == 39))
                {
                    // found device, do something..
                }

                delay(1);
            }
        }
        Wire.endTransmission();

        Serial.println(0, "I2C scanner. Scanning bus 1...");
        for (byte i = 8; i < 127; i++)
        {
            Wire1.beginTransmission(i);
            if (Wire1.endTransmission() == 0)
            {
                Serial.println(0, "Found address: " + String(i));
                // check address
                if (i == 64)
                {
                    // found device, do something..
                }

                delay(1);
            }
        }
        Wire1.endTransmission();

        Serial.println(1, "I2C device check DONE.");
