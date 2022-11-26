RTC_DATA_ATTR int bootCount = 0; // Esta variable se guarda en la memoria del RTC.
                  // Esta memoria sí se mantiene en un deepsleep


#define uS_TO_FACTOR    1000000 // FACTOR DE CONVERSION A MICROSEGUNDOS
#define TIME_TO_SLEEP   5 // Tiempo que el ESP va a dormir en s
#define LED_PIN         26
#define BUTTON_PIN      25

void setup() {
  // Configuración light sleep
 Serial.begin(115200);
 delay(1000);
 
 pinMode(LED_PIN,OUTPUT);
 bootCount ++;
 Serial.println("Número de veces iniciado " + String(bootCount));
 print_wakeup_reason();

esp_sleep_enable_ext0_wakeup((gpio_num_t)BUTTON_PIN,HIGH);
esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP*uS_TO_FACTOR);
Serial.println("configurando para poner a dormir el ESP32 por " + String(TIME_TO_SLEEP) + " segundos.");


if(bootCount%2 == 0){
Serial.println("ESP se va a dormir ahora");
esp_deep_sleep_start();
}

Serial.println("Esta línea se imprime en los conteos impares");
 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, LOW);
  
 
  esp_light_sleep_start();
  digitalWrite(LED_PIN, HIGH);
  delay(500);

  print_wakeup_reason();

  

}

void print_wakeup_reason(){
  
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch(wakeup_reason){
    case ESP_SLEEP_WAKEUP_EXT0:
      Serial.println("Inicio causado por la señal en el RTC_IO");
    break;
    case ESP_SLEEP_WAKEUP_EXT1:
      Serial.println("Inicio causado por la señal en el RTC_CNTL");
    break;
    
    case ESP_SLEEP_WAKEUP_TIMER:
      Serial.println("Inicio causado por la señal en un timer");
    break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD:
      Serial.println("Inicio causado en pin touch");
    break;
    case ESP_SLEEP_WAKEUP_ULP:
    Serial.println("Inicio causado por la señal lanzada por el ULP Coprocessor");
    break;
    default:
      Serial.printf("El inicio no fue causado por alguna razón conocida %d\n", wakeup_reason);
      
 
    
    }
  
}
