#include <TimerOne.h>
int timercount = 0; // Timer counter
const int ButtonA = 2;
const int LEDA    = 8;
const int ButtonB = 3;
const int LEDB    = 9;

void timer_int(){ // ISR (Interrupt Service Routine)
  int state = digitalRead(ButtonA);

  if (state == HIGH)
    digitalWrite(LEDA, HIGH);
  else
    digitalWrite(LEDA, LOW);
}
void setup() {
  Serial.begin(9600);

  pinMode(ButtonA, INPUT_PULLUP);
  pinMode(ButtonB, INPUT_PULLUP);

  pinMode(LEDA, OUTPUT);
  pinMode(LEDB, OUTPUT);

  Timer1.initialize(500000);
  Timer1.attachInterrupt(timer_int);
}
void loop(){
  int state = digitalRead(ButtonB);

  if (state == HIGH)
    digitalWrite(LEDB, HIGH);
  else 
    digitalWrite(LEDB, LOW);

  delay(1000);
}

