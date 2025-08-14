# -*- coding: utf-8 -*-
"""
Created on Sun Mar 22 19:05:31 2020
@author: Hasham Muhammad
# Basisprogramm Spyder/Python für Lab 1
"""

import serial
import csv
import numpy as np
import matplotlib.pyplot as plt
# import time  # nur erforderlich, wenn ein Zeitstempel erzeugt werden soll

# Serial connection to Arduino
ser = serial.Serial('/dev/cu.usbserial-14430', 9600)
ser.flushInput()

max_readings = 100
daten = []
x = np.arange(0, max_readings, 1)

# Read serial data
for n in range(0, max_readings):
    ser_bytes = ser.readline()
    decoded_bytes = int(ser_bytes[0:len(ser_bytes)-1].decode("utf-8"))
    print(decoded_bytes)
    daten.append(decoded_bytes)
    
    # Save to CSV
    with open("test_data_11227.csv", "a", newline='') as f:
        writer = csv.writer(f, delimiter=" ")
        writer.writerow([decoded_bytes])
        # For timestamp: writer.writerow([time.time(), decoded_bytes])

# Plot the data
plt.figure(0)
plt.plot(x, daten)
plt.xlabel('Measurement Number')
plt.ylabel('Total time of flight in ms')

plt.figure(1)
a = np.hstack(daten)
plt.hist(a, bins='auto')
plt.show()

# Print mean value
print("Mittelwert: ")
print(np.mean(daten))

# Close serial connection
ser.close()
