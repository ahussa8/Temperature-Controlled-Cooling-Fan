#include <DHT.h>

#define ENABLE 5
#define DIRA 3
#define DIRB 4
#define LED_BLUE_PIN 6
#define LED_GREEN_PIN 9
#define LED_RED_PIN 11
#define DHTPIN 10
#define DHTTYPE DHT11
#define ROOM_TEMP_THRESHOLD_F 85.0
#define SLIGHTLY_HIGH_THRESHOLD_F 88.0

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, LOW);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  if (f < ROOM_TEMP_THRESHOLD_F) {
    setColor(0, 0, 255);
    analogWrite(ENABLE, 0);
    Serial.print("Temp: ");
    Serial.print(f);
    Serial.println("F Room Temperature (Blue), Motor OFF");
  } else if (f < SLIGHTLY_HIGH_THRESHOLD_F) {
    setColor(255, 255, 0);
    analogWrite(ENABLE, 128);
    Serial.print("Temp: ");
    Serial.print(f);
    Serial.println("F Slightly Higher (Yellow), Motor ~50%");
  } else {
    setColor(255, 0, 0);
    analogWrite(ENABLE, 255);
    Serial.print("Temp: ");
    Serial.print(f);
    Serial.println("F High Temperature (Red), Motor FULL");
  }
  delay(2000);
}

void setColor(byte red, byte green, byte blue) {
  analogWrite(LED_RED_PIN, red);
  analogWrite(LED_GREEN_PIN, green);
  analogWrite(LED_BLUE_PIN, blue);
}