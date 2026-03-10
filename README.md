# Autosar_LdCom_

## 專案簡介
本專題基於 **AUTOSAR** 規範的 OS 上實作 **Large Data Communication (LdCom)** 模組。AUTOSAR (Automotive Open System Architecture) 是一套車用軟體標準，主要目的為提高軟體使用的可重複性。

在 AUTOSAR CP (Classic Platform) 中可分為三個層級：
* **應用層 (Application Layer)**
* **運行環境層 (Runtime Environment Layer)**
* **基礎軟體層 (Basic Software Layer)**

本專題目標是實作 LdCom 傳送端與接收端並使其按照規範運行。與一般 Com 模組不同，LdCom 專門處理大型資料（一個 IPDU 內部僅包含一個 Signal），且不需要額外對信號進行處理。

## 實作目標
* **模組開發**：實作 LdCom 傳送端與接收端，並確保其按照規範正常運行。
* **資料處理**：專門處理大型資料（IPDU 內僅包含單一 Signal），不需額外進行信號處理。
* **軟體實作**：包含整個模組的軟體設計、實作、以及與上下層模組的互動。

## 技術重點
* **開發環境**：CS+ for CC (IDE)
* **硬體平台**：RH850 開發板
* **實作語言**：C 語言
