int tiempo; 
int distancia;
int tiempo2; 
int distancia2;
int tiempo3; 
int distancia3;
int tiempo4; 
int distancia4;
int vecDist[4];

int Trig1=35; 
int Echo1=34; //Sensor delantero derecho

int Trig2=37; 
int Echo2=36; //Sensor delantero izquierdo

int Trig3=33; 
int Echo3=32; //Sensor tracero izquierdo

int Trig4=31; 
int Echo4=30; //Sensor tracero derecho

int Mdd_pwm=8;
int Mdd_dir0=24;
int Mdd_dir1=25;

int Mdi_pwm=9;
int Mdi_dir0=22;
int Mdi_dir1=23;

int Mtd_pwm=6;
int Mtd_dir0=28;
int Mtd_dir1=29;

int Mti_pwm=7;
int Mti_dir0=26;
int Mti_dir1=27;

void setup() 
{
  Serial.begin(9600);
  pinMode(Echo1,INPUT);
  pinMode(Trig1,OUTPUT); 
  pinMode(Echo2,INPUT);
  pinMode(Trig2,OUTPUT); 
  pinMode(Echo3,INPUT);
  pinMode(Trig3,OUTPUT); 
  pinMode(Echo4,INPUT);
  pinMode(Trig4,OUTPUT); 

  pinMode(Mdd_dir0,OUTPUT);
  pinMode(Mdd_dir1,OUTPUT);
  pinMode(Mdi_dir0,OUTPUT);
  pinMode(Mdi_dir1,OUTPUT);
  pinMode(Mtd_dir0,OUTPUT);
  pinMode(Mtd_dir1,OUTPUT);
  pinMode(Mti_dir0,OUTPUT);
  pinMode(Mti_dir1,OUTPUT);
}
void loop() 
{
//Sensor 1 
digitalWrite(Trig1,HIGH);
delayMicroseconds(1);
digitalWrite(Trig1,LOW); 
tiempo=pulseIn(Echo1,HIGH);
distancia=(tiempo*0.03432)/2;
//Sensor 2
digitalWrite(Trig2,HIGH);
delayMicroseconds(1);
digitalWrite(Trig2,LOW); 
tiempo2=pulseIn(Echo2,HIGH);
distancia2=(tiempo2*0.03432)/2;
//Sensor 3
digitalWrite(Trig3,HIGH);
delayMicroseconds(1);
digitalWrite(Trig3,LOW); 
tiempo3=pulseIn(Echo3,HIGH);
distancia3=(tiempo3*0.03432)/2;
//Sensor 4
digitalWrite(Trig4,HIGH);
delayMicroseconds(1);
digitalWrite(Trig4,LOW); 
tiempo4=pulseIn(Echo4,HIGH);
distancia4=(tiempo4*0.03432)/2;
//asignar data
vecDist[0]=distancia;
vecDist[1]=distancia2;
vecDist[2]=distancia3;
vecDist[3]=distancia4;
//Send data
Serial.println(vecDist[0]);
Serial.println(vecDist[1]);
Serial.println(vecDist[2]);
Serial.println(vecDist[3]);
//Movimiento
if (distancia >= 20 && distancia2 >= 20)
{
  digitalWrite(Mtd_dir0,LOW);
  digitalWrite(Mtd_dir1,HIGH); 
                                    //Motores traseros On siempre que la distancia sea mayor a 10cm
  digitalWrite(Mti_dir0,LOW);
  digitalWrite(Mti_dir1,HIGH);

  digitalWrite(Mdi_dir0,LOW);
  digitalWrite(Mdi_dir1,LOW);

  digitalWrite(Mdd_dir0,LOW);
  digitalWrite(Mdd_dir1,LOW);

  analogWrite(Mtd_pwm,map(60,0,100,0,255));
  analogWrite(Mti_pwm,map(60,0,100,0,255));

  
}

if (distancia < 20 || distancia2 < 20)
{
  digitalWrite(Mtd_dir0,LOW);
  digitalWrite(Mtd_dir1,HIGH); 
                                    //Motores traseros On pero con menos velocidad, PWM al 20%
  digitalWrite(Mti_dir0,LOW);
  digitalWrite(Mti_dir1,HIGH);

  analogWrite(Mtd_pwm,map(20,0,100,0,255));
  analogWrite(Mti_pwm,map(20,0,100,0,255));

  if(distancia < 20)
  {
    digitalWrite(Mdd_dir0,LOW);
    digitalWrite(Mdd_dir1,HIGH);
    digitalWrite(Mdi_dir0,LOW);
    digitalWrite(Mdi_dir1,LOW);
                              //Motores delantero derecho On a toda capacidad para girar evadiendo el obstaculo
    analogWrite(Mdd_pwm,map(60,0,100,0,255));
  }

    if(distancia2 < 20)
  {
    digitalWrite(Mdi_dir0,LOW);
    digitalWrite(Mdi_dir1,HIGH);
    digitalWrite(Mdd_dir0,LOW);
    digitalWrite(Mdd_dir1,LOW); 
                              //Motores delantero izquierdo On a toda capacidad para girar evadiendo el obstaculo
    analogWrite(Mdi_pwm,map(60,0,100,0,255));
  }

}
}
