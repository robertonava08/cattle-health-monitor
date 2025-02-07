# Cattle Health Collar: An IoT-Based Vital Monitoring Device
An IoT device made to be worn by cattle on their necks to measure different vitals with the goal of increasing early disease detection and prevention

**COMPONENTS** 

  • ESP32 - microcontroller
  • MPU6050 - used to track movement and activity levels
  • MLX90614 - measures the temp of objects with or without contact
  • MAX30102 - measures the heart rate (will have to replace with something else since it has to be in direct contact of skin)



**Wiring Setup** 

  SDA of MLX90614 + SDA of MPU6050 --> D21 of ESP32

  SCL of MLX90614 + SCL of MPU6050 --> D22 of ESP32

  VIN of MLX90614 + VCC of MPU6050 --> 3V of ESP32

  GND of MLX90614 + GND of MPU6050 --> GND of ESP32

  