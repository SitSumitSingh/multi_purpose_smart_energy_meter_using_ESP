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
#### 1. SCT-013-030 (current sensor) x2
  
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


#### 2. ZMPT101b (voltage sensor) x1

![image](https://github.com/user-attachments/assets/e3c2baff-99c1-4b04-9374-2c743cc0c512)

The ZMPT101B AC Single Phase voltage sensor module is based on a high precision ZMPT101B voltage Transformer used to measure the accurate AC voltage with a voltage transformer. This is an ideal choice to measure the AC voltage using Arduino or ESP32.

The Modules can measure voltage within 250V AC voltage & the corresponding analog output can be adjusted. The module is simple to use and comes with a multi-turn trim potentiometer for adjusting and calibrating the ADC output.

##### Specifications
* Voltage up to 250 volts can be measured    
* Lightweight with on-board micro-precision voltage transformer     
* High precision on-board op-amp circuit      
* Operating temperature : 40ºC ~ + 70ºC     
* Supply voltage 5 volts to 30 volts       

#### 3. Two Channel Relay Module x1

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
  
#### 4. ESP-WROOM-32 x1
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
  
#### 5. OLED display x1 (SSD1306 0.96 inch )
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

#### 6. Capacitor(10µF) x2

<img src="https://github.com/user-attachments/assets/729d783d-8176-4e05-8085-85eec1a4d77f" width="30%" />






  
