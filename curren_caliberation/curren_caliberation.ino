const int sensorPin = A0; // Analog pin for SCT-013-000
const float calibration = 30.0; // Adjust based on your burden resistor (30 for 10-bit ADC)
const float VREF = 5.0; // Reference voltage for Arduino ADC

void setup() {
    Serial.begin(115200); // Start serial communication
}

void loop() {
    const int sampleSize = 200; // Number of samples for RMS calculation
    float sum = 0;

    for (int i = 0; i < sampleSize; i++) {
        int sensorValue = analogRead(sensorPin); // Read analog value
        float voltage = (sensorValue / 1023.0) * VREF; // Convert to voltage
        float current = (voltage - (VREF / 2)) * calibration; // Convert to current
        sum += current * current; // Square the current value
        Serial.println(current); // Print current value for Serial Plotter
        delay(1); // Small delay for stable reading
    }

    float rmsCurrent = sqrt(sum / sampleSize); // RMS calculation
    Serial.print("RMS Current: ");
    Serial.println(rmsCurrent);
    delay(1000);
}

