
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Libreria DHT
#include <DHT.h>
// Definición del pin y tipo del sensor DHT
#define Type DHT11
int DHTPin = 7;
// Objeto del sensor DHT
DHT dht(DHTPin, Type);

// Lectura de temperatura y humedad del sensor DHT
float humidity = dht.readHumidity();
float tempC = dht.readTemperature();
float tempF = dht.readTemperature(true);
// Un delay
int dt = 500;

void setup() {

  // Inicializar pantalla LCD
  lcd.begin(16, 2);
  Wire.begin();
  lcd.init();       // Inicializar el display LCD
  lcd.backlight();  // Encender la luz de fondo

  // Comenzamos el sensor DHT
  dht.begin();
  pinMode(DHTPin, INPUT);
  //Monitor Serial
  Serial.begin(9600);
}

void loop() {
  Serial.println(tempC);

  lcd.setCursor(0, 0);
  lcd.print(tempC);
  delay(dt);
}
