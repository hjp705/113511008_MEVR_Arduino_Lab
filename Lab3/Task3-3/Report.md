**`Lab3/Task3-3/report.md`**

```markdown
# 課題報告：Task 3-3 HC-05 Wireless LED Control

- 學生姓名：黃家珮
- 學生學號：113511008
- 完成日期：2026-10-01

---

### 1. 實驗目標(可參考課程投影片寫法)
- 學習 HC-05 藍牙模組之配對與無線通訊設定方法。
- 了解 Arduino 與電腦之間的藍牙串列通訊（Bluetooth Serial Communication）原理。
- 熟悉 HC-05 與 Arduino 的資料收發機制。
- 實作以 C# 圖形化介面透過藍牙控制 Arduino LED 開關。
- 驗證無線序列通訊取代 USB 有線通訊的可行性。

### 2. 設備與元件
- Arduino Uno 開發板 × 1
- HC-05 藍牙模組 × 1
- LED × 1
- 電阻（220 Ω 或 330 Ω）× 1
- 麵包板（Breadboard）× 1
- 跳線若干
- USB Type-B 傳輸線 × 1
- 個人電腦（已安裝 Arduino IDE）× 1
- Visual Studio（C# Windows Forms Application）

### 3. 操作說明與成果
1. 電路架設：將 HC-05 藍牙模組連接至 Arduino Uno，並完成 LED 控制電路接線。

2. 設定藍牙連線：開啟電腦藍牙功能，搜尋並配對 HC-05 模組，完成虛擬 COM Port 建立。

3. 燒錄 Arduino 程式：使用 USB 線連接 Arduino Uno 至電腦，開啟 Advanced_Task3-3.ino 程式並點擊「上傳」完成燒錄。Arduino 持續接收來自 HC-05 的藍牙指令以控制 LED。

4. 建立 PC 控制介面：沿用 Advanced Task 3-2 的 C# GUI 程式，調整 SerialPort 設定為 HC-05 對應的 COM Port。

5. 功能測試：

    按下 GUI 的 On 按鈕時，電腦經由藍牙傳送開燈指令。
    HC-05 接收資料後轉送給 Arduino。
    Arduino 接收到指令後點亮 LED。
    按下 GUI 的 Off 按鈕時，Arduino 接收到關燈指令並熄滅 LED。
    測試過程中不需 USB 序列通訊即可完成 LED 控制。

6. 實驗成果：成功利用 HC-05 藍牙模組建立 Arduino 與電腦之間的無線序列通訊。使用者可透過 C# 圖形化介面遠端傳送控制訊號，使 Arduino 正確執行 LED 開啟與關閉功能，達成無線 LED 控制目標。

7. 操作影片：請參閱同目錄下 video/Task3-3.mp4 之實際操作畫面。
