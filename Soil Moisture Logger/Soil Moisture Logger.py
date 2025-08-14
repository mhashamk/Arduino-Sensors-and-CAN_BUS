import matplotlib.pyplot as plt
# Data
x = [1, 2, 3, 4, 5, 6] # Coverage (cm)
y = [2.18, 2.11, 2.05, 1.97, 1.89, 1.84] # Sensor values
# Conversion parameters
V_0 = 2.83 # Voltage at 0% coverage
11
V_100 = 1.60 # Voltage at 100% coverage
# Convert sensor values to coverage percentages
coverage_percentages = [round((V_0 - value) / (V_0 - V_100) * 100, 2) for value in y]
# Plotting
plt.figure(figsize=(8, 5))
plt.plot(x, coverage_percentages, color='blue', marker='o', label='Data points')
plt.xlabel('Coverage (cm)')
plt.ylabel('Coverage (%)')
plt.title('Characteristic Curve: Coverage (cm) vs. Coverage (%)')
plt.grid()
plt.legend()
plt.tight_layout()
plt.show() # Print values
print("Sensor Values (y):", y)
print("Coverage Percentages:", coverage_percentages)