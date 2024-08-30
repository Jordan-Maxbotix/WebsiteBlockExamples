import serial

ser = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)

while True:
    data = ser.read_until(b'\r')
    try:
        range = data[1:-1] #Don't include the first and last character ('R' and '\r')
        range = int(range)
        print(range)
    except:
        print("Error decoding value!")