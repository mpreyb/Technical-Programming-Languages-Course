int data;
int pasos_2=11;
int dir_2=10;
int pasos_1=9;
int dir_1=8;
int iman=12;

void setup() 
{
Serial.begin(9600);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
pinMode(iman,OUTPUT);
}

void loop() 
{
   if (Serial.available()> 0)
  {
    data = Serial.read();
  }
   if (data == '1')
    {
        digitalWrite(dir_1, LOW);
        for(int x = 0; x <= 1; x++)
        {
          digitalWrite(pasos_1,HIGH);
          delay(50);
          digitalWrite(pasos_1,LOW);
          delay(50);
        }
       data='6';
    }
   if (data == '0')
    {
        digitalWrite(dir_1, HIGH);
        for(int x = 0; x <= 1; x++)
        {
          digitalWrite(pasos_1,HIGH);
          delay(50);
          digitalWrite(pasos_1,LOW);
          delay(50);
        }
       data='6';
    }
   if (data == '2')
   {
        digitalWrite(dir_2, LOW);
        for(int x = 0; x <= 1; x++)
        {
          digitalWrite(pasos_2,HIGH);
          delay(50);
          digitalWrite(pasos_2,LOW);
          delay(50);
        }
       data='6';
   }
  if (data == '3')
   {
        digitalWrite(dir_2, HIGH);
        for(int x = 0; x <= 1; x++)
        {
          digitalWrite(pasos_2,HIGH);
          delay(50);
          digitalWrite(pasos_2,LOW);
          delay(50);
        }
       data='6';
   }
  if (data == '4')
   {
    digitalWrite (12, HIGH);
    Serial.println(digitalRead(13));
   }

 if (data == '5')
 {
    digitalWrite(dir_1, LOW);
    for(int x = 0; x <= 60; x++)
    {
      digitalWrite(pasos_1,HIGH);
      delay(50);
      digitalWrite(pasos_1,LOW);
      delay(50);
    }
    digitalWrite(dir_2, LOW);
    for(int x = 0; x <= 45; x++)
    {
      digitalWrite(pasos_2,HIGH);
      delay(50);
      digitalWrite(pasos_2,LOW);
      delay(50);
    }
       data='6';
 }

 if (data == '6')
 {
  digitalWrite(pasos_1,LOW);
  digitalWrite(pasos_2,LOW);
 }

}
