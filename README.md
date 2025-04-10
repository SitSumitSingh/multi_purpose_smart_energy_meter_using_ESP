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
* SCT-013-030 (current sensor) x2
* ZMPT101b (voltage sensor) x1
* Relay x2
* ESP-WROOM-32 x1
* OLED display x1
* Capacitor(10µF) x2


  
