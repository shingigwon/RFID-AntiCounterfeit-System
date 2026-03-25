# 📡 RFID 기반 정품 위조 방지 보증서 시스템  
> 교내 특별과정 임베디드 시스템 SW (2023.03 ~ 2023.06) <br>
> 🏆 프로젝트 평가 1위

---

## 📌 프로젝트 소개
온라인 구매 증가로 인해 정품과 가품 구별이 어려운 문제를 해결하기 위해,  
RFID를 활용하여 제품 정보를 저장하고 정품 여부를 검증할 수 있는 시스템을 개발했습니다.

---

## 🚀 주요 기능
- RFID 태그에 제품 정보(모델명, 제조일, A/S 기간 등) 저장
- RFID 리더기를 통한 제품 정보 조회 및 검증
- MySQL 연동을 통한 정품 여부 확인
- MQTT 및 NodeRED를 활용한 데이터 흐름 처리 및 시각화

---

## 🏗️ 시스템 흐름
- RFID 태그 정보 읽기  
- MQTT를 통해 데이터 전송
- MySQL에서 제품 정보 조회 및 검증
- NodeRED에서 데이터 처리 및 시각화  


---

## 🛠 Tech Stack
| 구분           | 기술                          |
|----------------|-------------------------------|
| 하드웨어       | ESP32-S3-DevKitC-1, RFID-RC522 |
| 펌웨어         | Arduino                        |
| 통신           | MQTT (Mosquitto)               |
| 서버/미들웨어  | Node-RED                       |
| 데이터베이스   | MySQL                          |

---

## 🧩 사용 센서
- **RFID-RC522**: 제품 정보 저장 및 인증

![RFID-RC522](https://github.com/user-attachments/assets/4b611906-b26c-455a-87e5-bbd6091193b3)

---

## 🖥️ 동작 화면
 
### NodeRED Flow
RFID UID를 수신하여 DB 조회 후 대시보드에 정품 정보를 표시하는 흐름입니다.
 
![NodeRED Flow](https://github.com/user-attachments/assets/b37ffd17-3d26-424e-a30f-e0d569f19f3a)
)
 
### 대시보드
좌측은 신규 RFID 정보 등록, 우측은 등록된 정품 정보 조회 화면입니다.
 
![Dashboard](https://github.com/user-attachments/assets/fe70ad09-c42b-4584-905a-e04e330ac0db)
)
 
---

## 🙋‍♂️ 담당 역할
- ESP32-S3 기반 RFID 데이터 수집 및 처리 로직 구현  
- MQTT 프로토콜을 활용한 데이터 전송 구조 설계  
- MySQL 연동을 통한 제품 인증 로직 구현  
- NodeRED 기반 데이터 흐름 구성 및 시각화  

---

## 💡 기대 효과
- 소비자가 쉽게 정품 여부를 확인 가능  
- 위조 제품 유통 방지 및 신뢰성 확보  

---

## 🔧 개선 방안
- RFID 통신 안정성 추가 개선  
- MQTT 기반 시스템 확장 및 실시간 처리 강화  

---

## 📄 프로젝트 자료
👉 [📑 결과 보고서 PDF 보기](https://github.com/user-attachments/files/19530597/SW_Project_SGG.pdf)
