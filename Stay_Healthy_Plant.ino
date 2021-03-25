const int led = 2;
const int relay = 3;
const int ldr = A7;
int var, level_brightness = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
pinMode(ldr, INPUT);
pinMode(relay, OUTPUT);
Serial.begin(9600);
digitalWrite(relay, LOW);
delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
var = analogRead(ldr);
level_brightness = map(var, 0, 1024, 0, 100);

Serial.println("Level brigtness = ");
Serial.println(level_brightness);
delay(200);

if(level_brightness <= 10){
  digitalWrite(relay, HIGH);
  digitalWrite(led, HIGH);
  delay(1000);
}
else if (level_brightness > 10){
  digitalWrite(relay, LOW);
  digitalWrite(led, LOW);
  delay(1000);
}
}
