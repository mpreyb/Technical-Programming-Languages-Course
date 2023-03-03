/*
 * LENGUAJES TÉCNICOS DE PROGRAMACIÓN - RETO 1
 * CODIGO ESCLAVO 2
 * Nombre: Reto1_Esclavo2
 * Propósito: Comunicación I2C
 * @autor Maria Paula Rey B./Juan Esteban Ramirez
 * @version Arduino IDE 1.8.12  / Proteus 8.7
 */
 
#include <Wire.h> 
#include <LiquidCrystal.h>

//Declarar de pines de pantalla LCD
const int rs = 23, en = 24, d4 = 25, d5 = 26, d6 = 27, d7 = 28;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int tempC;     //Variable para guardar la temperatura recibida

//Pines para los LEDs
int G2=4;
int R2=3;

void loop(){
}

void setup()
{
    pinMode(4, OUTPUT);
    pinMode(3, OUTPUT);
    Wire.begin(2);                     //Nos conectamos al bus de i2c con la direccion 2
    Wire.onReceive(receiveEvent);      // Configura el evento de recibir por I2C
    Serial.begin(9600);
    lcd.begin(16, 4);                  //Inicializar pantalla LCD
}

void receiveEvent()
{
  while(Wire.available())     
  {
    int tempC = Wire.read();          //Almacenar los bytes (temperatura) recibidos como un int
    Serial.print("TEMPERATURE: ");
    Serial.print(tempC);
    Serial.println(" C");
    delay(500);

     if (tempC >= 38)                 //Si la temperatura es mayor a 38°C
      {
        //LED rojo encendido
        digitalWrite(4,LOW);
        digitalWrite(3,HIGH);

        //Mostrar mensaje en la pantalla LCD
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Temperatura");
        lcd.setCursor(0,1);
        lcd.print("alta");
        }
        else {
          //LED verde encendido
          digitalWrite(4,HIGH);
          digitalWrite(3,LOW);

          //Mostrar mensaje en la pantalla LCD
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Temperatura");
          lcd.setCursor(0,1);
          lcd.print("normal");
          }
  }
    Serial.println();       // Cámbia de línea en el Serial Monitor.
    delay(500);
}
