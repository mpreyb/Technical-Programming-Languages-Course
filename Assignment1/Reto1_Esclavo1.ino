/*
 * LENGUAJES TÉCNICOS DE PROGRAMACIÓN - RETO 1
 * CODIGO ESCLAVO 1
 * Nombre: Reto1_Esclavo1
 * Propósito: Comunicación I2C
 * @autor Maria Paula Rey B./Juan Esteban Ramirez
 * @version Arduino IDE 1.8.12  / Proteus 8.7
 */

#include <Wire.h> 

//Pines motor
const int in_1 = 6;   
const int in_2 = 5;

//Variable para enviar la distancia a un obstáculo detectado

void setup()
{
  Wire.begin(1);                   //Esclavo 1
  Wire.onReceive(receiveEvent);    // Configura el evento de recibir por I2C
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  stopM();   //Detener el motor
}

void loop(){
}

void receiveEvent(){
  while(Wire.available())     
  {
    int d2 = Wire.read();        //Almacenar los bytes recibidos como un int
    Serial.print("DISTANCE: ");
    Serial.print(d2);
    Serial.println(" CM");
    delay(500);

    if (d2 > 16)                //Si la distancia es mayor a 16cm
    {
      clockwiseM();
      } else if (d2 == 16){    //Si la distancia es igual a 16cm (mínima), se detiene y gira en dirección contraria
        stopM();
        delay(200);
        anclockwiseM();
        }else if (d2 < 16){     //Si la distancia es menor a 16cm, se detiene (por seguridad).
          stopM();
        }
  }
    Serial.println();           // Cámbia de línea en el Serial Monitor.
    delay(500);
}

//----------- FUNCIONES MOTOR ----------//
void stopM()                 //Detener
{
  digitalWrite(in_1,HIGH) ;
  digitalWrite(in_2,HIGH) ;
}

void clockwiseM()            //Dirección de las manecillas del reloj
{
  digitalWrite(in_1,HIGH) ;
  digitalWrite(in_2,LOW) ;
}

void anclockwiseM()          //Dirección contraria a las manecillas del reloj
{
  digitalWrite(in_1,LOW) ;
  digitalWrite(in_2,HIGH) ;
}
