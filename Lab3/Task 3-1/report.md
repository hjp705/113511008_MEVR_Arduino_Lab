**`Lab3/Task3-1/report.md`**

```markdown
# 課題報告：Task 3-1 Timer Interrupt vs Blocking Delay

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
1. 電路架設：依據 Basic Task 1-2 接線方式建立兩組按鈕與 LED 電路，分別作為 Timer Interrupt 與 Blocking Delay 之比較實驗。

2. 燒錄程式：使用 USB 線連接 Arduino Uno 至電腦，開啟 Advanced_Task3-1.ino 程式並點擊「上傳」完成燒錄。

3. 功能測試：

    Button A + LED A 使用 TimerOne 函式庫設定每 50 ms 觸發一次 Timer Interrupt。
    在中斷服務程序（ISR）中讀取 Button A 狀態並更新 LED A。
    Button B + LED B 則於 loop() 中以輪詢方式讀取按鈕狀態。
    在 loop() 結尾加入 delay(1000)，模擬系統執行阻塞延遲。

4. 實驗成果：

    Timer Interrupt 控制的 LED A 即使系統正在執行 delay(1000)，仍能定期執行中斷服務程序，快速偵測按鈕狀態並更新 LED。
    Blocking Delay 控制的 LED B 必須等待延遲結束後才能再次讀取按鈕狀態，因此反應速度明顯較慢，部分短暫按壓可能無法被偵測。
    實驗結果顯示 Timer Interrupt 具有較佳的即時性與可靠性，適合用於機器人控制、感測器監控等需要即時回應的系統。

5. 操作影片：請參閱同目錄下 video/Task3-1.mp4 之實際操作畫面。
