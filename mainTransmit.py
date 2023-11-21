from XInput import *

import serial
import struct
import serial.tools.list_ports
import threading
import cv2
import time
import atexit


def connetc_COM(ser_number, baudrate):
    ports = list(serial.tools.list_ports.comports())
    serial_number = ser_number
    for p in ports:
        if serial_number == p.serial_number:
            return serial.Serial(p.device, baudrate)
    print("NO DEVICE FOUND")


speed_L = 0
speed_R = 0
Top = 0
Mid = 0
Bot = 0
Crab = 0
LED = 0



# CONTROL by two sticks and NO letter_button - 0..250 (TURBO = 25), A - 0..500(TURBO = 50), Y - 0..1000(TURBO = 100)
# Create the handler and set the events functions
class MyHandler(EventHandler):
    def process_button_event(self, event):
        global Top
        if event.button == "LEFT_THUMB":
            print()
        elif event.button == "RIGHT_THUMB":
            print()
        elif event.button == "LEFT_SHOULDER":
            print()
        elif event.button == "RIGHT_SHOULDER":
            print()
        elif event.button == "BACK":
            print()
        elif event.button == "START":
            print()
        elif event.button == "DPAD_LEFT":
            print()
        elif event.button == "DPAD_RIGHT":
            print()
        elif event.button == "DPAD_UP":
            print()
        elif event.button == "DPAD_DOWN":
            print()
        elif event.button == "A":
            print("A")
        elif event.button == "B":
            Top = Top + 5
            print()
        elif event.button == "Y":
            global LED
            LED = 1
        elif event.button == "X":
            Top = Top - 5
            print()
    def process_stick_event(self, event):
        global speed_L, speed_R
        if event.stick == LEFT:
            speed_L = (event.y + 1)*128
        elif event.stick == RIGHT:
            speed_R = (event.y + 1)*128


    def process_trigger_event(self, event):
        global speed_L, speed_R, Mid, Top
        if event.trigger == LEFT:
            Mid = event.value * 180

        elif event.trigger == RIGHT:
            Top = event.value * 180

        #print(speed_L, "   ", speed_R, "   ")
    def process_connection_event(self, event):
        global speed
        if event.type == EVENT_CONNECTED:
            print()
        elif event.type == EVENT_DISCONNECTED:
            speed = 0
        else:
            print("Unrecognized controller event type")
def send_command(serial_port):
        global speed_L, speed_R, LED, Top, Mid, Bot, Crab
        array = bytearray(struct.pack("H", int(speed_L))) #левый борт
        array.extend(bytearray(struct.pack("H", int(speed_R))))
        array.extend(bytearray(struct.pack("H", int(Top))))
        array.extend(bytearray(struct.pack("H", int(Mid))))
        array.extend(bytearray(struct.pack("H", int(Bot))))
        array.extend(bytearray(struct.pack("H", int(Crab))))
        array.extend(bytearray(struct.pack("?", int(LED))))
        #format_str = '4s'
        #message = struct.unpack(format_str, array)[0].decode()
        serial_port.write(array)
        print(array)


def Exit_func(file):
    file.close()


if __name__ == "__main__":

    # INIT
    handler = MyHandler(0, 1, 2, 3)  # initialize Xbox controller handler object
    ser_holybro = connetc_COM('0001', 57600)
    #ser_bolid_rs232 = connetc_COM('R4841986051', 460800)
    #ser_bolid_rs485 = connetc_COM('Q6949935051', 115200)
    # ser_r2d2 = connetc_COM('FT2N0AMEA',921600)

    #data_file = open('data.csv', 'w')
    #writer = csv.writer(data_file)


    thread = GamepadThread(handler)  # initialize controller thread

    #atexit.register(Exit_func, data_file)

    while True:
        #ser_holybro = (message)
        send_command(ser_holybro)
        #ret, frame = cap.read()
        #cv2.imshow("preview", frame)
        #key = cv2.waitKey(20)
        #if key == 27:  # exit on ESC
        #    break
        time.sleep(0.1)

    thread.stop()

    # can run other stuff here
