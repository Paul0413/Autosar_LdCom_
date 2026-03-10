# Autosar_LdCom_
簡介：
本專題基於AUTOSAR 規範的 OS 上實作 Large Data Communication
(以下簡稱LdCom )模組。AUTOSAR (Automotive Open System Architecture)
是一套車用軟體標準，其設立的主要目的即為提高軟體使用的可重複性。而
在 AUTOSAR CP (Classic Platform) 中可分為以下三個部分：應用層
(Application Layer)、、行環境層層(Runtime Environment Layer)以及基礎軟體層
(Basic Software Layer)、。在層層中，同模模組的規書定義了該模模組的環為及
與其他模組間的互動。AUTOSAR 將功能切分成同模的模組，以利開發者更
好的進環系統維護與更新。
本專題目的是實作LdCom 傳送端與接收端並使其能按照AUTOSAR 規
範正常行環，專題內容包含整個模組的軟體設計及實作。與Com 模組同模
的是，LdCom 專門處理大型資料，也就是一個IPDU (Interaction Layer Protocol
Data Unit)內部只會有一個 Signal，並且同需要額外對Signal 進環處理。
