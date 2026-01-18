import serial
import requests
import time

# ================= CONFIGURATION =================
SERIAL_PORT = "COM5"              # Change as needed
BAUD_RATE = 9600
API_BASE_URL = "BASE_API"
GROUP_NUMBER = "1"                # Logical mapping for Button 1
# ================================================


def main():
    try:
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
        print("Listening to Arduino on", SERIAL_PORT)
    except serial.SerialException as e:
        print("Serial connection error:", e)
        return

    while True:
        try:
            line = ser.readline().decode("utf-8").strip()

            if not line:
                continue

            normalized = line.lower()

            # Validate expected Arduino message
            if normalized == "button 1 pressed":
                endpoint = f"/led/group/{GROUP_NUMBER}/toggle"
                url = API_BASE_URL + endpoint

                print("Group number received:", GROUP_NUMBER)
                print("Endpoint called:", endpoint)

                try:
                    response = requests.get(url, timeout=5)

                    if response.status_code == 200:
                        print("API response: SUCCESS")
                    else:
                        print("API response: ERROR (Status Code:", response.status_code, ")")

                except requests.RequestException as api_error:
                    print("API response: ERROR (Request failed)")
                    print(api_error)

            else:
                print("Invalid serial input received:", line)

        except Exception as e:
            print("Runtime error:", e)
            time.sleep(1)