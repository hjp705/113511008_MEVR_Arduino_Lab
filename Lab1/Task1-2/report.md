**`Lab1/Task1-2/report.md`**

```markdown
# 課題報告：Task 1-2 RGB LED —Layering Three Inputs

- 學生姓名：黃家珮
- 學生學號：113511008
- 完成日期：2026-09-17

---

### 1. 實驗目標(可參考課程投影片寫法)
- 學習整合數位輸入（Button）、序列埠輸入（Serial Input）與類比輸入（Variable Resistor）三種輸入方式。
- 了解 RGB LED 三個顏色通道（R、G、B）的控制原理。

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- RGB LED × 1
- 按鈕（Push Button）× 1
- 可變電阻（Variable Resistor）× 1
- 220 Ω 限流電阻 × 3（RGB 各色腳位皆需串接）

### 3. 操作說明與成果
1. 完成電路接線：依照實驗電路圖將 RGB LED、按鈕及可變電阻接至 Arduino Uno。其中 RGB LED 的三個顏色腳位皆需串接限流電阻，最長腳（共陰極）接至 GND。

2. 燒錄程式：使用 USB 線連接 Arduino Uno 至電腦，開啟 Task1-2.ino 並點擊「上傳」，將程式燒錄至開發板。

3. 測試藍光控制：旋轉可變電阻，利用 analogRead() 讀取類比輸入值並調整藍色 LED 亮度。旋鈕轉動時可觀察藍光亮度隨之改變。

4. 測試紅光控制：按下按鈕後，紅色 LED 點亮。此時 RGB LED 顯示由藍色與紅色混合而成的紫色（Purple）。

4. 測試綠光控制：開啟 Arduino IDE 的 Serial Monitor，輸入字元 1 並送出。程式接收到序列埠資料後點亮綠色 LED。

5. 實驗成果：
    - 僅調整可變電阻時，RGB LED 顯示藍色（Blue）。
    - 在藍光基礎上按下按鈕後，RGB LED 顯示紫色（Purple）。
    - 再透過 Serial Monitor 輸入 1 開啟綠光後，RGB LED 同時輸出紅、綠、藍三色，呈現白色（White）。
    - 成功驗證類比輸入、數位輸入與序列埠輸入三者可共同控制 RGB LED 並產生顏色疊加效果。

6. 操作影片：請參閱同目錄下 video/Task1-2.mp4 之實際操作畫面。
