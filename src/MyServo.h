#ifndef MY_SERVO_H
#define MY_SERVO_H 1

#include <Arduino.h>
#include <Servo.h>


#define DELTA_T 15 // go at 66hz to best match the servo freq

class MyServo {
public:

    MyServo(int          pinNumber,
            float        maxAngleVelocity,
            unsigned int minFreq,
            unsigned int maxFreq,
            float        minRadAngle,
            float        maxRadAngle,
            float        homeRadAngle = 0);

    void         setAngleLimits(float minRadAngle,
                                float maxRadAngle);
    float        getMinRadAngle();
    float        getMaxRadAngle();

    void         setCalibrationFreq(unsigned int minFreq,
                                    unsigned int maxFreq);

    float        getCurrentAngle();
    float        getCurrentAngleExcludingOffset();

    void         setTargetRadAngle(float angleRad);
    float        getTargetRadAngle();
    float        getTargetRadAngleExcludingOffset();

    void         setOffset(float angleRad);
    float        getOffset();

    void         setCurrentAngleVelocity(float angleRadVelocity);
    float        getCurrentAngleVelocity();

    unsigned int getMinFreq();
    unsigned int getMaxFreq();

    void         setFreqency(long microseconds);

    float        getMaxAngleVelocity();

    bool         atTargetAngle();

    void         process(unsigned int deltaT = DELTA_T);

    float getHomeRadAngle();

private:

    bool virtualServo = false;

    unsigned int pinNumber;

    float homeAngle;

    unsigned int minFreq;
    unsigned int maxFreq;

    float offsetAngle = 0;
    volatile float currentAngle;
    float targetAngle = 0;

    unsigned long lastUpdate;

    float minRadAngle;
    float maxRadAngle;

    float currentAngleVelocity;
    float maxAngleVelocity;

    Servo servo;

    void         move();

    static float map_float(float x,
                           float in_min,
                           float in_max,
                           float out_min,
                           float out_max);
};
#endif /* ifndef MY_SERVO_H */

/*MyServo::MyServo(unsigned int pinNumber, float maxAngleVelocity)
    : servoLib(numba1 + numba2), thingTwo(numba1, numba2) {}
 */