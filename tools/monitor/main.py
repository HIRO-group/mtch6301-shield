import serial
import time
import os
import sys

generated_path = os.path.join(os.path.dirname(__file__), 'generated')
sys.path.append(generated_path)

from generated.common_pb2 import Envelope

SERIAL_PORT = '/dev/ttyACM0' 
BAUD_RATE = 115200

def run_listener():
    try:
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=0.1)
        print(f"Listening on {SERIAL_PORT}...")

        while True:
            if ser.in_waiting > 0:
                raw_payload = ser.read(ser.in_waiting)

                try:
                    env = Envelope()
                    env.ParseFromString(raw_payload)

                  
                    active_field = env.WhichOneof("payload")

                    if active_field == "info_packet":
                        print(f"[{time.strftime('%H:%M:%S')}] INFO: {env.info_packet.name}")
                    
                    elif active_field == "sensor_packet": # Assuming you add this later
                        print(f"[{time.strftime('%H:%M:%S')}] SENSOR: {env.sensor_packet.value}")
                    
                    elif active_field is None:
                        print("Received an empty envelope.")

                except Exception as e:
                    # print(f"Decode error: {e}")
                    pass

            time.sleep(0.01)

    except serial.SerialException as e:
        print(f"Serial Error: {e}")
    except KeyboardInterrupt:
        print("\nStopping...")
    finally:
        if 'ser' in locals() and ser.is_open:
            ser.close()

if __name__ == "__main__":
    run_listener()