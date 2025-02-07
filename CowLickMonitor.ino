#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <MPU6050.h>

MPU6050 mpu;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
    Serial.begin(115200);
    Wire.begin();

    // Check MPU6050 connection
    Serial.println("Initializing MPU6050...");
    if (mpu.testConnection()) {
        Serial.println("MPU6050 connection successful!");
        mpu.initialize();
    } else {
        Serial.println("MPU6050 connection failed!");
    }

    // Check MLX90614 connection
    Serial.println("Initializing MLX90614...");
    if (mlx.begin()) {
        Serial.println("MLX90614 connection successful!");
    } else {
        Serial.println("MLX90614 connection failed!");
    }
}

void loop() {
    // Read MPU6050 data
    int16_t ax, ay, az, gx, gy, gz;
    mpu.getAcceleration(&ax, &ay, &az);
    mpu.getRotation(&gx, &gy, &gz);
    Serial.print("MPU6050 Acceleration: ");
    Serial.print(ax); Serial.print(", ");
    Serial.print(ay); Serial.print(", ");
    Serial.println(az);
    Serial.print("MPU6050 Gyroscope: ");
    Serial.print(gx); Serial.print(", ");
    Serial.print(gy); Serial.print(", ");
    Serial.println(gz);

    // Read MLX90614 temperature
    Serial.print("MLX90614 Ambient Temp: ");
    //  Conversion equation for Celcius to Fahrenheit (celsius * 9.0 / 5.0) + 32.0;
    Serial.print((mlx.readAmbientTempC() * 9.0 / 5.0) + 32.0); // prints ambient temp
    Serial.print(" F, Object Temp: ");
    Serial.print((mlx.readObjectTempC() * 9.0 / 5.0) + 32.0); // prints object temp
    Serial.println(" F");

    delay(1000);  // Delay 1 second before next reading
}

