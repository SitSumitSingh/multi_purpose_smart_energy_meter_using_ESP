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
     
  ![image](https://github.com/user-attachments/assets/701d9088-86ac-4439-ab47-3ab3a84d79c5)
  
   Like any other transformer, a current transformer has a primary winding, a magnetic core, and a secondary winding. The secondary winding comprises many turns of fine wire housed 
     within the casing of the transformer.

   ##### Specifications :
  * Input Current: 0-30A AC
    
  * Output Signal: DC 0-1 V
    
  * Non-linearity: 2-3 %
    
  * Built-in resistance (RL): 60 Ω
    
  * Turn Ratio: 20000:1
    
  * Resistance Grade: Grade B
    
  * Work Temperature: -25 °C~+70 °C
    
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

#### 3. Relay x2
#### 4. ESP-WROOM-32 x1
#### 5. OLED display x1
#### 6. Capacitor(10µF) x2


  
