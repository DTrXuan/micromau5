#include <Wire.h>
#include <L3G.h>

L3G gyro;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }

  gyro.enableDefault();
}

void loop() {
  gyro.read();

  Serial.print("G ");
  Serial.print("X: ");
  // Roll
  Serial.print((int)gyro.g.x);
  Serial.print(" Y: ");
  // Pitch
  Serial.print((int)gyro.g.y);
  Serial.print(" Z: ");
  // Yaw
  Serial.println((int)gyro.g.z);

  delay(100);
}
