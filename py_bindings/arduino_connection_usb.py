import py_controller_binding 
import serial

ser = serial.Serial('/dev/ttyUSB0',9600)
s = [0,1]

controller = py_controller_binding.controller(0.1, 0.1, 0.1, 0.1, 0.1)
print(controller.GetError())

while True:
    read_serial=ser.readline().strip()
    values = read_serial.decode('ascii').split(',')
    a = [float(s) for s in values]
    print(a)
