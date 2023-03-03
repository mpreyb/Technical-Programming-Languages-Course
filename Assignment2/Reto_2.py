# -*- coding: utf-8 -*-
"""
Created on Tue Oct 13 10:00:17 2020

@author: Juan Esteban Ramirez
"""
from tkinter import *
import serial
import time

ArduinoSerial = serial.Serial('com2', 9600, timeout=.1)
time.sleep(2)


status1 = 0


def subir():
    global status1
    ArduinoSerial.write(b'1')
    status1 = (ArduinoSerial.readline() )

def bajar():
    global status1
    ArduinoSerial.write(b'0')
    status1 = (ArduinoSerial.readline() )

def izq():
    global status1
    ArduinoSerial.write(b'2')
    status1 = (ArduinoSerial.readline() )
def der():
    global status1
    ArduinoSerial.write(b'3')
    status1 = (ArduinoSerial.readline() )
def iman():
    global status1
    ArduinoSerial.write(b'4')
    status1 = (ArduinoSerial.readline() )
def mov1():
    global status1
    ArduinoSerial.write(b'5')
    status1 = (ArduinoSerial.readline())
    
root = Tk()
root.title("Control de la grua")
btn1 = Button(root, text="Subir", command= subir)
btn2 = Button(root, text="Bajar", command= bajar)
btn3 = Button(root, text="Izquierda", command=izq)
btn4 = Button(root, text="Derecha", command=der)
btn5 = Button(root, text="Iman", command=iman)
btn6 = Button(root, text="Mov 1", command=mov1)
btn1.pack()
btn2.pack(side = BOTTOM)
btn3.pack(side = LEFT)
btn4.pack(side = RIGHT)
btn5.pack()
btn6.pack()
root.mainloop()