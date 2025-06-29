// Define motor driver pins for L293D
#define IN1 D1  // Motor A
#define IN2 D2
#define IN3 D3  // Motor B
#define IN4 D4

void setup() {
  // Set motor pins as OUTPUT
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start Serial Communication
  Serial.begin(115200);
  Serial.println("WASD control started. Use keys W/A/S/D to move. X to stop.");
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();

    // Ignore newline or carriage return
    if (cmd == '\n' || cmd == '\r') return;

    switch (cmd) {
      case 'w':
      case 'W':
        moveForward();
        break;
      case 's':
      case 'S':
        moveBackward();
        break;
      case 'a':
      case 'A':
        turnLeft();
        break;
      case 'd':
      case 'D':
        turnRight();
        break;
      case 'x':
      case 'X':
        stopMotors();
        break;
      default:
        Serial.println("Invalid key. Use W, A, S, D, or X.");
        break;
    }
  }
}

// --- Movement Functions ---

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Moving Forward");
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Moving Backward");
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Turning Left");
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Turning Right");
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Motors Stopped");
}
