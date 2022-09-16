const int boton = 25, led = 33;


void setup() {
  // put your setup code here, to run once:
  pinMode(boton,INPUT);
  pinMode(led,OUTPUT); //Configuracion de entrada
  //pinMode(boton,OUTPUT); //Configuracion de sálida
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int voltaje = digitalRead(boton);
  Serial.println(voltaje);
  //delay(1000);
  if(voltaje == 1){
    digitalWrite(led,HIGH);
    Serial.println("Led encendido");
    
    
    }
  else{  
  digitalWrite(led,LOW);
  Serial.println("Led apagado");
  
  }

  delay(5000);
}
