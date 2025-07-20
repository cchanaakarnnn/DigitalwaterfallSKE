import termios

import serial
import time

arduino_port = '/dev/cu.usbmodem11201'
baud_rate = 250000
SE = None

def setup_SE():
    global SE
    SE = serial.Serial(arduino_port, baud_rate)
    print(f'[theSerial] : PORT -> {arduino_port} | BAUD -> {baud_rate}')
    # time.sleep(0.1)  # Allow time for the connection to establish
    print('[theSerial] : Serial Ready')

def send_SE(message: str):
    try:
        if SE.is_open:
            SE.flush()
            SE.write(message.encode('utf-8'))
            # print('[theSerial] : sent')
        else:
            print("[theSerial] : Serial port closed, attempting to reopen")
            setup_SE()  # Attempt to reopen the serial port
    except:
        print(f"[theSerial] : OSError encountered")
        print("[theSerial] : Attempting to reinitialize serial connection")
        setup_SE()  # Reinitialize on error
        time.sleep(0.3)  # Give time for reconnection

        if SE.is_open: # resend
            SE.flush()
            SE.write(message.encode('utf-8'))
            # print('[theSerial] : sent')
        else:
            print("[theSerial] : Serial port closed, attempting to reopen")
            setup_SE()  # Attempt to reopen the serial port

def wait_for_response():
    while True:
        if SE.in_waiting > 0:
            response = SE.readline().decode('utf-8').strip()
            print('[theSerial] : received', response)
            break
        time.sleep(0.01)  # Check periodically

# Example usage
if __name__ == '__main__':
    setup_SE()
    send_SE("Hello Arduino")
