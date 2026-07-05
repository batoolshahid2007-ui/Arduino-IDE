#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

#include <math.h>

MPU6050 mpu;

bool dmpReady = false;
uint8_t mpuIntStatus;
uint8_t devStatus;
uint16_t packetSize;
uint16_t fifoCount;
uint8_t fifoBuffer[64];

Quaternion q;
VectorFloat gravity;
float ypr[3];

double setpoint = 180.0;
double Kp = 21.0;
double Ki = 140.0;
double Kd = 0.8;

float input = 180.0;
float output = 0.0;
float last_input = 180.0;
float iTerm = 0.0;
float dTerm = 0.0;

unsigned long lastTime = 0;

const int ENA = 5;
const int IN1 = 6;
const int IN2 = 7;
const int IN3 = 8;
const int IN4 = 9;
const int ENB = 10;

volatile bool mpuInterrupt = false;

void dmpDataReady() {
    mpuInterrupt = true;
}

void setup() {

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    Wire.setClock(400000);
#endif

    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    analogWrite(ENA, 0);
    analogWrite(ENB, 0);

    mpu.initialize();

    devStatus = mpu.dmpInitialize();

    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788);

    if (devStatus == 0) {
        mpu.setDMPEnabled(true);
        attachInterrupt(digitalPinToInterrupt(2), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
        mpu.resetFIFO();
        packetSize = mpu.dmpGetFIFOPacketSize();
        dmpReady = true;
    } else {
        while (1);
    }

    lastTime = millis();
}

void loop() {

    if (!dmpReady) return;

    if (!mpuInterrupt) return;

    mpuInterrupt = false;

    mpuIntStatus = mpu.getIntStatus();
    fifoCount = mpu.getFIFOCount();

    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        mpu.resetFIFO();
        return;
    }

    if (mpuIntStatus & 0x02) {

        while (fifoCount < packetSize)
            fifoCount = mpu.getFIFOCount();

        mpu.getFIFOBytes(fifoBuffer, packetSize);
        fifoCount -= packetSize;

        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

        input = ypr[1] * 180.0 / M_PI + 180.0;

        calculatePID();
        controlMotors();
    }
}

void calculatePID() {

    unsigned long now = millis();
    double dt = (now - lastTime) / 1000.0;

    if (dt >= 0.005) {

        double error = setpoint - input;

        iTerm += Ki * error * dt;

        if (iTerm > 255) iTerm = 255;
        if (iTerm < -255) iTerm = -255;

        double dInput = (input - last_input) / dt;

        output = Kp * error + iTerm - Kd * dInput;

        if (output > 255) output = 255;
        if (output < -255) output = -255;

        last_input = input;
        lastTime = now;
    }
}

void controlMotors() {

    if (input > 210 || input < 150) {
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
        return;
    }

    int motorSpeed = constrain((int)fabs(output), 0, 255);

    if (output > 0) {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    }
    else if (output < 0) {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    }
    else {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
    }

    analogWrite(ENA, motorSpeed);
    analogWrite(ENB, motorSpeed);
}
