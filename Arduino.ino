 const  int buzzer = 13;
char data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
 data =  Serial.read();
delay(5);
if (data=='1')
{
tone (buzzer, 1000); // Envoie un signal sonore 1KHz... 
  delay(1000); // ...pendant 1 seconde 
  noTone(buzzer);
 
}
else if (data=='0')
{
  noTone(buzzer);     // Arrête le son... 
  delay(1000);        // ...pendant 1sec
}
}}
