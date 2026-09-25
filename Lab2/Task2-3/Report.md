**`Lab2/Task2-3/report.md`**

```markdown
# 課題報告：Task 2-3 External Interrupt vs Polling

- 學生姓名：黃家珮
- 學生學號：113511008
- 完成日期：2026-09-24

---

### 1. 實驗目標(可參考課程投影片寫法)
- 學習外部中斷（External Interrupt）與輪詢（Polling）之基本原理。
- 了解不同事件偵測方式對系統反應速度的影響。
- 實作按鈕控制 LED 開關功能，並比較中斷與輪詢機制之差異。
- 驗證在系統忙碌或阻塞（Blocking）情況下，中斷與輪詢的行為表現。

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1

### 3. 操作說明與成果
1. **燒錄程式**：使用 USB 線連接 Arduino Uno 至電腦，開啟 `Task0-1.ino` 並點擊「上傳」。
2. **開啟監控器**：開啟 Arduino IDE 的 Serial Monitor，將鮑率（Baud rate）設為 **9600 baud**。
3. **實驗成果**：序列埠監控器成功每秒印出一次 `Hello World from Arduino!` 訊息。
4. **操作影片**：請參閱同目錄下 `video/Task0-1.mp4` 之實際操作畫面。
