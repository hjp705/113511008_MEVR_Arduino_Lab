**`Lab3/Task3-2/report.md`**

```markdown
# 課題報告：Task 3-2 LED Control with Serial Communication

- 學生姓名：黃家珮
- 學生學號：113511008
- 完成日期：2026-10-01

---

### 1. 實驗目標(可參考課程投影片寫法)
- 學習 Arduino 與電腦之間的 UART 序列通訊原理。
- 熟悉 Arduino Serial.begin()、Serial.read() 與 Serial.println() 的使用方式。
- 學習使用 C# Windows Forms 製作簡易圖形化操作介面（GUI）。
- 實作透過電腦端 GUI 傳送指令控制 Arduino LED 開啟與關閉。
- 驗證 Arduino 與電腦之雙向序列通訊功能。

### 2. 設備與元件
- Arduino Uno 開發板 × 1
- LED × 1
- 電阻（220 Ω 或 330 Ω）× 1
- 麵包板（Breadboard）× 1
- 跳線若干
- USB Type-B 傳輸線 × 1
- 個人電腦（已安裝 Arduino IDE）× 1
- Visual Studio（C# Windows Forms Application）

### 3. 操作說明與成果
1. 電路架設：將 LED 與限流電阻連接至 Arduino Uno 指定數位輸出腳位，完成 LED 控制電路。

2. 建立 PC 控制介面：使用 Visual Studio 建立 C# Windows Forms 專案，於視窗中新增「On」與「Off」按鈕，並設定 SerialPort 進行序列通訊。

3. 燒錄 Arduino 程式：使用 USB 線連接 Arduino Uno 至電腦，開啟 Advanced_Task3-2.ino 程式並點擊「上傳」完成燒錄。Arduino 使用 Serial.  begin(9600) 初始化 UART 通訊，並持續接收來自電腦的指令。

4. 功能測試：

    按下 GUI 的 On 按鈕時，C# 程式透過序列埠傳送開燈指令。
    Arduino 接收到資料後點亮 LED。
    按下 GUI 的 Off 按鈕時，C# 程式透過序列埠傳送關燈指令。
    Arduino 接收到資料後熄滅 LED。
    Arduino 可透過 Serial.println() 回傳目前狀態至電腦端顯示。

5. 實驗成果：成功建立 C# 圖形化控制介面，透過 UART 序列通訊控制 Arduino LED 開關。當使用者按下介面中的 On 或 Off 按鈕時，Arduino 能正確接收指令並控制 LED 狀態，同時將執行結果回傳至電腦端，完成雙向序列通訊功能驗證。

6. 操作影片：請參閱同目錄下 video/Advanced_Task3-2.mp4 之實際操作畫面。
