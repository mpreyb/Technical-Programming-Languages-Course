# -*- coding: utf-8 -*-
"""
Created on Fri Nov 13 12:22:27 2020

@author: Ramirez,Rey,Moreno
"""

import serial
import time
import collections
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib.lines import Line2D
import numpy as np


def getSerialData(self,Samples,numData,serialConnection, lines):
    for i in range(numData):
        value  = float(serialConnection.readline().strip())  #Leer sensor / Read sensor
        data[i].append(value) #Guarda lectura en la última posición / #Save reading in the end position
        lines[i].set_data(range(Samples),data[i]) # Dibujar nueva linea / Drawn new line

        
serialPort = 'COM2' # Puerto serial arduino / Arduino serial port

try:
  serialConnection = serial.Serial(serialPort, 9600) # Instanciar objeto Serial / Instance Serial Object
except:
  print('Cannot conect to the port')

Samples = 10  #Muestras / Samples
sampleTime = 100  #Tiempo de muestreo / Sample Time
numData = 1


# Limites de los ejes / Axis limit
xmin = 0
xmax = Samples
ymin = [0, 0 , 0, 0, 0]
ymax = [1000, 1000 , 1000 , 1000, 100]
lines = []
data = []

for i in range(numData):
    data.append(collections.deque([0] * Samples, maxlen=Samples))
    lines.append(Line2D([], [], color='blue'))
  
fig = plt.figure()# Crea una nueva figura #Create a new figure.
ax1 = fig.add_subplot(3, 2, 1,xlim=(xmin, xmax), ylim=(ymin[0] , ymax[0]))
ax1.title.set_text('Sensor 1')
ax1.set_xlabel("Samples")
ax1.set_ylabel("Distancia [cm]")
ax1.add_line(lines[0])

# ax2 = fig.add_subplot(3, 2, 2,xlim=(xmin, xmax), ylim=(ymin[1] , ymax[1]))
# ax2.title.set_text('Sensor 2')
# ax2.set_xlabel("Samples")
# ax2.set_ylabel("Distancia [cm]")
# ax2.add_line(lines[1])

# ax3 = fig.add_subplot(3, 2, 3,xlim=(xmin, xmax), ylim=(ymin[2] , ymax[2]))
# ax3.title.set_text('Sensor 3')
# ax3.set_xlabel("Samples")
# ax3.set_ylabel("Distancia [cm]")
# ax3.add_line(lines[2])

# ax4 = fig.add_subplot(3, 2, 4,xlim=(xmin, xmax), ylim=(ymin[3] , ymax[3]))
# ax4.title.set_text('Sensor 4')
# ax4.set_xlabel("Samples")
# ax4.set_ylabel("Distancia [cm]")
# ax4.add_line(lines[3])

# ax5 = fig.add_subplot(3, 2, 5,xlim=(xmin, xmax), ylim=(ymin[4] , ymax[4]))
# ax5.title.set_text('Corriente')
# ax5.set_xlabel("Samples")
# ax5.set_ylabel("Amperios [mA]")
# ax5.add_line(lines[4])


    
anim = animation.FuncAnimation(fig,getSerialData, fargs=(Samples,numData,serialConnection,lines), interval=sampleTime)
plt.show()

serialConnection.close() # cerrar puerto serial/ close serial port
 
