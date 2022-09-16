const int LED = 33;
/*#define led 2*/
void setup() {
  // put your setup code here, to run once:
 
pinMode(LED,OUTPUT);

}

void loop() {
  
  digitalWrite(LED,HIGH);
  delay(500); //milisegundos
  digitalWrite(LED,LOW);
  delay(500); 
  
}
