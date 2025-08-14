# Soil Moisture Logger

This Python script processes and visualizes soil moisture sensor data by converting raw voltage measurements to coverage percentages. It creates a characteristic curve showing the relationship between physical coverage depth and sensor response.

## Features

- Voltage to percentage conversion
- Characteristic curve visualization
- Calibration-based measurements
- Professional plotting with grid and labels

## Requirements

### Software Dependencies

Install the required Python package:

```bash
pip install matplotlib
```

## Sensor Calibration

The script uses pre-calibrated voltage values:
- **V_0 (0% coverage)**: 2.83V - Sensor in air/dry condition
- **V_100 (100% coverage)**: 1.60V - Sensor fully covered/wet condition

## Data

The script processes the following measurement data:

| Coverage (cm) | Sensor Voltage (V) | Coverage (%) |
|---------------|-------------------|--------------|
| 1             | 2.18              | 52.85        |
| 2             | 2.11              | 58.54        |
| 3             | 2.05              | 63.41        |
| 4             | 1.97              | 69.92        |
| 5             | 1.89              | 76.42        |
| 6             | 1.84              | 80.49        |

## Usage

Run the script directly:

```bash
python "Soil Moisture Logger.py"
```

## How It Works

1. **Data Definition**: Raw voltage measurements at different coverage depths
2. **Calibration**: Uses known 0% and 100% voltage references
3. **Conversion**: Applies linear conversion formula:
   ```
   Coverage (%) = (V_0 - V_sensor) / (V_0 - V_100) × 100
   ```
4. **Visualization**: Creates a professional plot showing the characteristic curve
5. **Output**: Displays both raw sensor values and converted percentages

## Conversion Formula

The percentage conversion uses a linear interpolation:

```python
coverage_percentage = (V_0 - sensor_value) / (V_0 - V_100) * 100
```

Where:
- `V_0` = 2.83V (0% coverage baseline)
- `V_100` = 1.60V (100% coverage reference)
- `sensor_value` = Measured voltage

## Calibration Process

To recalibrate for your sensor:

1. **Measure V_0**: Record voltage when sensor is completely dry/in air
2. **Measure V_100**: Record voltage when sensor is fully submerged/covered
3. **Update constants**:
   ```python
   V_0 = your_dry_voltage     # e.g., 2.83
   V_100 = your_wet_voltage   # e.g., 1.60
   ```

## Output

The script generates:
- **Graph**: Coverage (cm) vs Coverage (%) characteristic curve
- **Console Output**: 
  - Raw sensor voltage values
  - Calculated coverage percentages

## Applications

This code is suitable for:
- Soil moisture monitoring systems
- Agricultural sensor networks
- Laboratory sensor characterization
- Educational demonstrations of sensor calibration

## Extending the Code

To adapt for real-time data logging:

```python
import serial
import time

# Add serial connection
ser = serial.Serial('COM8', 9600)

# Replace static data with real-time readings
while True:
    raw_voltage = float(ser.readline().decode().strip())
    coverage_pct = (V_0 - raw_voltage) / (V_0 - V_100) * 100
    print(f"Voltage: {raw_voltage}V, Coverage: {coverage_pct:.2f}%")
    time.sleep(1)
```

## Hardware Setup

Typical sensor setup:
- Soil moisture sensor (capacitive or resistive)
- ADC for voltage measurement
- Microcontroller (Arduino, ESP32, etc.)
- Power supply (3.3V or 5V depending on sensor)

## Troubleshooting

1. **Import Errors**:
   ```bash
   pip install --upgrade matplotlib
   ```

2. **Calibration Issues**:
   - Ensure sensor is completely dry for V_0 measurement
   - Ensure sensor is fully covered for V_100 measurement
   - Allow time for sensor readings to stabilize

3. **Negative Percentages**: Check if V_0 > measured voltage > V_100
