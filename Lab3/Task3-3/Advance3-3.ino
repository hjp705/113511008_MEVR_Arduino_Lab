#include <SoftwareSerial.h>
const int LEDA = 8;
// Arduino RX, Arduino TX
SoftwareSerial bluetooth(10, 11);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LEDA, LOW);

  Serial.begin(9600);       // USB除錯用
  bluetooth.begin(9600);    // HC-05通訊

  Serial.println("Arduino ready");
}

void loop() {
  if (bluetooth.available() > 0) {
    char command = bluetooth.read();

    Serial.print("Received: ");
    Serial.println(command);

    if (command == '1') {
      digitalWrite(LEDA, HIGH);
      bluetooth.println("LED ON");
    }
    else if (command == '0') {
      digitalWrite(LEDA, LOW);
      bluetooth.println("LED OFF");
    }
  }
}
