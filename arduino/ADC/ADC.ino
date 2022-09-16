const int LDR = 34, L35 = 35, LED = 33;

//#define LDR 34;


void setup() {
  // put your setup code here, to run once:
  pinMode(LDR,INPUT);
  pinMode(L35,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
// put your main code here, to run repeatedly:

int lux = analogRead(LDR), temp = (analogRead(L35) * 0.1221); //conversión a grados Celcius

Serial.println(lux);
delay(1000);
//Serial.println(temp);
//delay(1000);

if(lux < 300){
  digitalWrite(LED,HIGH);
  delay(4000);
  
  }
  else{digitalWrite(LED,LOW);}

}
