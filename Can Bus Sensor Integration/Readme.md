# CAN Bus Sensor Integration

This Python script demonstrates how to integrate sensor data with CAN (Controller Area Network) bus communication using the Canalyst-II device. It reads sensor data from a serial connection and transmits it over a CAN bus network.

## Features

- Serial communication with sensor devices
- CAN bus message transmission and reception
- Data validation and error handling
- Real-time sensor data processing

## Requirements

### Hardware
- Canalyst-II CAN bus analyzer/interface device
- Sensor connected via serial communication (e.g., Arduino with sensors)
- CAN bus network setup

### Software Dependencies

Install the required Python packages:

```bash
pip install canalystii numpy pyserial
```

## Configuration

Before running the script, update the following parameters:

1. **Serial Port Configuration**:
   ```python
   ser = serial.Serial('COM8', baudrate=9600)  # Windows
   # For Linux/Mac: ser = serial.Serial('/dev/ttyUSB0', baudrate=9600)
   ```

2. **CAN Bus Settings**:
   ```python
   dev = canalystii.CanalystDevice(bitrate=500000)  # 500 kbps CAN bitrate
   ```

3. **CAN Message Parameters**:
   ```python
   new_message = canalystii.Message(can_id=0x7ac,  # CAN identifier
                                    remote=False,
                                    extended=False,
                                    data_len=8,
                                    data=pl)
   ```

## Usage

1. Connect your Canalyst-II device to your computer
2. Connect your sensor device to the specified serial port
3. Ensure your CAN bus network is properly configured
4. Run the script:

```bash
python can_bus_sensor_integration.py
```

## How It Works

1. **Initialization**: Establishes serial communication and connects to the Canalyst-II device
2. **Buffer Clearing**: Clears any pending CAN messages on channel 0
3. **Data Collection**: Reads sensor values from the serial port (up to 100 values)
4. **CAN Transmission**: Sends each sensor value as a CAN message on channel 1
5. **Message Reception**: Receives and validates CAN messages
6. **Cleanup**: Properly closes all connections

## CAN Message Format

The script sends CAN messages with the following structure:
- **CAN ID**: 0x7AC
- **Data Length**: 8 bytes
- **Data**: Sensor value repeated 8 times in the payload

## Error Handling

- Invalid serial data is caught and logged
- CAN message processing errors are handled gracefully
- Proper resource cleanup is ensured

## Troubleshooting

1. **Serial Port Issues**: 
   - Verify the correct port name (COM port on Windows, /dev/tty* on Linux/Mac)
   - Check baud rate matches your sensor device

2. **CAN Bus Connection**:
   - Ensure Canalyst-II device is properly connected
   - Verify CAN bus bitrate matches your network configuration
   - Check termination resistors on the CAN bus

3. **Permission Issues** (Linux/Mac):
   ```bash
   sudo usermod -a -G dialout $USER  # Add user to dialout group
   sudo chmod 666 /dev/ttyUSB0       # Grant permissions to serial port
   ```

## Author

Created by Hasham Muhammad for Bus Systems Lab course.
