// ZMPT101B Voltage Sensor with Arduino (Offset Correction & RMS Calculation)

#define ZMPT101B_PIN A0  // Analog pin connected to ZMPT101B

const float calibrationFactor = 687; // Adjust this factor based on calibration
const int sampleCount = 1000;          // Increase sample count for accuracy

void setup() {
    Serial.begin(115200);  // Start serial communication
}

void loop() {
    float sum = 0;
    float squaredSum = 0;
    float offsetVoltage = 2.5; // DC bias of the sensor (adjust based on measurement)

    for (int i = 0; i < sampleCount; i++) {
        int sensorValue = analogRead(ZMPT101B_PIN); // Read raw analog value
        float voltage = sensorValue * (5.0 / 1023.0); // Convert ADC value to voltage
        voltage -= offsetVoltage; // Remove DC offset
        squaredSum += voltage * voltage; // Sum of squares for RMS calculation
        Serial.println(voltage); // Print values for Serial Plotter visualization
        delayMicroseconds(1000); // Faster sampling for accuracy
    }

    float rmsVoltage = sqrt(squaredSum / sampleCount); // Compute RMS Voltage
    Serial.print("RMS Voltage: ");
    Serial.println(rmsVoltage);
    Serial.println(rmsVoltage * calibrationFactor, 2); // Display RMS Voltage

    delay(500); // Small delay before next computation
}
