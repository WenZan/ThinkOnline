int led = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    ;// wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("serial is ok!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    int choice = Serial.read();
    Serial.println(choice, DEC);
    if (choice == 11) {
      digitalWrite(led, HIGH);
      delay(1000);
      digitalWrite(led, LOW);
   }
  }
}
