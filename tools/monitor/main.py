import serial
import time
# Import from the subdirectory
from generated.data_pb2 import InfoMessagePacket

# --- Configuration ---
SERIAL_PORT = '/dev/ttyACM0' # Change to COMx on Windows
BAUD_RATE = 115200

def run_listener():
    try:
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=0.1)
        print(f"Listening on {SERIAL_PORT} at {BAUD_RATE}...")

        while True:
            if ser.in_waiting > 0:
                raw_payload = ser.read(ser.in_waiting)

                try:
                    msg = InfoMessagePacket()
                    msg.ParseFromString(raw_payload)
                    print(f"[{time.strftime('%H:%M:%S')}] Received Name: {msg.name}")

                except Exception as e:
                    pass # Probaby from compiling

            time.sleep(0.01)

    except serial.SerialException as e:
        print(f"Serial Error: {e}")
    except KeyboardInterrupt:
        print("\nStopping listener...")
    finally:
        if 'ser' in locals() and ser.is_open:
            ser.close()

if __name__ == "__main__":
    run_listener()