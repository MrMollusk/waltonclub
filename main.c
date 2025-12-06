const int trigPin = 9;
const int echoPin = 10;

long duration;
float distanceCm;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

float readDistanceCm() {
  // send 10 µs pulse on TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // read ECHO pulse length
  duration = pulseIn(echoPin, HIGH, 30000); // timeout ~30 ms

  // convert to cm (speed of sound ~343 m/s)
  float distance = duration * 0.0343 / 2.0;
  return distance;
}

void loop() {
  distanceCm = readDistanceCm();
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  delay(200);
}
