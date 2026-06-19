import serial
import sqlite3
from datetime import datetime

# Conexión a la base de datos
conn = sqlite3.connect('telemetry.db')
cursor = conn.cursor()
cursor.execute('''CREATE TABLE IF NOT EXISTS telemetry_logs 
                  (timestamp TEXT, humidity REAL, temperature REAL)''')

ser = serial.Serial('/dev/serial0', 9600)

print("Sistema de persistencia iniciado...")

try:
    while True:
        if ser.in_waiting > 0:
            data = ser.readline().decode('utf-8').strip()
            # Supongamos formato H:XX.X,T:XX.X
            try:
                parts = data.split(',')
                h = parts[0].split(':')[1]
                t = parts[1].split(':')[1]
                
                # Guardar en DB
                cursor.execute("INSERT INTO telemetry_logs VALUES (?,?,?)", 
                               (datetime.now().strftime("%Y-%m-%d %H:%M:%S"), h, t))
                conn.commit()
                print(f"Dato registrado: H={h}, T={t}")
            except:
                print("Error de formato en trama")
except KeyboardInterrupt:
    conn.close()
