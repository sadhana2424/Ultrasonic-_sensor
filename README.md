## 📏 Ultrasonic Distance Measurement System using ESP8266

## 📌 Project Overview
The Ultrasonic Distance Measurement System is an IoT project developed using the ESP8266 (NodeMCU) and an HC-SR04 Ultrasonic Sensor. The system measures the distance of nearby objects in real time and displays the measured distance on a web page. It is useful for obstacle detection, smart parking, water level monitoring, and automation projects.

## 🎯 Objective
Measure the distance between the sensor and an object.
Display real-time distance on a web page.
Learn ultrasonic sensor interfacing with ESP8266.
Build a simple IoT-based monitoring system.

## 🛠️ Components Required
ESP8266 NodeMCU
HC-SR04 Ultrasonic Sensor
Breadboard
Jumper Wires
USB Cable
Wi-Fi Connection

## 🔌 Circuit Connections
Ultrasonic Sensor	ESP8266 Pin
VCC	5V
GND	GND
TRIG	D1 (GPIO5)
ECHO	D2 (GPIO4) (Use a voltage divider to reduce 5V to 3.3V)
## ⚙️ Working Principle
The ESP8266 sends a trigger pulse to the HC-SR04 sensor.
The sensor emits ultrasonic waves.
The waves reflect from the object and return to the sensor.
The ESP8266 calculates the distance based on the echo time.
The measured distance is displayed on a web page in real time.

## 🌐 Web Interface Features
Real-time Distance Display
Distance in Centimeters (cm)
Responsive HTML & CSS Design
Automatic Data Refresh

## ▶️ How to Run
Connect the HC-SR04 sensor to the ESP8266.
Open the project in Arduino IDE.
Install the ESP8266 Board Package.
Enter your Wi-Fi SSID and Password.
Upload the code to the ESP8266.
Open the Serial Monitor.
Copy the IP address displayed.
Open the IP address in your browser.
Move an object in front of the sensor and observe the distance reading.

## 📊 Sample Output
Distance	Status
0–10 cm	Very Close
11–30 cm	Near
Above 30 cm	Safe Distance

## 🌍 Applications
Smart Parking Systems
Obstacle Detection
Water Tank Level Monitoring
Robotics
Home Automation
Industrial Automation

## 🚀 Features
Real-time Distance Measurement
Wi-Fi Enabled
Live Web Dashboard
Accurate Object Detection
Beginner-Friendly ESP8266 Project

## 💻 Software Used
Arduino IDE
ESP8266 Board Package
HTML
CSS


### Web Dashboard

![Web Dashboard](hardware1.png)

### Hardware Setup

![Hardware Setup](hardware2.png)

## Demo Video

🎥 [Watch Project Demo](https://drive.google.com/file/d/1Ce3LrrWuqdqoDwebxSmZDOWUzq4CT7vN/view?usp=drivesdk)

## Author

Sadhana
