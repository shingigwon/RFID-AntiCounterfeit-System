# 정품 위조 방지를 위한 보증서 RFID 시스템- 교내 특별과정 임베디드시스템S/W(2023.03~2023.06)

## 개요
온라인 구매가 증가함에 따라 정품과 가품을 구별하는 것이 어려워졌습니다. 이를 해결하기 위해 RFID를 이용하여 해당 제품에 대한 정보가 포함된 보증서를 만들어 정품과 가품을 구별하는 시스템을 개발하였습니다.

## 프로젝트 목표
- RFID에 제품 모델명, 제조일, A/S 기간, 구매일 등의 정보를 저장
- 리더기를 통해 정보를 읽고 검증
- 데이터베이스(MySQL)와 연동하여 정품 여부 확인
- NodeRED 및 MQTT를 활용하여 데이터 흐름 관리

## 개발 환경
- **ESP32-S3-DevKitC-1**
- **Arduino**
- **MySQL**
- **MQTT**(Mosquitto 사용)
- **NodeRED**

## 사용한 센서
- **RFID-RC522**: 제품 정보 저장 및 인증을 위한 RFID 모듈
![RFID-RC522_](https://github.com/user-attachments/assets/4b611906-b26c-455a-87e5-bbd6091193b3)



## 시스템 흐름도
1. RFID 정보를 읽음
2. MQTT를 통해 데이터 전송
3. NodeRED에서 데이터 시각화
4. MySQL에서 해당 RFID 정보 조회


## 기대 효과
- 소비자가 쉽게 정품 여부를 확인할 수 있음
- 구매자와 판매자 간의 신뢰 확보
- 위조 제품 유통 방지

## 개선 방안
1. **ESP32-S3와 RFID 모듈 간 연결 안정성 개선**
2. **MQTT와 NodeRED 활용성을 증가시켜 시스템 확장성 강화**

- [임베디드 SW 프로그래밍_기말_프로젝트_결과보고서.pdf](https://github.com/user-attachments/files/19530597/SW_Project_SGG.pdf)


