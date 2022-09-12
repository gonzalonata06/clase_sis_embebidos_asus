const int LDR = 34;
//#define LDR 34;

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR,INPUT);
  Serial.begin(9600);
}

void loop() {
// put your main code here, to run repeatedly:

int m = analogRead(LDR);

Serial.println(m);
delay(1000);

}
