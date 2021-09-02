
import serial
import time

#nombre del dispositivo serial : dmesg | grep -v disconnect | grep -Eo "tty(ACM|USB)." | tail -1
#serial = serial.Serial('/dev/ttyACM0',9600)
serial.flushInput()

def iluminacion (line):
    if int(line) < 80:
        dato = "noche"
    else:
        dato = "dia"
    return dato

while True:
    try:
        lineBytes = serial.readline()
        line = str(lineBytes.decode('latin-1').strip())
        line = line.split(",")
        print(line[1])

        mensaje = iluminacion(int(float(line[1]))).encode('latin-1')
        serial.write(mensaje)
        time.sleep(0.5)

    except KeyboardInterrupt:
        break
