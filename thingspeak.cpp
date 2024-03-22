#include <Wire.h>
#include <MPU6050_tockn.h>
#include <WiFi.h>
#include "ThingSpeak.h"

const char WIFI_SSID = "DivyaJ";   // your network SSID (name) 
const char WIFI_PASSWORD = "y2kij52t";   // your network password
unsigned long channelID = 2481767;
const char* readAPIKey = "7X6VAGOY4MC3CWS6";
const char* writeAPIKey = "6DX8IRWVRM09SG8P";

WiFiClient  client;

const int xPin = A0; // Connect X-axis of accelerometer to analog pin A0
const int yPin = A3; // Connect Y-axis of accelerometer to analog pin A1
const int zPin = A6; // Connect Z-axis of accelerometer to analog pin A2
#define SDA_PIN 21      // Define SDA pin
#define SCL_PIN 22      // Define SCL pin
#define FLEX_PIN_1 A7     // Flex sensor pin
#define FLEX_PIN_2 4
#define LED_PIN 2       // LED pin

#define THRESHOLD 500   // Threshold value for LED activation

MPU6050 mpu6050_1(Wire);
MPU6050 mpu6050_2(Wire);

void setup() {
  Serial.begin(9600); // Initialize serial communication
  Wire.begin(SDA_PIN, SCL_PIN); // Initialize I2C with defined SDA and SCL pins
  pinMode(LED_PIN, OUTPUT);
  // Initialize MPU6050 1
  mpu6050_1.begin();
  // Initialize MPU6050 2
  mpu6050_2.begin();
  delay(1000);
}

void loop() {
  // Read analog values from accelerometer
  int xValue = analogRead(xPin);
  int yValue = analogRead(yPin);
  int zValue = analogRead(zPin);

  // Read accelerometer and gyroscope data from MPU6050 1
  mpu6050_1.update();
  // Get accelerometer data
  float ax1 = mpu6050_1.getAccX();
  float ay1 = mpu6050_1.getAccY();
  float az1 = mpu6050_1.getAccZ();

  float gx1 = mpu6050_1.getGyroX();
  float gy1 = mpu6050_1.getGyroY();
  float gz1 = mpu6050_1.getGyroZ();

  // Read accelerometer and gyroscope data from MPU6050 2
  mpu6050_2.update();
  // Get accelerometer data
  float ax2 = mpu6050_2.getAccX();
  float ay2 = mpu6050_2.getAccY();
  float az2 = mpu6050_2.getAccZ();

  float gx2 = mpu6050_2.getGyroX();
  float gy2 = mpu6050_2.getGyroY();
  float gz2 = mpu6050_2.getGyroZ();

  // Read flex sensor value
  int flexValue1 = analogRead(FLEX_PIN_1);
  Serial.print("Flex Sensor1 Value: ");
  Serial.println(flexValue1);

  // Read flex sensor value
  int flexValue2 = analogRead(FLEX_PIN_2);
  Serial.print("Flex Sensor2 Value: ");
  Serial.println(flexValue2);

  // Write sensor data to ThingSpeak fields
  ThingSpeak.writeField(ChannelNumber, Flex1FieldNumber, flexValue1, myCounterReadAPIKey);
  ThingSpeak.writeField(ChannelNumber, Flex2FieldNumber, flexValue2, myCounterReadAPIKey);
  ThingSpeak.writeField(ChannelNumber, MPU1FieldNumber, ax1, myCounterReadAPIKey);
  ThingSpeak.writeField(ChannelNumber, MPU2FieldNumber, ax2, myCounterReadAPIKey);
  ThingSpeak.writeField(ChannelNumber, AccelerometerFieldNumber, xValue, myCounterReadAPIKey);

  delay(1000); // Delay for stability
}
