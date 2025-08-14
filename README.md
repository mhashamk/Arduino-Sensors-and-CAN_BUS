# Arduino Sensors and CAN Bus Integration

[![Python](https://img.shields.io/badge/Python-3.x-blue.svg)](https://www.python.org/)
[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D.svg)](https://www.arduino.cc/)
[![License](https://img.shields.io/badge/License-Educational-green.svg)](#)

## Overview

This repository contains a comprehensive collection of Python and Arduino projects for sensor data acquisition, processing, and transmission. The projects demonstrate various communication protocols including serial communication and CAN bus integration, designed specifically for educational purposes in embedded systems and sensor technology courses.

Each project includes complete Python scripts for data logging, visualization, and analysis, along with corresponding Arduino code examples for sensor interfacing.

## Projects Included

### 1. 🔊 Ultrasonic Distance Measurement
- **File**: `ultrasonic_distance.py`
- **Functionality**: Real-time distance measurement using ultrasonic sensors
- **Features**: Time-of-flight calculation, CSV logging, statistical analysis
- **Hardware**: HC-SR04 ultrasonic sensor + Arduino

### 2. 🌱 Soil Moisture Monitoring
- **File**: `Soil Moisture Logger.py`
- **Functionality**: Voltage-to-moisture conversion with calibration
- **Features**: Characteristic curve plotting, percentage conversion
- **Hardware**: Capacitive/resistive soil moisture sensor + Arduino

### 3. 📱 IMU Motion Tracking (MPU6050)
- **File**: `Reading Serial Data from MPU6050.py`
- **Functionality**: 3-axis accelerometer data acquisition
- **Features**: Real-time plotting, histogram analysis, mean calculation
- **Hardware**: MPU6050 6-axis IMU sensor + Arduino

### 4. 🚗 CAN Bus Sensor Integration
- **File**: `can_bus_sensor_integration.py`
- **Functionality**: CAN bus communication with sensor data transmission
- **Features**: Bidirectional CAN messaging, data validation, error handling
- **Hardware**: Canalyst-II CAN interface + Arduino + CAN network

## Repository Structure

```
Arduino-Sensors-and-CAN_BUS/
├── README.md                           # This file
├── Ultrasonic Distance
│   ├── ultrasonic_distance.py               # Ultrasonic sensor project
│   ├── ultrasonic_distance.ino              # Arduino IDE project
│   ├── README.md                        
├── Soil Moisture Logger
│   ├── Soil Moisture Logger.py              # Soil moisture monitoring
│   ├── Soil Moisture Logger.ino             # Arduino IDE project
│   ├── README.md                     
├── IMU Motion Tracking
│   ├── Reading Serial Data from MPU6050.py  # IMU data acquisition
│   ├── BasisMPU6050.ino                     # Arduino IDE project
│   ├── MPU6050 Complementary Filter.ino     # Arduino IDE project
│   ├── README.md                       
├── 
│   ├── can_bus_sensor_integration.py        # CAN bus integration
│   ├── README.md                       

```

## Requirements

### Hardware Components
- **Microcontroller**: Arduino Nano, Uno, or Micro
- **Sensors**:
  - HC-SR04 Ultrasonic Distance Sensor
  - Capacitive or Resistive Soil Moisture Sensor
  - MPU6050 6-axis IMU (Accelerometer + Gyroscope)
- **CAN Interface**: Canalyst-II CAN Bus Analyzer (for CAN project)
- **Connections**: USB cables, jumper wires, breadboard

### Software Dependencies

#### Arduino IDE
- Install from [arduino.cc](https://www.arduino.cc/en/software)
- Required libraries (install via Library Manager):
  - `Wire.h` (built-in)
  - `MPU6050` library by Electronic Cats

#### Python Environment
```bash
pip install numpy matplotlib pyserial canalystii
```

**Required Python Libraries:**
- `numpy` - Numerical computations and array operations
- `matplotlib` - Data visualization and plotting
- `pyserial` - Serial communication with Arduino
- `canalystii` - CAN bus communication (for CAN project only)

## Quick Start

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/Arduino-Sensors-and-CAN_BUS.git
   cd Arduino-Sensors-and-CAN_BUS
   ```

2. **Install Python dependencies**:
   ```bash
   pip install -r requirements.txt
   ```

3. **Upload Arduino code** to your microcontroller (see individual project READMEs)

4. **Configure serial port** in Python scripts:
   ```python
   # Windows
   ser = serial.Serial('COM8', 9600)
   # macOS/Linux
   ser = serial.Serial('/dev/ttyUSB0', 9600)
   ```

5. **Run the desired project**:
   ```bash
   python ultrasonic_distance.py
   ```

## Features

- ✅ **Real-time Data Acquisition**: Live sensor readings via serial communication
- ✅ **Data Visualization**: Automatic plotting and histogram generation
- ✅ **CSV Data Logging**: Persistent storage for analysis
- ✅ **Statistical Analysis**: Mean, distribution, and trend analysis
- ✅ **Error Handling**: Robust error management and validation
- ✅ **Cross-platform**: Works on Windows, macOS, and Linux
- ✅ **Educational Focus**: Well-commented code for learning

## Educational Context

These projects were developed for:
- **Course**: Sensor Technology and Bus Systems Laboratory
- **Level**: Undergraduate Engineering
- **Objectives**: 
  - Understanding sensor interfacing principles
  - Learning data acquisition and processing techniques
  - Exploring communication protocols (Serial, CAN)
  - Practical application of embedded systems concepts

## Contributing

This repository is primarily for educational use. If you'd like to contribute improvements or additional sensor examples:

1. Fork the repository
2. Create a feature branch
3. Submit a pull request with detailed description

## License

This project is provided for educational purposes. Feel free to use.

## Support

For questions or issues:
- Check individual project README files for specific troubleshooting
- Verify hardware connections and software dependencies
- Ensure correct serial port configuration

## Author

**Hasham Muhammad**  
*Sensor Technology Laboratory*  
*Bus Systems Laboratory*

---

⭐ If this repository helped you learn about sensors and embedded systems, please give it a star!
