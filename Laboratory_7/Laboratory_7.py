from fastapi import FastAPI, HTTPException
import serial
import time

app = FastAPI()
arduino = None

@app.get("/")
def root():
    return {"message": "Arduino Serial API is running."}

@app.on_event("startup")
def startup_event():
    global arduino
    try:
        arduino = serial.Serial('COM5', 9600, timeout=1)
        time.sleep(2)
        print("Serial connection established.")
    except serial.SerialException as e:
        print(f"Error establishing serial connection: {e}")

@app.on_event("shutdown")
def shutdown_event():
    global arduino
    if arduino and arduino.is_open:
        arduino.close()

@app.get("/led/on")
def turn_all_on():
    if arduino and arduino.is_open:
        arduino.write(b"on")
        return {"status": "success", "message": "All LED turned ON"}
    raise HTTPException(status_code=500, detail="Serial connection failed")

@app.get("/led/off")
def turn_all_off():
    if arduino and arduino.is_open:
        arduino.write(b"off")
        return {"status": "success", "message": "All LED turned OFF"}
    raise HTTPException(status_code=500, detail="Serial connection failed")

@app.get("/led/{color}")
def control_led(color: str):
    if arduino and arduino.is_open:
        cmd = color.strip().lower()
        match cmd:
            case "red":
                arduino.write(b"1")
                return {"color": "red", "sent": "1"}
            case "green":
                arduino.write(b"2")
                return {"color": "green", "sent": "2"}
            case "blue":
                arduino.write(b"3")
                return {"color": "blue", "sent": "3"}
            case _:
                raise HTTPException(status_code=400, detail="Invalid Command. Use red, green, blue, ON, or OFF")
    else:
        raise HTTPException(status_code=500, detail="Serial connection failed")