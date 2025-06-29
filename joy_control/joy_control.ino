#define DIR_LEFT D1
#define PWM_LEFT D2
#define DIR_RIGHT D5
#define PWM_RIGHT D6

void setup() {
  Serial.begin(115200);
  pinMode(DIR_LEFT, OUTPUT);
  pinMode(PWM_LEFT, OUTPUT);
  pinMode(DIR_RIGHT, OUTPUT);
  pinMode(PWM_RIGHT, OUTPUT);
}

void driveMotor(int pwm, int dirPin, int pwmPin) {
  if (pwm >= 0) {
    digitalWrite(dirPin, HIGH);
    analogWrite(pwmPin, pwm);
  } else {
    digitalWrite(dirPin, LOW);
    analogWrite(pwmPin, -pwm);
  }
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    int comma = input.indexOf(',');
    if (comma != -1) {
      int left = input.substring(0, comma).toInt();
      int right = input.substring(comma + 1).toInt();
      driveMotor(left, DIR_LEFT, PWM_LEFT);
      driveMotor(right, DIR_RIGHT, PWM_RIGHT);
    }
  }
}
