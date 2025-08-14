# Arduino-Sensors-and-CAN_BUS

## Overview
This repository contains Python and Arduino projects for reading sensor data and transmitting it via serial or CAN bus. The projects are designed for educational purposes, specifically for learning about ultrasonic distance sensors, soil moisture monitoring, IMU motion tracking, and CAN bus integration in a lab setting.

---

## Projects Included

### 1. Ultrasonic Distance
**Directory:** `ultrasonic_distance/`  
**Files:**  
- `ultrasonic_distance.py` – Python script for reading distance from an ultrasonic sensor  
- `README.md` – Project-specific documentation  

**Description:**  
Measures distance using an ultrasonic sensor connected to an Arduino and logs the data.  

---

### 2. Soil Moisture Logger
**Directory:** `soil_moisture_logger/`  
**Files:**  
- `soil_moisture_logger.py` – Python script for reading soil moisture sensor data  
- `README.md` – Project-specific documentation  

**Description:**  
Monitors soil moisture levels using a sensor and logs the data for analysis.  

---

### 3. IMU Motion Tracking
**Directory:** `imu_motion_tracking/`  
**Files:**  
- `imu_motion_tracking.py` – Python script for reading MPU6050 sensor data and calculating roll, pitch, and yaw  
- `README.md` – Project-specific documentation  

**Description:**  
Tracks motion and orientation using the MPU6050 IMU, combining accelerometer and gyroscope data with a complementary filter.  

---

### 4. CAN Bus Sensor Integration
**Directory:** `can_bus_sensor_integration/`  
**Files:**  
- `can_bus_sensor_integration.py` – Python script for reading sensor data via serial and sending it over CAN bus  
- `README.md` – Project-specific documentation  

**Description:**  
Integrates Arduino sensor data with CAN bus communication using a Canalyst-II device. Reads sensor values, sends them over CAN, and verifies received messages.  

---

## Requirements
- **Hardware:**  
  - Arduino Nano or Micro  
  - Ultrasonic sensor  
  - Soil moisture sensor  
  - MPU6050 sensor  
  - Canalyst-II CAN interface (for CAN project)  

- **Software:**  
  - Arduino IDE  
  - Python 3.x  
  - Python libraries: `numpy`, `matplotlib`, `serial`, `canalystii`  

---

## Usage
1. Upload the corresponding Arduino code (if needed) to the board.  
2. Run the Python script in each project folder to read and visualize sensor data.  
3. For CAN bus communication, ensure the Canalyst-II device is connected and the correct serial port is configured.  

---

## License
This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.

---

## Author
Hasham Muhammad
