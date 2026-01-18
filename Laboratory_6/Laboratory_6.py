import serial
import time

# Adjust COM port as needed (e.g., 'COM3' or '/dev/ttyUSB0')
arduino = serial.Serial(port='COM5', baudrate=9600, timeout=1)

time.sleep(2)  # Allow Arduino reset

print("Python Serial Listener Started")

while True:
    if arduino.in_waiting > 0:
        data = arduino.readline().decode().strip().upper()

        if data == 'R':
            arduino.write(b'1')
            print("Received R → Sent 1")

        elif data == 'G':
            arduino.write(b'2')
            print("Received G → Sent 2")

        elif data == 'B':
            arduino.write(b'3')
            print("Received B → Sent 3")