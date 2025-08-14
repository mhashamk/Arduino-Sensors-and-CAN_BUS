# -*- coding: utf-8 -*-
# Created on Thu Mar 30 18:15:07 2023
# Author: Hasham Muhammad
# Sample code for bus systems lab
# pip install canalystii

import canalystii
import numpy as np
import serial

# Initialize serial communication (update 'COM8' and baudrate as per your setup)
ser = serial.Serial('COM8', baudrate=9600)

# Connect to the Canalyst-II device (bitrate of 500000 for CAN bus communication)
dev = canalystii.CanalystDevice(bitrate=500000)

# Receive all pending messages on channel 0 / clear buffer
for msg in dev.receive(0):
    print(msg)

# Define the maximum number of sensor values to record
max_values = 100
data = []
x = np.arange(0, max_values, 1)

# Collect sensor data and send via CAN
for n in range(max_values):
    ser_bytes = ser.readline()
    try:
        decoded_bytes = int(ser_bytes.decode("utf-8").strip())
        print(decoded_bytes)
        data.append(decoded_bytes)
        pl = (decoded_bytes, decoded_bytes, decoded_bytes, decoded_bytes,
              decoded_bytes, decoded_bytes, decoded_bytes, decoded_bytes)
        new_message = canalystii.Message(can_id=0x7ac,
                                         remote=False,
                                         extended=False,
                                         data_len=8,
                                         data=pl)
        dev.send(1, new_message)
    except ValueError:
        print("Invalid data received")

# Receive and process CAN messages
for msg in dev.receive(1):
    try:
        received_data = msg.data
        received_value = int(received_data[0])
        if received_value in data:
            print(f"Received value: {received_value} matches sent data.")
    except Exception as e:
        print(f"Error processing received message: {e}")

# Stop both channels
dev.stop(0)
dev.stop(1)
del dev
ser.close()
