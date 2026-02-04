import serial
import time
import os
import sys
import threading

generated_path = os.path.join(os.path.dirname(__file__), 'generated')
sys.path.append(generated_path)

from generated.common_pb2 import Data, Command

SERIAL_PORT = '/dev/ttyACM0' 
BAUD_RATE = 115200

class SerialMonitor:
    def __init__(self):
        self.ser = None
        self.running = True

    def send_command(self):
        while self.running:
            try:
                user_input = input("> ").strip().lower()
                
                if user_input == 'exit':
                    self.running = False
                    break
                
                if user_input == 'test':
                    cmd = Command()
                    cmd.test_command.SetInParent() 
                    
                    serialized_data = cmd.SerializeToString()
                    
                    length_prefix = len(serialized_data).to_bytes(2, byteorder='little')
                    
                    if self.ser and self.ser.is_open:
                        self.ser.write(length_prefix + serialized_data)
                        print(f"Sent: TestCommand ({len(serialized_data)} bytes)")
                
            except Exception as e:
                print(f"Error sending: {e}")

    def listen(self):
        while self.running:
            try:
                if not self.ser or not self.ser.is_open:
                    self.ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=0.1)
                    print(f"[{time.strftime('%H:%M:%S')}] Connected")

                header = self.ser.read(2)
                if len(header) < 2:
                    continue

                msg_len = int.from_bytes(header, byteorder='little')
                raw_payload = self.ser.read(msg_len)

                if len(raw_payload) < msg_len:
                    continue

                data = Data()
                data.ParseFromString(raw_payload)
                active_field = data.WhichOneof("payload")

                if active_field == "info_packet":
                    print(f"\r[{time.strftime('%H:%M:%S')}] INFO: {data.info_packet.message}\n> ", end="")

            except (serial.SerialException, OSError):
                print(f"\n[{time.strftime('%H:%M:%S')}] Connection lost. Retrying...")
                time.sleep(5)
            except Exception as e:
                pass

    def start(self):
        listener_thread = threading.Thread(target=self.listen, daemon=True)
        listener_thread.start()
        
        self.send_command()

if __name__ == "__main__":
    monitor = SerialMonitor()
    monitor.start()