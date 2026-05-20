# Assistant Brief

이 파일은 Codex에게 프로젝트 목표, 작업 방식, 우선순위를 알려주는 메모입니다.
원하는 내용을 자연어로 적어두면, 이후 대화에서 이 파일을 기준으로 계획을 세우거나 코드를 작성할 수 있습니다.

## 1. 나의 목표

- 2개월 내에 Deep Learning 응용 이미지 분석 프로그램을 만든다.
- 최종 목표: 학습한 기준 이미지와 입력 이미지를 비교하여 OK / NG 구분
- 최종 목표와 현재 진행 상황을 바탕으로 해야할 일을 수립한다.

## 2. 현재 상황

- 하루에 1시간 정도 작업할 수 있다.
- 대화상자 기반 기초적인 MFC 작업을 보고 이해할 수 있다.
- C++의 클래스, 포인터와 같은 기초적 문법을 알고 있다.
- 영상처리 알고리즘은 대부분 모른다. 

## 3. 원하는 결과물

- visual studio 2026에서 실행 가능한 MFC 대화상자 기반 이미지 분석 프로그램
- 한국어 UI

## 4. 선호하는 작업 방식

- 먼저 전체 계획을 제안하고, 내가 승인하면 코드 작성(중요!)
- 작은 단위로 만들고 매번 실행 확인

## 5. 제약 조건

- 무료 도구와 오픈소스 중심으로 진행

## 6. 이번에 Codex에게 요청할 일

- 테스트용 MFC 프로그램 코드 구조 설계
- Image Processing 폴더에 있는 sample 사진을 입력으로 받음. 
- Image Processing 폴더에 있는 target 사진을 입력으로 받음.
- Target 사진은 우리가 sample에서 찾고자 하는 부분.
- sample 내에 target이 위치한 부분을 사각형으로 마킹하여 출력.
- 해당 코드를 작성한다면, github에 올리기 위한 방법(너가 스스로 할 수 있는지 포함)
- 변수 명을 m_자료형이름 과 같이 변경한다. 예시) m_samplePath -> m_strSamplePath (내가 주석으로 달자)

## 7. 현재 개발 환경

- 확인일: 2026-05-19
- OS: Microsoft Windows 11 Home 64비트 (10.0.26200, 빌드 26200)
- PC/메인보드: BIOSTAR Group A620MS-E
- CPU: AMD Ryzen 5 7500F 6-Core Processor (6코어 / 12스레드)
- RAM: 31.62 GB
- GPU: NVIDIA GeForce RTX 5060 Ti
  - NVIDIA 조회 기준 VRAM: 8151 MiB
  - 드라이버 버전: 595.97
- 저장공간: C: 943.49 GB 중 794.64 GB 여유
- Visual Studio: Visual Studio Community 2026
  - 설치 버전: 18.6.11806.211
  - 표시 버전: 18.6.0
  - 설치 경로: C:\Program Files\Microsoft Visual Studio\18\Community
  - 상태: 설치 완료, 실행 가능
  - C++ 데스크톱 개발 워크로드: 설치 확인
  - MFC/ATL 구성 요소: 설치 확인

## 8. 현재 환경을 반영한 개발 방향

- 현재 PC 사양은 MFC, OpenCV, ONNX Runtime 기반의 이미지 분석 프로그램 개발에 충분하다.
- GPU가 있으므로 딥러닝 학습 또는 추론에서 CUDA/PyTorch 활용을 검토할 수 있다.
- 단, 최종 MFC 프로그램은 처음부터 딥러닝을 바로 붙이기보다 이미지 표시, 전처리, 기본 비교 기능을 먼저 완성한 뒤 ONNX 모델 추론을 붙이는 순서가 적절하다.
- 현재 설치된 버전은 Visual Studio Community 2026이다. 이후 개발은 현재 설치된 버전을 기준으로 진행하되, VS2022 호환성이 꼭 필요하면 별도로 확인한다.

## 사용 예시

대화에서 이렇게 말하면 됩니다.

```text
ASSISTANT_BRIEF.md를 읽고, 내 Planner 프로젝트의 MVP 계획을 세워줘.
```

또는 이렇게 요청할 수 있습니다.

```text
ASSISTANT_BRIEF.md의 내용을 기준으로 첫 번째 개발 작업을 시작해줘.
```
