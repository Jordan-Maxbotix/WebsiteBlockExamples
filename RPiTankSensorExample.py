import serial

ser = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)

data = ser.read_until(b'\r')    #Read the next range reading; We do this to syncronize with the end of the range cycle
ser.write(b'T')                 #Send the command (In this case, the teach command)
data = ser.read_until(b'\r')    #Read the response

if data == b'Teach Complete\r':
    print("Command successful!")
else:
    print("Command failed!")