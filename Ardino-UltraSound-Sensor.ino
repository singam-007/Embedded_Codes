const int ECHO_PIN = 3;
const int TRIG_PIN = 4;
const int LED_PIN =  2;

long duration = 0;
float distance = 0.0;
float oldDistance = 0.0;

void setup() {
  Serial.begin(9600);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration * 0.0345 / 2;

  if (distance > oldDistance + 1 || distance < oldDistance - 1)  {
    oldDistance = distance;
    Serial.print(distance, 1);
    Serial.println(" cm");

    if (distance < 50) {
      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  }
}
