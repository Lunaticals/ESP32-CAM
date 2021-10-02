//ESP32CAM flash
//Por: Hugo Vargas
//24 de mayo de 2021
//Creditos Moayom
//
//Este es el programa básico para controlar el
//LED Flash del ESP32CAM. El led flash parpadea
//cada 500 ms.


//https://github.com/codigo-iot/ESP32CAM-Flash

//Definición de pines
#define LAMP 4 //Se selecciona el pin donde se encuentra el led flash
#define LED1 12 //GPIO 12


//Inicialización del programa
void setup() //Estructura principal
{
  pinMode(LAMP, OUTPUT); //Configuración de pines. 2 parámetros, pin a configurar y estado (INPUT,INPUT_PULLUP,OUTPUT)
  pinMode(LED1, OUTPUT);
} //Fin de void setup ()

//Cuerpo del programa
void loop() //Función bucle
{
  digitalWrite (LAMP, HIGH); //Encender led. 2 parámetros, pin a controlar, estado (0,LOW,FALSE,1,HIGH,TRUE)
  digitalWrite (LED1, LOW);
  delay (500); //Espera de 2 segundos
  digitalWrite (LAMP, LOW); //Apagar led
  digitalWrite (LED1, HIGH);
  delay (500); //Espera de 2 segundos
} //Fin de void loop()
