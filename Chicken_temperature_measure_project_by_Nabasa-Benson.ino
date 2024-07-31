#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11Pin 14
#define GreenLEDPin 25
#define yelloyLEDPin 26
#define redLEDPin 27 
#define BuzzerPin 33

void setup(){
  Serial.begin(115200);
  pinMode(BuzzerPin, OUTPUT);
  pinMode(GreenLEDPin, OUTPUT);
  pinMode(yelloyLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  digitalWrite(redLEDPin, LOW);
  digitalWrite(yelloyLEDPin, LOW);
  digitalWrite(GreenLEDPin, LOW);
  digitalWrite(BuzzerPin, HIGH);
  delay(500);
  digitalWrite(BuzzerPin, LOW);
  delay(500);
  digitalWrite(BuzzerPin, HIGH);
  delay(500);
  digitalWrite(BuzzerPin, LOW);
}

void loop(){
  DHT.read(DHT11Pin);
  Serial.print("temp:");
  Serial.print(DHT.temperature);
  Serial.print("  humi:");
  Serial.println(DHT.humidity);
  if(DHT.temperature > 27){
    digitalWrite(redLEDPin, HIGH);
  digitalWrite(yelloyLEDPin, LOW);
  digitalWrite(GreenLEDPin, LOW);
    digitalWrite(BuzzerPin, HIGH);
    delay(250);
    digitalWrite(BuzzerPin, LOW);
    delay(250);
  }
  if(DHT.temperature <= 24){
    digitalWrite(GreenLEDPin, HIGH);
  digitalWrite(redLEDPin, LOW);
  digitalWrite(yelloyLEDPin, LOW);
    digitalWrite(BuzzerPin, HIGH);
    delay(1000);
    digitalWrite(BuzzerPin, LOW);
    delay(5000);
  }
  if(DHT.temperature > 24 && DHT.temperature < 28){
    digitalWrite(yelloyLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(GreenLEDPin, LOW);
    digitalWrite(BuzzerPin, HIGH);
    delay(500);
    digitalWrite(BuzzerPin, LOW);
    delay(250);
    digitalWrite(BuzzerPin, HIGH);
    delay(500);
    digitalWrite(BuzzerPin, LOW);
    delay(500);
  }
  delay(500);
}
