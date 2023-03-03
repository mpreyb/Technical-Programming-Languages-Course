/*
 * LENGUAJES TÉCNICOS DE PROGRAMACIÓN - RETO 1
 * CODIGO MAESTRO
 * Nombre: Reto1_Maestro
 * Propósito: Comunicación I2C
 * @autor Maria Paula Rey B./Juan Esteban Ramirez
 * @version Arduino IDE 1.8.12  / Proteus 8.7
 */
 
#include <Wire.h>

long tiempo=0;                        //Variable para el tiempo del pulso generado por el Echo del sensor
long d=0;                             //Variable para la distancia al obstáculo
int d2;                               //Variable para el envío de la distancia (en bytes)

//Pines sensor ultrasonico
int pinTrigger=7; 
int pinEcho=6;

//Pines LEDs
int G1=4;
int R1=3;


int tempdigital;                       //Variable para valor análogo de temperatura
int tempC;                             //Variable para almacenar valor digital de temperatura

void setup()
{
  pinMode(pinEcho,INPUT);
  pinMode(pinTrigger,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  //ESCLAVO 1
  digitalWrite(pinTrigger,LOW);                     //Se asegura un cero en el pin que se va a utilizar como Trigger
  delayMicroseconds(5);                             //Restardo de 5 microsegundo
  digitalWrite(pinTrigger,HIGH);                    //Se establece en alto el pin del trigger para comenzar el pulso de inicio del sensor
  delayMicroseconds(10);  
  digitalWrite(pinTrigger,LOW);                     //Se establece en bajo el pin del Trigger para terminar el pulso de inicio del sensor
  tiempo=pulseIn(pinEcho,HIGH);                     //Se inicia la función pulseIn para que mida el tiempo del pulso generado por el Echo del sensor
  d=tiempo*0.0343/2;                                //Calculo de distancia a la cual se encuentra el objeto
  d2=map(d,0,1023,0,200);                           //Se mapea el valor de d para ser enviado. Además, se limita el número de bytes
  Serial.print("DISTANCE: ");
  Serial.print(d2);
  Serial.println(" CM");

  if (d2 >= 16)                                     //Si la distancia es mayor a 16cm
   {
     digitalWrite(4,HIGH);                          //Encender LED verde
     digitalWrite(3,LOW);
   }
   else if (d2 < 16) {                              //Si la distancia es menor a 16cm
    digitalWrite(4,LOW);                            //Encender LED rojo
    digitalWrite(3,HIGH);
   }
   
  Wire.beginTransmission(1);                        // Transmite al dispositivo 1
  Wire.write(d2);                                   // Envia la variable d2      
  Wire.endTransmission();                           // Finaliza la transmision
  delay(200);
  
  //ESCLAVO 2
  tempdigital = analogRead(A1);                     //Leer valor de temperatura del sensor
  tempC = (tempdigital * 5.0)*100.0/ 1024.0;        //Convertir a un valor digital
  Serial.print("TEMPERATURA: ");
  Serial.print(tempC);
  Serial.println(" C");
  Serial.println();                                 //Cambiar de línea en terminal
  Wire.beginTransmission(2);                        //Transmite al dispositivo 2
  Wire.write(tempC);                                //Envia la variable tempC
  Wire.endTransmission();                           //Finaliza la transmisión
 }
