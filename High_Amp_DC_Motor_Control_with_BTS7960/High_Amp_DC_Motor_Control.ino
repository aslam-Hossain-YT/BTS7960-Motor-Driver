// Define pins
const int RPWM_PIN = 9; // RPWM pin of BTS7960 connected to Arduino pin 5
const int LPWM_PIN = 10; // LPWM pin of BTS7960 connected to Arduino pin 6

void setup() {
  // Set up the control pins as outputs
  pinMode(RPWM_PIN, OUTPUT);
  pinMode(LPWM_PIN, OUTPUT);
}

void loop() {
  // Motor forward
  for (int speed = 0; speed <= 255; speed++) {
    analogWrite(RPWM_PIN, speed);
    analogWrite(LPWM_PIN, 0);
    delay(39); // Increase speed gradually over 10 seconds (10,000ms/256 steps = 39ms per step)
  }
  
  delay(2000); // Stop for 2 seconds
  
  // Motor reverse
  for (int speed = 0; speed <= 255; speed++) {
    analogWrite(LPWM_PIN, speed);
    analogWrite(RPWM_PIN, 0);
    delay(39); // Increase speed gradually over 10 seconds
  }

  delay(2000); // Stop for 2 seconds before restarting the loop
}

