# MPU6050 Serial Data Reader

This Python script reads accelerometer data from an MPU6050 sensor connected via serial communication (typically through an Arduino). It processes the X-axis acceleration data, saves it to a CSV file, and provides visualization and statistical analysis.

## Features

- Real-time serial data acquisition from MPU6050
- CSV data logging
- Data visualization (line plot and histogram)
- Statistical analysis (mean calculation)

## Requirements

### Hardware
- MPU6050 accelerometer/gyroscope sensor
- Arduino or microcontroller for sensor interface
- USB/Serial connection to computer

### Software Dependencies

Install the required Python packages:

```bash
pip install pyserial numpy matplotlib
```

## Configuration

Update the serial port configuration before running:

```python
ser = serial.Serial('COM8', 9600)  # Windows
# For Linux/Mac: ser = serial.Serial('/dev/ttyUSB0', 9600)
```

## Usage

1. Connect your MPU6050 sensor to an Arduino
2. Upload Arduino code that reads X-axis acceleration and sends via serial
3. Connect Arduino to your computer via USB
4. Update the COM port in the script
5. Run the script:

```bash
python "Reading Serial Data from MPU6050.py"
```

## How It Works

1. **Serial Initialization**: Opens serial connection and flushes input buffer
2. **Warm-up Phase**: Reads and discards first 10 readings to stabilize
3. **Data Collection**: Reads 10 acceleration values from X-axis
4. **Data Processing**: 
   - Converts bytes to integer values
   - Saves each reading to CSV file
   - Stores values for analysis
5. **Visualization**:
   - Line plot showing measurement progression
   - Histogram showing data distribution
6. **Statistics**: Calculates and displays mean value

## Data Format

- **Input**: Serial data as UTF-8 encoded integers
- **Output**: CSV file with space-delimited values
- **File**: `test_data_neu.csv` (created in script directory)

## Visualization

The script generates two plots:

1. **Figure 0**: Line plot showing acceleration values over measurement number
2. **Figure 1**: Histogram showing the distribution of acceleration values

## Arduino Code Example

Your Arduino should send acceleration data like this:

```arduino
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);
  
  Serial.println(ax);  // Send X-axis acceleration
  delay(100);
}
```

## Troubleshooting

1. **Serial Port Issues**:
   - Check Device Manager (Windows) or `ls /dev/tty*` (Linux/Mac)
   - Ensure correct baud rate (9600)
   - Verify Arduino is connected and running

2. **Data Reading Problems**:
   - Check Arduino serial output in Serial Monitor first
   - Ensure data is sent as integers followed by newline
   - Verify sensor wiring and power supply

3. **Permission Issues** (Linux/Mac):
   ```bash
   sudo usermod -a -G dialout $USER
   sudo chmod 666 /dev/ttyUSB0
   ```

4. **Import Errors**:
   ```bash
   pip install --upgrade matplotlib numpy pyserial
   ```

## File Output

- **CSV File**: `test_data_neu.csv` - Contains all recorded acceleration values
- **Format**: One value per line, space-delimited
- **Location**: Same directory as the Python script

## Educational Context

This code was developed for the Sensor Technology course (Kurs Sensorik) in Summer Semester 2020, focusing on practical implementation of sensor data acquisition and analysis.

## Author

Created by Hasham Muhammad  


