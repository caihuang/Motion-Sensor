
int servoPin = 13; // pin for servo
int inputPin = 2; // pin for PIR sensor
int val = 0; // stores the value read
int pir = LOW; // no motion detected in beginning

void setup()
{
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT); // servo as output
  pinMode(inputPin, INPUT); // sensor as input
}

void loop() {
  val = digitalRead(inputPin);
  if(val == HIGH)
  {
    digitalWrite(servoPin, HIGH);
    if (pir == LOW)
    {
      Serial.println("Motion detected!");
      pir = HIGH;
    }
  }
  else
  {
    digitalWrite(servoPin, LOW);
    if(pir == HIGH)
    {
      Serial.println("Motion ceased!");
      pir = LOW;
    }
  }

}
