#include <Servo.h>

Servo gate;

// Pin definitions
const int IR1 = 2;   // Outside sensor
const int IR2 = 4;   // Inside sensor
const int SERVO_PIN = 9;

// Servo angles
const int OPEN_POS  = 70;
const int CLOSE_POS = 10;

// Parking slots
const int TOTAL_SLOTS = 3;
int availableSlots = 3;

// Timeout (6 seconds)
const unsigned long ENTRY_TIMEOUT = 6000;

// Gate states
enum GateState {
  IDLE,
  ENTRY_OPENED,
  EXIT_OPENED,
  WAIT_CLEAR
};

GateState state = IDLE;
unsigned long gateOpenedTime = 0;

void setup() {
  Serial.begin(9600);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  gate.attach(SERVO_PIN);
  gate.write(CLOSE_POS);

  Serial.println("=================================");
  Serial.println(" SMART PARKING GATE SYSTEM ");
  printParkingStatus();
  Serial.println("=================================");
}

void loop() {

  int s1 = digitalRead(IR1);   // LOW = detected
  int s2 = digitalRead(IR2);

  switch (state) {

    case IDLE:
      // ENTRY
      if (s1 == LOW) {
        if (availableSlots > 0) {
          Serial.println("ENTRY detected -> OPENING gate");
          openGate();
          gateOpenedTime = millis();
          state = ENTRY_OPENED;
        } else {
          Serial.println("PARKING FULL - ENTRY DENIED");
          printParkingStatus();
          delay(1000);
        }
      }
      // EXIT (only if a car is inside)
      else if (s2 == LOW) {
        int parkedCars = TOTAL_SLOTS - availableSlots;
        if (parkedCars > 0) {
          Serial.println("EXIT detected -> OPENING gate");
          openGate();
          state = EXIT_OPENED;
        } else {
          Serial.println("NO CAR INSIDE - EXIT DENIED");
          printParkingStatus();
          delay(1000);
        }
      }
      break;

    case ENTRY_OPENED:
      if (s2 == LOW) {
        availableSlots--;
        Serial.println("CAR ENTERED");
        printParkingStatus();
        closeGate();
        state = WAIT_CLEAR;
      }
      else if (millis() - gateOpenedTime >= ENTRY_TIMEOUT) {
        Serial.println("ENTRY TIMEOUT -> CLOSING gate");
        closeGate();
        state = WAIT_CLEAR;
      }
      break;

    case EXIT_OPENED:
      if (s1 == LOW) {
        if (availableSlots < TOTAL_SLOTS) {
          availableSlots++;
        }
        Serial.println("CAR EXITED");
        printParkingStatus();
        closeGate();
        state = WAIT_CLEAR;
      }
      break;

    case WAIT_CLEAR:
      if (s1 == HIGH && s2 == HIGH) {
        Serial.println("READY FOR NEXT VEHICLE");
        state = IDLE;
      }
      break;
  }
}

// -------- SERVO FUNCTIONS --------

void openGate() {
  smoothMove(CLOSE_POS, OPEN_POS);
  Serial.println("Gate OPEN");
}

void closeGate() {
  smoothMove(OPEN_POS, CLOSE_POS);
  Serial.println("Gate CLOSED");
}

void smoothMove(int from, int to) {
  if (from < to) {
    for (int pos = from; pos <= to; pos++) {
      gate.write(pos);
      delay(25);
    }
  } else {
    for (int pos = from; pos >= to; pos--) {
      gate.write(pos);
      delay(25);
    }
  }
}

// -------- STATUS PRINT --------

void printParkingStatus() {
  int parkedCars = TOTAL_SLOTS - availableSlots;
  Serial.print("Parked Cars: ");
  Serial.println(parkedCars);
  Serial.print("Available Slots: ");
  Serial.println(availableSlots);

  if (availableSlots == 0) {
    Serial.println("STATUS: PARKING FULL");
  } else {
    Serial.println("STATUS: SPACE AVAILABLE");
  }
}
