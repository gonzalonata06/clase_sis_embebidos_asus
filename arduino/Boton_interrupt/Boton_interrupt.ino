
  // put your setup code here, to run once:
struct boton{
  const int pin;
  int numVec;
  bool presionado;
  };
  
  boton boton1 = {25,0,false};

void IRAM_ATTR isr_boton(){
  boton1.numVec += 1;
  boton1.presionado = true; 
  
  }
  
void setup() {
  Serial.begin(9600);
  pinMode(boton1.pin,OUTPUT);
  attachInterrupt(boton1.pin, isr_boton, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(boton1.presionado){
    Serial.printf("El boton se ha presionado %u \n", boton1.numVec);
    boton1.presionado = false;
    }

}
