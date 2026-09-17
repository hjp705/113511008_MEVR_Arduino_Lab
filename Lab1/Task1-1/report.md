**`Lab1/Task1-1/report.md`**

```markdown
# 課題報告：Task 1-1 Using the variable resistor to adjust LED lightness

- 學生姓名：黃家珮
- 學生學號：113511008
- 完成日期：2026-09-17

---

### 1. 實驗目標(可參考課程投影片寫法)
- Using variable resistor and "int analogRead(pin)" to control the LED's brightness and read the return value.
- Adjust the LED's brightness based on the analog value.
- print the analog return value every 1 second in the Serial Monitor

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- Varialbe resistor
- Red LED

### 3. 操作說明與成果
1. 完成電路接線：依照實驗要求將可變電阻（Variable Resistor）接至 Arduino Uno 的類比輸入腳位（如 A0），並將 LED 與限流電阻接至 PWM 輸出腳位，使 Arduino 能讀取可變電阻的電壓值並控制 LED 亮度。

2. 燒錄程式：使用 USB 線連接 Arduino Uno 至電腦，開啟 Task1-1.ino 並點擊 Arduino IDE 的「上傳（Upload）」按鈕，將程式燒錄至開發板。

3. 開啟序列埠監控器：開啟 Arduino IDE 的 Serial Monitor，將鮑率（Baud Rate）設為 9600 baud，觀察程式每秒輸出的類比讀值。

4. 調整可變電阻：旋轉可變電阻旋鈕，Arduino 會透過 analogRead() 讀取電壓變化，並根據讀值調整 LED 的亮度。讀值越大，LED 亮度越高；讀值越小，LED 亮度越低。

5. 實驗成果：成功透過可變電阻調整 LED 亮度，且序列埠監控器每秒印出一次目前的類比輸入值

6. 操作影片：請參閱同目錄下 video/Task1-1.mp4 之實際操作畫面。