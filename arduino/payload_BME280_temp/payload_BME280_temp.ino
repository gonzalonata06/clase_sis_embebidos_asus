#include <Adafruit_BMP280.h>
#include <SD.h>
#include <sd_diskio.h>
#include <sd_defines.h>

File readings, readme;
const int LED = 33;

Adafruit_BMP280 bmp;

char payload[50]; //datos a escribir en el SD y serial

void setup() {
  // put your setup code here, to run once:
 pinMode(LED,OUTPUT);
 Serial.begin(115200); // Inicializar serial UART-USB
 bmp.begin(0x76); // Inicializar comunicación I2C con el sensor barométrico
 SD.begin(); //Inicializar SD 
 readme = SD.open("/README.txt",FILE_WRITE);
 readme.print("Archivo de lecturas del sensor BMP280.\n" "Temperatura [°C], Presion [Pa]");
}

void loop() {
  //Hacer: Columna 1: temperatura ; columna 2: presión
  //Serial.println(String(bmp.readTemperature()) + "\t" + String(bmp.readPressure()) );
 // sprintf(payload, "temp:%.2f, press:%.2f", bmp.readTemperature(), bmp.readPressure()); //Futuro diccionario 
  sprintf(payload, "%.2f, %.2f", bmp.readTemperature(), bmp.readPressure());
  Serial.println(payload);

  //Abro archivo y escribo
  digitalWrite(LED,HIGH);
  readings = SD.open("/readings.csv", FILE_APPEND);
  readings.println(payload);
  readings.close();
  digitalWrite(LED,LOW);
  delay(500);

}
