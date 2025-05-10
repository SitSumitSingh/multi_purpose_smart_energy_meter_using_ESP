## Smart Energy Meter using ESP-32 (IOT)
-------------------------------------------------------------------

### 1. Abstract 
The IoT-Based Smart Energy Meter is an intelligent energy monitoring system designed to measure and track voltage, current, power consumption, and cost estimation for multiple household appliances, including a Fan, Air Conditioner, and Bulb etc. The system utilizes an ESP32 microcontroller connected to current and voltage sensors (SCT-013-000 & ZMPT101B) to obtain real-time energy data. This data is processed and displayed on an OLED screen, sent to an IoT dashboard (Blynk, Firebase, or Google Sheets), and stored for historical analysis.

The project incorporates relays and for remote appliance control while ensuring electrical safety. A Google Sheets webhook is integrated to log energy data for further analysis. Machine Learning algorithms can be applied to predict usage patterns and optimize energy consumption.

Key challenges such as WiFi disconnection, inaccurate sensor readings, and overheating are mitigated through automatic reconnection mechanisms, software filtering techniques, and efficient PCB design with heat management solutions. Future enhancements include AI-based load prediction, solar energy integration, and voice control via Google Assistant/Alexa.

This system provides an efficient, scalable, and cost-effective solution for home energy management, allowing users to monitor, control, and optimize energy consumption in real-time.

### 2. Introduction
The rapid growth of urbanization and industrialization has led to an exponential increase in global electricity consumption, necessitating efficient and intelligent energy monitoring systems. Traditional energy meters provide only aggregate consumption data, lacking real-time insights, remote accessibility, or intelligent load management features. This limitation hinders consumers' ability to analyze, optimize, and control their power usage effectively.

An energy meter is a device used to measure the electrical energy consumed by a residence, business, or an electrically powered device. In modern smart grid infrastructures, energy meters have evolved into digital, network-enabled systems capable of capturing real-time data, communicating with cloud platforms, and enabling bidirectional energy flow in distributed energy networks.

### 3. Problem Statement
Several existing systems use Arduino and GSM for single-load energy monitoring. However, most lack cloud integration or multi-load capability. This project aims to overcome those limitations by using:
* ESP32 for multi-load monitoring with Wi-Fi capability. 
* Google Sheets integration for cloud-based data logging. 
* Blynk IoT platform for mobile-based visualization.

