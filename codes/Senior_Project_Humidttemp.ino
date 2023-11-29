#include <dht11.h>
#define DHT11PIN 4

int HUM = 8;
int TEMP = 9;
int tempMax = 20;
int HumMin = 30;


dht11 DHT11;
void  setup()
{
  Serial.begin(9600);
pinMode (HUM,OUTPUT);
pinMode (TEMP,OUTPUT);
 }

void loop()
{
  Serial.println();

  int chk = DHT11.read(DHT11PIN);

  Serial.print(" Humidty : ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print(" Temperature : ");
  Serial.println((float)DHT11.temperature, 2);
 

if (DHT11.humidity <= 60) {
   digitalWrite (HUM,HIGH);//humidty Output
}else digitalWrite (HUM,LOW);{
  }
   if (DHT11.temperature >= 25) {
  digitalWrite (TEMP,HIGH);//temp Output
  } else digitalWrite (TEMP,LOW);
  
delay(60000);
}
