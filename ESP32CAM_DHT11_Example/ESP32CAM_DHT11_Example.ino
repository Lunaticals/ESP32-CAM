#include "DHT.h" // Biblioteca que contiene los parámetros de medición del sensor DHT

#define DHTPIN 12   // Definición de la variable que utilizaremos, bajo el PIN 12

#define DHTTYPE DHT11   // Definición del tipo de archivo

 
DHT dht(DHTPIN, DHTTYPE); // Definición de la función que recibe el pin de entrada y tipo de archivo

void setup() {
  Serial.begin(115200); // Selección de velocidad de conexión
  Serial.println(F("Prueba de conexion")); 

  /*
  La F permite decidir sobre en dónde 'vivirán' las cadenas de Strings que se compilen en el programa,
  es decir, si se ocupa la F() sobre un String, dicha cadena no será copiada a la RAM durante la ejecución del programa,
  sino que se mantendrá dentro de la MEMFLASH de la computadora, permitiendo mantener una mayor cantidad de
  RAM dinámica disponible a costa de menor espacio en MEMFLASH para código.
  */

  dht.begin();  // Inicio del sensor
}

void loop() {
  delay(2000); // Espera de tiempo para no perder información en lo que se inicia el sensor

  float t = dht.readTemperature();  // Temperatura en °C
  float f = dht.readTemperature(true); // Temperatura en °F
  
  if ( isnan(t) || isnan(f)) {
    Serial.println(F("No hay conexion")); // EN caso de no recibir mensaje, mandar mensaje
    return;
  }

 
  Serial.print(F("Temperatura en °C: "));  // Envío (como impresión) de temperatura °C al monitor serial
  Serial.print(t);
  Serial.print(F("\n"));
  Serial.print(F("Temperatura en °F: ")); // Envío (como impresión) de temperatura °F al monitor serial
  Serial.print(f);
  Serial.print(F("\n"));

  
}
