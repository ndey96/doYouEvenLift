volatile boolean lifts = false;
volatile int waitingForInput = false;
const int musclePin = A0;
int powerLevel = 0; // Cannot exceed 9000
int highScore = 0;

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, buttonPressed, RISING);
}

void loop() {
  if (lifts) {
    powerLevel = analogRead(musclePin);
    if (powerLevel > highScore) {
      highScore = powerLevel;
    }
    Serial.println(powerLevel);
  } else if (!waitingForInput) {
    Serial.print("Your power level: ");
    Serial.println(highScore);
    Serial.println("Do you even lift?");
    highScore = 0;
    waitingForInput = true;
  }
}

void buttonPressed() {
  lifts = !lifts;
  waitingForInput = false;
}
