import serial
import time
import os

try:
    arduino = serial.Serial(port='COM6', baudrate=9600, timeout=1)
    time.sleep(2)

    # NEW: Clear buffer so "Arduino Ready." does not get read as a response
    arduino.reset_input_buffer()

    while True:
        os.system('cls')
        print("--------------------------------")
        print(" Arduino Python Controller")
        print("--------------------------------")
        print("[R] Red ON/OFF")
        print("[G] Green ON/OFF")
        print("[B] Blue ON/OFF")
        print("[A] All ON")
        print("[V] Violet ONv")
        print("[O] All OFF")
        print("[X] Exit")
        print("--------------------------------")
        
        user_input = input("Enter Choice: ").upper()
        
        if not user_input:
            continue
        
        if user_input == 'X':
            print("Exiting application...")
            break
        
        elif user_input in ['R', 'G', 'B', 'A', 'O', 'V']:
            arduino.write(user_input.encode())
            time.sleep(0.15)

            # Read correct Arduino response
            action = arduino.readline().decode().strip()

            if action:
                print(f"Action: {action}")
            else:
                print("No response from Arduino.")

            time.sleep(1)

        else:
            print(f"Command {user_input} is not a valid choice!!")
            time.sleep(1)

except serial.SerialException as e:
    print(f"Serial exception: {e}")
except Exception as ex:
    print(f"Unexpected error: {ex}")
