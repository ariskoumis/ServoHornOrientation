#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Servo.h"
 
MPU6050 mpu;
 
int16_t ax, ay, az;
int16_t gx, gy, gz;
 
Servo myservo;
 
int val;
int prevVal;
 
void setup() 
{
    Wire.begin();
    Serial.begin(9600); 
    mpu.initialize();
    myservo.attach(9);
}
 
void loop() 
{
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    val = map(ay, -17000, 17000, 0, 179);
    if (abs(val - prevVal) > 20)
    { 
        myservo.write(val);
        prevVal = val;
    }
}
