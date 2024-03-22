#include <Wire.h>
#include <MPU6050_tockn.h>

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
}

void loop() {
  // Read analog values from accelerometer
  int xValue = analogRead(xPin);
  int yValue = analogRead(yPin);
  int zValue = analogRead(zPin);

  // Print values to serial monitor
  Serial.print("Analog Accelerometer Values - X: ");
  Serial.print(xValue);
  Serial.print("\tY: ");
  Serial.print(yValue);
  Serial.print("\tZ: ");
  Serial.println(zValue);

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

  // Print data to serial monitor for MPU6050 1
  Serial.print("MPU6050 1 - AccX1: ");
  Serial.print(ax1);
  Serial.print("\tAccY1: ");
  Serial.print(ay1);
  Serial.print("\tAccZ1: ");
  Serial.println(az1);

  Serial.print("MPU6050 Gyroscope Values - GyroX1: ");
  Serial.print(gx1);
  Serial.print("\tGyroY1: ");
  Serial.print(gy1);
  Serial.print("\tGyroZ1: ");
  Serial.println(gz1);

  // Print data to serial monitor for MPU6050 2
  Serial.print("MPU6050 2 - AccX2: ");
  Serial.print(ax2);
  Serial.print("\tAccY2: ");
  Serial.print(ay2);
  Serial.print("\tAccZ2: ");
  Serial.println(az2);

  Serial.print("MPU6050 Gyroscope Values - GyroX2: ");
  Serial.print(gx2);
  Serial.print("\tGyroY: ");
  Serial.print(gy2);
  Serial.print("\tGyroZ: ");
  Serial.println(gz2);

  // Read flex sensor value
  int flexValue1 = analogRead(FLEX_PIN_1);
  Serial.print("Flex Sensor1 Value: ");
  Serial.println(flexValue1);

  // Control LED based on flex sensor value
  if (flexValue1 > THRESHOLD) {
    digitalWrite(LED_PIN, HIGH); // Turn on LED if flex value exceeds threshold
  } else {
    digitalWrite(LED_PIN, LOW);  // Turn off LED if flex value is below threshold
  }

  delay(1000); // Delay for stability

  int flexValue2 = analogRead(FLEX_PIN_2);
  Serial.print("Flex Sensor2 Value: ");
  Serial.println(flexValue2);

  // Control LED based on flex sensor value
  if (flexValue2 > THRESHOLD) {
    digitalWrite(LED_PIN, HIGH); // Turn on LED if flex value exceeds threshold
  } else {
    digitalWrite(LED_PIN, LOW);  // Turn off LED if flex value is below threshold
  }

  delay(1000); // Delay for stability
}