### 4. Components used 
#### I. SCT-013-030 (current sensor) x2
  
  ![image](https://github.com/user-attachments/assets/ad44aa54-9d6c-468d-bb39-d27f56a4cad1)
  
   The SCT-013 is a Non-invasive AC Current Sensor Split Core Type Clamp Meter Sensor that can be used to measure AC current up to 30 amperes. Current transformers (CTs) are sensors 
     are for measuring alternating current. They are particularly useful for measuring whole building electricity consumption. The SCT-013 current sensors can be clipped straight either 
     to the live or neutral wire without having to do any high voltage electrical work.
     
  ![image](https://github.com/user-attachments/assets/50eb48be-560c-4152-aa7a-25318080674d)

  
   Like any other transformer, a current transformer has a primary winding, a magnetic core, and a secondary winding. The secondary winding comprises many turns of fine wire housed 
     within the casing of the transformer.

   ##### Specifications :
  * Input Current: 0-30A AC     
  * Output Signal: DC 0-1 V    
  * Non-linearity: 2-3 %   
  * Built-in resistance (RL): 60 Ω    
  * Turn Ratio: 2000:1         
  * Resistance Grade: Grade B    
  * Work Temperature: -25 °C ~ +70 °C        
  * Dielectric Strength (between shell and output): 1000 V AC / 1 min 5 mA     


#### II. ZMPT101b (voltage sensor) x1

![image](https://github.com/user-attachments/assets/e3c2baff-99c1-4b04-9374-2c743cc0c512)

The ZMPT101B AC Single Phase voltage sensor module is based on a high precision ZMPT101B voltage Transformer used to measure the accurate AC voltage with a voltage transformer. This is an ideal choice to measure the AC voltage using Arduino or ESP32.

The Modules can measure voltage within 250V AC voltage & the corresponding analog output can be adjusted. The module is simple to use and comes with a multi-turn trim potentiometer for adjusting and calibrating the ADC output.

##### Specifications
* Voltage up to 250 volts can be measured    
* Lightweight with on-board micro-precision voltage transformer     
* High precision on-board op-amp circuit      
* Operating temperature : 40ºC ~ + 70ºC     
* Supply voltage 5 volts to 30 volts       

#### III. Two Channel Relay Module x1

![image](https://github.com/user-attachments/assets/2685989e-1ca3-4bf0-b677-e7a30465cedb)

##### Specifications
* Low Level Trigger Relay Module   
* Two separate LEDs for On/Off indication of the Relay.  
* Triggering input voltage 3.3V – 5V.  
* Back EMF protection  
* Opto isolation circuitry   
* Module with diode current protection, short response time   
* AC Control Voltage: 250V @max.10A  
* DC Control Voltage: 30V @max. 10A   
  
#### IV. ESP-WROOM-32 x1
The ESP-WROOM-32 is a powerful Wi-Fi + Bluetooth combo module developed by Espressif, and it's the core module in many ESP32-based development boards. Here's a quick breakdown of its key features and why it's popular in IoT and embedded systems projects:

![image](https://github.com/user-attachments/assets/ee644498-e422-44f8-a43a-6212c5a91a60)

##### Key Features :
* Processor: Dual-core Tensilica LX6 microprocessor, up to 240 MHz     
* Memory: 520 KB SRAM   
4 MB Flash (typically, depending on the breakout board)   
* Wireless:
    Wi-Fi: 802.11 b/g/n.       
    Bluetooth: v4.2 BR/EDR and BLE    
* GPIO Pins: 34 programmable GPIOs (input/output, PWM, ADC, DAC, I2C, SPI, UART, etc.)    
* ADC: 12-bit, 18 channels (some shared with other functions)     
* DAC: 2 channels (8-bit)      
* Touch Sensors: 10 capacitive touch inputs    
* PWM: Supported on all GPIOs    
* Security: Secure boot, flash encryption, and cryptographic hardware acceleration    
* Operating Voltage: 3.0V to 3.3V    
* Power Consumption: Ultra-low power modes supported   
  
#### V. OLED display x1 (SSD1306 0.96 inch )
An OLED (organic light-emitting diode) is used frequently in displaying texts, bitmap images, shapes, and different types of clocks. They offer good view angles and pixel density in a cost-effective manner.


<img src="https://github.com/user-attachments/assets/3416a738-be92-47c2-9000-3770bcb4d8a6" width="300"/>
<img src="https://github.com/user-attachments/assets/c711d1ca-64fd-4898-82f7-cb6e1b1f7534" width="300"/>

##### Specifications
* Size :	0.96 inch    
* Terminals :	4   
* Pixels :	128×64    
* Communication :	I2C     
* VCC	: 3.3V-5V    
* Operating Temperature	: -40℃ to +80℃   

#### VI. Capacitor(10µF) x2

<img src="https://github.com/user-attachments/assets/729d783d-8176-4e05-8085-85eec1a4d77f" width="30%" />

#### VII. Buck Converter x1

A buck converter is a type of DC-DC converter that steps down voltage from its input (supply) to its output (load). It’s widely used in power electronics to efficiently supply lower voltages from higher ones, like converting 12V to 5V in embedded systems.

![image](https://github.com/user-attachments/assets/d48c53c4-c60a-4fec-91d4-3e16100c0411)

##### Specification
* Input voltage: 3-40V
* Output voltage: 1.5-35V(Adjustable)
* Output current: Rated current is 2A, maximum 3A
* Switching Frequency: 150KHz
* Operating temperature:Industrial grade (-40 to +85 )
* Conversion efficiency: 92%(highest)

#### VIII. Vero board x1

![image](https://github.com/user-attachments/assets/04ed2800-c4ef-48f1-bd5a-97d4fa715546)


### 5. Software Used 

* Arduino IDE :
  The Arduino IDE (Integrated Development Environment) is a software platform used to write, compile, and upload code to Arduino boards. It's the main tool used to program Arduino-based microcontrollers.

* Circuit Designer :
   It is a tool that let you create, simulate, and share electronic circuits right from your browser, without needing to install anything.

* Blynk IOT:
  Blynk IoT is a popular platform for building IoT (Internet of Things) applications that allows you to control and monitor hardware devices (like ESP32, ESP8266, Arduino, etc.) from your smartphone or web dashboard — without needing to build your own backend infrastructure.

### 6. Block Diagram

![image](https://github.com/user-attachments/assets/41fcf83a-922f-4e7e-960e-1b655d835d9c)

This is a block diagram of a dual-load IoT-based energy monitoring and control system using an ESP32 microcontroller, integrating Blynk IoT, CT sensors, voltage transformer, relays, and display. Here's a breakdown of each block:   

🔌 1. Power Supply (Left Side):   
Provides the AC power to both LOAD1 and LOAD2.    
This AC supply is monitored for current and voltage.    

🔋 2. LOAD1 and LOAD2:      
Two different electrical loads (e.g., lights, fans, appliances) being powered and monitored.        
Relays are used to control (ON/OFF) these loads through the ESP32.     

🧲 3. CT1 and CT2 (Current Transformers):     
* CT1 monitors the current drawn by LOAD1.      
* CT2 monitors the current drawn by LOAD2.     
These sensors measure current and send analog signals to the ESP32 for processing.  

⚡ 4. VT (Voltage Transformer):    
Measures the line voltage.    
Sends a scaled-down analog signal to the ESP32 for safe voltage sensing.     

🧠 5. ESP32 Microcontroller:      
Core processing unit of the system.   
Tasks:      
* Reads current from CT1 and CT2.    
* Reads voltage from VT.    
* Calculates power consumption.     
* Controls the relays (thus, LOAD1 and LOAD2).   
* Sends data to the Blynk Cloud via Wi-Fi.   
* Displays real-time values on a connected display (likely OLED or LCD).    

📟 6. Display:    
Shows local real-time data such as:   
* Voltage   
* Current   
* Power usage for each load   
* Possibly cost, energy consumed, etc.   

🌐 7. Blynk IoT System (Cloud + Mobile App):    
The ESP32 is connected to the Blynk cloud over Wi-Fi. A smartphone app communicates with Blynk cloud.   
You can:   
* Monitor real-time values (current, voltage, power).     
* Control LOAD1 and LOAD2 using switches in the app.    

### 7. Circuit Diagram

![circuit_image (1)](https://github.com/user-attachments/assets/0b1b877a-8d76-43c8-ad8c-1618a8dff117)

Component----ESP32      
Current_1---- 32          
Current_2---- 33       
Relay_1---- 25     
Relay_2---- 26       
Voltage---- 34 & 35        
OLED Display     
Vcc-------	3.3V       
GND-------	GND     
SCK-------	 22      
SDA-------	 21      
##### Complete Circuit Diagram

![circuit_image (2)](https://github.com/user-attachments/assets/b0a84bff-8a7f-4a4e-81d6-cfe60ebf9531)


### 8. PCB design:  

![WhatsApp Image 2025-04-20 at 10 58 07_8cbd12aa](https://github.com/user-attachments/assets/029e4e7f-7cef-4f65-a04a-7146cae0063a)

![WhatsApp Image 2025-04-20 at 10 58 11_fbe9134e](https://github.com/user-attachments/assets/828b1e5f-b65d-4837-9851-699688a43aa9)

### 9. Algorithm:
Objective: Monitor voltage, current, power, energy consumption, and cost for two electrical loads using an ESP32. Control relays based on power thresholds, display data on an OLED screen, send data to Blynk for remote monitoring, and log data to Google Sheets.    

 ***✅ 1. Initialization Phase (`setup()`)***
- 1.1. **Start Serial Communication**
   - Begin Serial Monitor at **baud rate 115200** for debugging.
- 1.2. **Set Analog Resolution**
  - Set **ADC resolution to 10 bits** using `analogReadResolution(10);`, suitable for reading analog sensor signals.
- 1.3. **Connect to Wi-Fi**
  - Start Wi-Fi using the provided **SSID and password**.
  - Keep trying until the connection is established.
- 1.4. **Start Blynk Connection**
  - Connect to **Blynk** using the **template ID** and **auth token**.
- 1.5. **(Optional) Initialize OLED Display**
  - OLED initialization code is present but commented out.
  - If enabled, it displays a **welcome message**.
- 1.6. **Configure Relay Pins**
  - Set `relay1` and `relay2` as **outputs**.
- Initialize them to **LOW (off)** state.
- 1.7. **Initialize Energy Monitors**
  - `emon1` and `emon2` are set up to monitor:
    - **Voltage** using **ZMPT101B** with a calibration constant of **520**.
    - **Current** using **SCT-013-000** with calibration constants:
      - **25** for Load 1
      - **95** for Load 2

 ***🔁 2. Continuous Monitoring Loop (`loop()`)***
- 2.1. **Run Blynk**
  - Ensures real-time communication with the **Blynk app**.
  - 2.2. **Sample Voltage & Current**
  - Call `calcVI(20, 2000)` for both `emon1` and `emon2`:
  - Measures **20 half-cycles** (~1 second at 50Hz).
  - Timeout after **2000 ms**.
- 2.3. **Extract RMS & Power Values**
  - Read **voltage, current, real power, and apparent power**.
  - Use `fabs()` to take **absolute values** and filter out negative noise.
- 2.4. **Energy & Cost Calculation (every 10 seconds)**
  - Check if **10 seconds** have passed using `millis()`.
  - If so:
    - **Energy (kWh)** = Power (W) × Time (hr)       
      `(realPower × interval / 3600000.0) / 1000`
    - **Cost** = Energy × ₹10/kWh
    - Send data to **Google Sheets** via a URL with query parameters.
 - 2.5. **Relay Control**
   - **Turn ON** relay if **real power > 100W**, else **turn OFF**.
 - 2.6. **Send Data to Blynk App**
   - Push the following to **Blynk virtual pins**:
   - **Voltage, Current, Energy, Power Factor, Cost, Relay State** (for both loads)
 - 2.7. **OLED Display**
   - Code for OLED is available but **commented out**.
   - Alternates display between **Load 1 and Load 2** every 2 seconds.

***🌐 3. Google Sheets Logging (`sendToGoogleSheets()`)***
- 3.1. **Construct URL**
   - Build a **GET request URL** with all sensor readings and calculations.
- 3.2. **Send HTTP GET Request**
  - Send data using `http.GET()` to a **Google Apps Script Web App**.
  - Print **success/failure** status to Serial Monitor.

 ***📦 Summary of Main Components Used***

| Component       | Purpose                                      |
|----------------|----------------------------------------------|
| **EmonLib**     | For calculating voltage, current, and power. |
| **WiFi + Blynk**| Real-time monitoring on mobile app.          |
| **Google Sheets** | Cloud-based logging for history/tracking. |
| **Relays**      | Automatic load control based on power usage. |
| **OLED (optional)** | Local display for power/energy info.    |

### ⚙️ Current Caliberation Algorithm (SCT-013-030)
This section explains how the RMS current is calculated from the analog signal of the SCT-013-000 current sensor.

**🔄 Algorithm Steps:**
***1. Define Constants:***
   - `sensorPin` is set to **A0**, where the SCT-013-000 sensor is connected.
   - `calibration` factor is set to **30.0**, based on the burden resistor and ADC scaling.
   - `VREF` is set to **5.0V**, the Arduino's reference voltage.

***2. Initialize Serial Communication:***
   - Start **Serial Monitor** at 115200 baud for debugging and data plotting.

***3. Sampling Loop:***
   - Take **200 samples** in each loop cycle for a smooth RMS calculation.
   - For each sample:
     - Read analog value from the sensor pin using `analogRead(sensorPin)`.
     - Convert the raw value to voltage using:  
       `voltage = (sensorValue / 1023.0) * VREF`
     - Convert voltage to instantaneous current using:  
       `current = (voltage - VREF/2) * calibration`
     - Square the current and add to a running sum:  
       `sum += current * current`
     - Print the instantaneous current value to the Serial Plotter.

***4. Calculate RMS Current:***
   - After 200 samples, calculate RMS current as:  
     `rmsCurrent = sqrt(sum / sampleSize)`
   - Print the RMS current to the Serial Monitor.

***5. Delay:***
   - Wait **1 second** before repeating the loop to allow stable output.

**📌 Notes:**
- This code assumes the sensor outputs a centered AC signal around **VREF/2**.
- Adjust the `calibration` constant if using a different burden resistor or ADC resolution.




  
