#include <Servo.h>

Servo motor;

// 接腳
const int trigPin = 2;
const int echoPin = 3;
const int servoPin = 5;

// 馬達設定
const int horizontalAngle = 105;
const int maxAngleChange = 24;



// 速度每增加 1 cm/s，馬達修正多少度
float targetDistance = 13;
float positionGain = -1.5;  // 位置修正強度，先從這個值測試
float speedGain = -0.8;

// 如果控制方向相反，改成 -1
int direction = -1;

// 測距設定：依照軌道長度調整
const float minDistance = 0;
const float maxDistance = 24;
const unsigned long sampleInterval = 60;  // 毫秒

float distance = 0;
float lastDistance = 0;
float speed = 0;
float smoothSpeed = 0;
float angle = 90;

unsigned long lastSampleTime = 0;
unsigned long lastMeasureTime = 0;

bool firstMeasure = true;

// 用超音波量距離，單位 cm
float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long echoTime = pulseIn(echoPin, HIGH, 10000);

  // 沒收到回波
  if (echoTime == 0) {
    return -1;
  }

  return echoTime * 0.0343 / 2;
}

void setup() {
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);

  motor.attach(servoPin);
  motor.write(horizontalAngle);

  delay(500);
}

void loop() {
  unsigned long currentTime = millis();

  // 每隔約 60 ms 測量一次
  if (currentTime - lastSampleTime < sampleInterval) {
    return;
  }

  lastSampleTime = currentTime;

  distance = measureDistance();
  unsigned long measureTime = millis();

  // 距離無效時，回到水平並重新開始測量
  if (distance < minDistance || distance > maxDistance) {
    motor.write(horizontalAngle);
    firstMeasure = true;
    smoothSpeed = 0;

    Serial.println("Invalid distance");
    return;
  }

  // 第一次只有位置，還不能算速度
  if (firstMeasure) {
    lastDistance = distance;
    lastMeasureTime = measureTime;
    firstMeasure = false;

    motor.write(horizontalAngle);
    return;
  }

  // 經過的時間，換成秒
  float timePassed = (measureTime - lastMeasureTime) / 1000.0;

  if (timePassed <= 0) {
    return;
  }

  // 正值：遠離感測器；負值：靠近感測器
  speed = (distance - lastDistance) / timePassed;

  lastDistance = distance;
  lastMeasureTime = measureTime;

  // 平滑速度，減少量測雜訊造成的抖動
  smoothSpeed = 0.35 * speed + 0.65 * smoothSpeed;

  float controlSpeed = smoothSpeed;

  // 速度很小時視為停止
  if (abs(controlSpeed) < 1.0) {
    controlSpeed = 0;
  }

  // 反向傾斜，抵消球的速度
 float positionError = targetDistance - distance;

 float angleChange = direction * (
  positionGain * positionError - speedGain * controlSpeed
 );

  if (abs(positionError) < 1.5 &&
      abs(smoothSpeed) < 1) {
    angleChange = 0;
  }

  angleChange = constrain(
    angleChange,
    -float(maxAngleChange),
    float(maxAngleChange)
  );

  angle = horizontalAngle + angleChange;
  motor.write(int(angle + 0.5));

  // Serial Monitor / Plotter 選擇 115200 baud
  Serial.print("Distance:");
  Serial.println(distance, 2);

  Serial.print("\tSpeed:");
  Serial.println(smoothSpeed, 2);

  Serial.print("\tAngle:");
  Serial.println(angle, 1);
}