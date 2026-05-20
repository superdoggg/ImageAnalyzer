# Assistant Brief

이 파일은 Codex에게 프로젝트 목표, 작업 방식, 우선순위를 알려주는 메모입니다.
원하는 내용을 자연어로 적어두면, 이후 대화에서 이 파일을 기준으로 계획을 세우거나 코드를 작성할 수 있습니다.

## 1. 나의 목표

- 2개월 내에 Deep Learning 응용 이미지 분석 프로그램을 만든다.
- 최종 목표: 학습한 기준 이미지와 입력 이미지를 비교하여 OK / NG 구분
- 현재 단계 목표: MFC 대화상자 기반 프로그램에서 sample 이미지와 target 이미지를 불러오고, OpenCV를 이용해 sample 내부의 target 위치를 찾는다.
- 최종 목표와 현재 진행 상황을 바탕으로 해야 할 일을 작은 단위로 수립한다.

## 2. 현재 상황

- 하루에 1시간 정도 작업할 수 있다.
- 대화상자 기반 기초적인 MFC 작업을 보고 이해할 수 있다.
- C++의 클래스, 포인터와 같은 기초적 문법을 알고 있다.
- 영상처리 알고리즘은 대부분 모른다.
- OpenCV는 아직 익숙하지 않으므로, 기능 구현과 함께 필요한 개념을 단계적으로 학습한다.

## 3. 원하는 결과물

- Visual Studio 2026, Visual Studio 2022 모두에서 실행 가능한 MFC 대화상자 기반 이미지 분석 프로그램
- 한국어 UI
- sample 이미지와 target 이미지를 사용자가 직접 불러올 수 있는 프로그램
- 이후 OpenCV를 이용해 sample 내부에서 target과 유사한 위치를 찾고, 해당 위치를 사각형으로 표시하는 프로그램
- 장기적으로 OK / NG 판정까지 확장 가능한 구조

## 4. 선호하는 작업 방식

- 먼저 전체 계획을 제안하고, 내가 승인하면 코드 작성(중요!)
- 작은 단위로 만들고 매번 실행 확인
- 한 번에 많은 기능을 넣지 않고, 기능 하나를 완성한 뒤 다음 단계로 진행
- 코드 수정 요청 시 요청한 범위 밖의 파일이나 기능은 건드리지 않는다.
- 중요한 결정은 이 파일에 정리해 두고, 이후 대화에서 기준 문서로 사용한다.

## 5. 제약 조건

- 집에서는 무료 도구와 오픈소스 중심으로 진행
- 집 개발 환경에서는 MIL(Matrox Imaging Library / Zebra Aurora Imaging Library)을 사용하기 어렵다고 판단
- 회사에서는 MIL 사용 가능성이 있으므로, 회사 환경에서는 MIL과 OpenCV를 비교 학습할 수 있다.
- 집 프로젝트의 실제 구현은 OpenCV 중심으로 진행한다.

## 6. 지금까지 진행한 내용

- MFC 대화상자 기반 프로젝트 `ImageAnalyzer` 생성
- OpenCV 없이 이미지 파일을 불러와 화면에 표시하는 기본 뼈대 구현
- `sample` 이미지와 `target` 이미지를 직접 선택해서 표시하는 기능 구현
- `LoadDefaultImages()`는 불필요하다고 판단하여 제거
- 멤버 변수명은 자료형 힌트가 드러나도록 정리
  - 예: `m_samplePath` -> `m_strSamplePath`
  - 예: `m_sampleImage` -> `m_imgSample`
- 각 함수와 주요 변수에 간단한 역할 설명 주석 추가
- `sample` 폴더의 각 sample 이미지에서 부분 이미지 target을 3개씩 생성하여 `target` 폴더에 저장
- GitHub 저장소 생성 및 첫 push 완료
  - 저장소: https://github.com/superdoggg/ImageAnalyzer

## 7. MIL 조사 결과와 결정

- MIL은 과거 Matrox Imaging Library이며, 현재는 Zebra Aurora Imaging Library로 제공된다.
- MIL은 오픈소스가 아니며, 평가판 또는 정식 라이선스가 필요한 상용 SDK이다.
- 회사에서는 MIL을 사용할 수 있을 가능성이 있으나, 집에서는 라이선스와 설치 조건 때문에 진행이 어렵다.
- 따라서 집 프로젝트는 OpenCV로 진행하고, 회사에서는 MIL과 OpenCV의 개념을 비교 학습한다.

## 8. OpenCV와 MIL의 관계

