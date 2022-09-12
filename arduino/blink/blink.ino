const int LED = 33;
/*#define led 2*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(921600);
Serial.print("Hola mundo");
pinMode(LED,OUTPUT);

}

void loop() {
  
  digitalWrite(LED,HIGH);
  delay(500); //milisegundos
  digitalWrite(LED,LOW);
  delay(500); 
  
}
