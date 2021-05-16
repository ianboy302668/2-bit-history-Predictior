# 2-bit-history-Predictior
## 專案說明
  此為計算機組織程式作業，目標為能將輸入序列毒入並做出正確預測的2位元預測器。
## 功能說明
**基本流程:**
  1. 在一文件檔(.txt)內輸入目標序列
  2. 讀取文件
  3. 前兩位為history，讀取相對應counter之state，並以該state為預測值
  4. 比較預測值與目標序列第三位元是否吻合
  5. 彈出目標序列第一位元
  6. 重複上述動作至序列長度小於3
  7. 輸出結果
## 使用說明
  1. 輸入參數: 檔案位置
  2. 確認輸出結果
## 輸入範例
      TTTTNNTNTNTNTNTNT

## 輸出範例
    The input is : TTTTNNTNTNTNTNTNT
        Counter            Prediction     Outcome     Missing(Y/N)    
    -------------------------------------------------------------------- 
     1   (11, SN, SN, SN, SN)          N             T           Yes!    
     2   (11, SN, SN, SN, WN)          N             T           Yes!    
     3   (11, SN, SN, SN, WT)          T             N           Yes!    
     4   (10, SN, SN, SN, WN)          N             N            No     
     5   (00, SN, SN, SN, WN)          N             T           Yes!    
     6   (01, WN, SN, SN, WN)          N             N            No 
     7   (10, WN, SN, SN, WN)          N             T           Yes!
     8   (01, WN, SN, WN, WN)          N             N            No 
     9   (10, WN, SN, WN, WN)          N             T           Yes!
    10   (01, WN, SN, WT, WN)          N             N            No 
    11   (10, WN, SN, WT, WN)          T             T            No 
    12   (01, WN, SN, ST, WN)          N             N            No 
    13   (10, WN, SN, ST, WN)          T             T            No 
    14   (01, WN, SN, ST, WN)          N             N            No 
    15   (10, WN, SN, ST, WN)          T             T            No 
