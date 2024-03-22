### posturemanagement
The Posture Management system is a wearable IoT jacket made with the help of various sensors such as accelerometer(ADXL335), MPU6050 and a couple of flex sensors along with a vibration module which has been attached to provide timely feedback assistance to the user. The data acquired from these sensors is then transferred to Thingspeak which can be further analysed for several purposes. Along with this, we have also developed a User Interface where the user can register himself and get timely updates about his/her posture.

The flex sensor measures the curvature of the back whereas the MPU6050 measures the x,y & z coordinates of the individual and the angular change in the individual's posture. The accelerometer attached is used for a special case of incorrect posture. All these sensors have been attached to different positions of the back: One of the flex sensors has been attached in the lumbar curve region to detect the bending of the lower back and the other one has been attached in the cervical curve region(corresponding to the pivot joint area). The two MPU6050 sensors have been located on the upper left and upper right corners of the back and the accelerometer is located just below the flex sensor in the lumbar curve region. The vibration module is attached just besides the accelerometer.We have integrated all three sensors together and used their values to detect various cases of incorrect postures and send a signal to the vibration actuator whenever the posture of the individual is incorrect.