- OpenCV의 `Mat`은 MIL의 image buffer와 비슷한 역할로 이해한다.
- OpenCV의 `imread`는 MIL의 image/buffer import 기능과 비슷한 역할로 이해한다.
- OpenCV의 `matchTemplate`은 MIL의 Pattern Matching 기능과 비슷한 목적을 가진다.
- OpenCV의 `rectangle`은 MIL의 graphic annotation 기능과 비슷한 결과 표시 역할을 한다.
- OpenCV는 무료 오픈소스라 집에서 학습과 구현을 진행하기 좋다.
- MIL은 산업 현장과 장비 연동에 강하므로 회사 환경에서 별도로 비교 학습한다.

## 9. OpenCV 기반 개발 계획

### 1단계: 현재 MFC 뼈대 안정화

- sample 이미지와 target 이미지를 사용자가 직접 선택해서 화면에 표시한다.
- 이미지 선택, 초기화, 상태 문구 표시가 정상 동작하는지 확인한다.
- OpenCV 코드는 아직 넣지 않고 MFC UI 흐름을 이해한다.

### 2단계: OpenCV 연결

- OpenCV 설치 및 Visual Studio 프로젝트 설정을 진행한다.
- MFC 코드와 OpenCV 코드를 직접 섞기보다 `ImageProcessor` 클래스를 새로 두는 구조를 사용한다.
- 처음에는 이미지 읽기, 저장, 크기 확인 정도만 OpenCV로 테스트한다.

### 3단계: 이미지 기본 처리 학습 및 구현

- 이미지가 픽셀 배열이라는 개념을 이해한다.
- 좌표 `(x, y)`, width, height, RGB/BGR, grayscale 개념을 학습한다.
- OpenCV의 기본 함수부터 익힌다.
  - `imread`
  - `resize`
  - `cvtColor`
  - `rectangle`
  - `imwrite`

### 4단계: target 위치 찾기

- OpenCV의 `matchTemplate`과 `minMaxLoc` 개념을 학습한다.
- sample 이미지 안에서 target 이미지와 가장 비슷한 위치를 찾는다.
- 찾은 위치, 유사도 점수, target 크기를 이용해 사각형 좌표를 계산한다.
- 결과 이미지를 화면에 표시한다.

### 5단계: OK / NG 기준 만들기

- 유사도 점수가 기준값 이상이면 OK, 낮으면 NG로 판단한다.
- target을 찾지 못하거나 위치가 예상 범위와 다르면 NG로 판단한다.
- 기준값은 처음에는 고정값으로 두고, 이후 UI에서 조정 가능하게 확장한다.

### 6단계: 딥러닝 확장 준비

- OpenCV 기반 비교 기능을 먼저 완성한 뒤 딥러닝으로 확장한다.
- 학습은 Python/PyTorch에서 진행하고, 추론은 ONNX Runtime을 통해 MFC에 연결하는 방향을 검토한다.
- 단, 딥러닝은 OpenCV 기반 MVP가 동작한 뒤 진행한다.

## 10. 코드 구조 원칙

- MFC 대화상자 클래스는 UI만 담당한다.
  - 버튼 클릭
  - 파일 선택
  - 이미지 표시
  - 상태 문구 표시
- 이미지 처리 로직은 별도 클래스로 분리한다.
  - 예: `ImageProcessor`
  - 이후 필요하면 `ImageProcessorOpenCV`, `ImageProcessorMIL`처럼 분리 가능
- 함수 이름은 특정 라이브러리에 너무 묶이지 않게 작성한다.
  - 예: `FindTargetInSample()`
  - 예: `LoadImage()`
  - 예: `DrawResultBox()`
- 집에서는 `ImageProcessorOpenCV`를 구현하고, 회사에서 MIL을 쓸 수 있으면 같은 기능을 `ImageProcessorMIL`로 비교 구현할 수 있다.

## 11. 현재 개발 환경

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

## 12. 다음 작업 후보

- OpenCV를 설치하기 전에 OpenCV 연결 계획만 세우기
- OpenCV 설치 및 프로젝트 설정 방법 정리
- `ImageProcessor` 클래스 설계안 작성
- OpenCV 없이 현재 MFC UI를 조금 더 정리
- OpenCV로 이미지 읽기만 하는 최소 테스트 구현
- OpenCV `matchTemplate` 개념 학습 자료 정리

## 사용 예시

대화에서 이렇게 말하면 됩니다.

```text
ASSISTANT_BRIEF.md를 읽고, 내 ImageAnalyzer 프로젝트의 다음 개발 계획을 세워줘.
```

또는 이렇게 요청할 수 있습니다.

```text
ASSISTANT_BRIEF.md의 내용을 기준으로 첫 번째 OpenCV 연결 작업을 시작해줘.
```
