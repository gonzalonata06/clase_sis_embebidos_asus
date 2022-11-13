#define pin_relevador 15 
#define PIN_BUTTON 25




unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 300; //delay para debouncing en ms
boolean status_boton = false;

//Al presionar un botón, cambia el color del led
void IRAM_ATTR isr_button(){
  if ((millis() - lastDebounceTime) > debounceDelay){
     if(status_boton){
      digitalWrite(pin_relevador,HIGH);
      }else{
        digitalWrite(pin_relevador,LOW);
        }
     status_boton = !status_boton;
 
     
     lastDebounceTime = millis();
  }
}

void setup() {
  // put your setup code here, to run once:
  
  attachInterrupt(PIN_BUTTON, isr_button, RISING);

  
  Serial.begin(115200);
  pinMode(pin_relevador,OUTPUT);
  pinMode(PIN_BUTTON,INPUT);

   //Canales LED 
  
}

void loop() {
  // put your main code here, to run repeatedly:
 
    
  

  
}
