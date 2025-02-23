const int trigpin = 2;
const int echopin = 3;

long duration;
int distance;

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  //clears the trigpin condition
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  //sets the trig pin for 10 seconds
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  //read the echo pin , return the sound waves travel time in micro seconds
  duration = pulseIn(echopin, HIGH);
  // calculating the distance 
  distance = duration * 0.034 / 2;// speed of sound is divided by 2
  // displays the distance on serial moniter
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.print("\n");
  delay(500);

  
}