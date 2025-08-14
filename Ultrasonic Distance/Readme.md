# Ultrasonic Distance Sensor Data Logger

This Python script reads distance measurements from an ultrasonic sensor connected via serial communication (typically through an Arduino). It processes time-of-flight data, logs measurements to a CSV file, and provides statistical analysis and visualization.

## Features

- Real-time ultrasonic distance measurement logging
- CSV data storage with configurable format
- Statistical analysis (mean calculation)
- Data visualization (line plot and histogram)
- Cross-platform serial port support

## Requirements

### Hardware
- Ultrasonic distance sensor (e.g., HC-SR04)
- Arduino or microcontroller for sensor interface
- USB/Serial connection to computer

### Software Dependencies

Install the required Python packages:

```bash
pip install pyserial numpy matplotlib
```

## Configuration

### Serial Port Setup

Update the serial port configuration for your system:

```python
# macOS/Linux example
ser = serial.Serial('/dev/cu.usbserial-14430', 9600)

# Windows alternative
# ser = serial.Serial('COM8', 9600)

# Linux alternative  
# ser = serial.Serial('/dev/ttyUSB0', 9600)
```

### Data Collection Parameters

Modify the number of readings:

```python
max_readings = 100  # Adjust as needed
```

## Usage

1. Connect your ultrasonic sensor to an Arduino
2. Upload Arduino code that measures distance and sends time-of-flight data
3. Connect Arduino to your computer via USB
4. Update the serial port path in the script
5. Run the script:

```bash
python ultrasonic_distance.py
```

## How It Works

1. **Serial Initialization**: Opens serial connection and flushes input buffer
2. **Data Collection Loop**: 
   - Reads time-of-flight measurements from serial port
   - Converts byte data to integer (milliseconds)
   - Saves each reading to CSV file
   - Stores values for analysis
3. **Visualization**:
   - Line plot showing measurement progression
   - Histogram showing data distribution
4. **Statistics**: Calculates and displays mean time-of-flight

## Data Format

- **Input**: Time-of-flight measurements in milliseconds via serial
- **Output**: CSV file with space-delimited values
- **File**: `test_data_11227.csv` (created in script directory)

## Distance Calculation

To convert time-of-flight to distance:

```python
# Speed of sound = 343 m/s at 20°C
# Distance = (time_of_flight × speed_of_sound) / 2
distance_cm = (time_of_flight_ms / 1000) * 34300 / 2
```

## Arduino Code Example

Compatible Arduino code for HC-SR04 sensor:

```arduino
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send trigger pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read echo duration
  long duration = pulseIn(echoPin, HIGH);
  
  // Convert to milliseconds and send
  Serial.println(duration / 1000);
  delay(100);
}
```

## Visualization Output

The script generates two plots:

1. **Figure 0**: Line plot showing time-of-flight progression over measurement number
2. **Figure 1**: Histogram showing the distribution of time-of-flight values

## CSV File Format

The CSV file contains:
- One measurement per line
- Space-delimited format
- Optional timestamp (commented in code)

To enable timestamps:

```python
import time

# In the data collection loop:
writer.writerow([time.time(), decoded_bytes])
```

## Troubleshooting

1. **Serial Port Issues**:
   ```bash
   # List available ports (macOS/Linux)
   ls /dev/cu.* /dev/tty.*
   
   # List available ports (Linux)
   ls /dev/ttyUSB* /dev/ttyACM*
   ```

2. **Permission Issues** (Linux/macOS):
   ```bash
   sudo usermod -a -G dialout $USER  # Linux
   sudo chmod 666 /dev/cu.usbserial-14430  # macOS
   ```

3. **Data Reading Problems**:
   - Verify Arduino serial output in Serial Monitor
   - Check baud rate matches (9600)
   - Ensure sensor wiring is correct
   - Verify power supply stability

4. **Package Installation**:
   ```bash
   pip install --upgrade pyserial matplotlib numpy
   ```

## Applications

This code is suitable for:
- Distance measurement projects
- Object detection systems
- Level monitoring applications
- Robotics obstacle avoidance
- Laboratory sensor characterization
- Educational demonstrations

## Sensor Specifications (HC-SR04)

- **Range**: 2cm - 400cm
- **Accuracy**: ±3mm
- **Resolution**: 0.3cm
- **Operating Voltage**: 5V DC
- **Operating Current**: <15mA
- **Operating Frequency**: 40kHz

## Author

Created by Hasham Muhammad  
