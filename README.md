# Bulls and Cows

작업기간 : 2025.03.13(목) - 2025.03.25(월)


## 프로젝트 소개

![image](https://github.com/user-attachments/assets/8a045509-ec0f-4418-b233-91ce32087b76)

### Bulls and Cows

'Bulls and Cows'는 숫자야구의 영어식 표기입니다.
이 게임은 숫자야구 게임을 바탕으로 한 텍스트 기반 턴제 퍼즐보드게임입니다.


### 프로젝트 목표
- 실시간 멀티플레이 구현

  플레이어간 소통이 가능한 멀티플레이 구조

- 플레이어간 정보 공유

  게임의 진행과 결과를 플레이어들이 모두 공유하도록 처리


### 기본 룰

- ID를 입력하면 참가자격이 주어집니다.
- 호스트가 게임을 시작할 때까지 ID를 입력하지 않으면 해당 게임엔 참여할 수 없습니다.
- 모든 플레이어에겐 3회의 정답기회와 턴당 10초의 시간이 주어집니다.
- 정답 숫자는 게임 시작 시 임의로 정해집니다.
- 플레이어는 본인의 턴에 3자리의 숫자를 입력하여 정답을 시도할 수 있습니다.
- 정답을 시도할 숫자를 입력할 땐 맨 앞에 '/'를 붙여야합니다.
- 입력된 숫자는 정답 숫자와 비교되어 규칙에 맞는 결과를 얻게됩니다.
- 입력된 숫자 중, 자리는 틀리지만 값은 일치하는 숫자의 개수는 B(볼), 자리와 값 모두 일치는 숫자의 개수는 S(스트라이크)의 앞에 표기됩니다.
- 모든 자리와 값이 일치하는 숫자를 입력하면 1점을 획득하고 해당 게임은 종료됩니다.
- '/'를 붙이면 올바르지 않은 형식의 답을 입력해도 턴은 소모됩니다.
- 턴을 모두 사용하면 아웃처리됩니다.
- '/'를 붙이지 않으면 자유롭게 채팅이 가능합니다.
- 원하는 만큼 게임은 반복할 수 있습니다.

## 프로젝트 내용

### 기본 흐름

![NinthWork-페이지-2 drawio](https://github.com/user-attachments/assets/0bfda761-4c4d-4c6a-b059-4d6d8cd6c791)

### 알고리즘

![NinthWork-Page-1 drawio](https://github.com/user-attachments/assets/523340d9-8a47-475e-869d-546fe9ae5b60)

### 프로젝트 구조

![NinthWork-페이지-3 drawio](https://github.com/user-attachments/assets/955b74bc-e3fd-4da7-8bbf-253f1119b119)


## 구현 기능

- GameMode 서버 로직
  - 채팅을 입력하면 서버에서 내용을 해석하여 판별
- 3자리 난수 생성 로직(중복없는 0-9숫자)
  - 게임 시작 시 서버에서 무작위 3자리 숫자를 만듭니다. 맨 앞자리엔 0이 제외됩니다.
- 판정 로직
  - 서버가 생성한 숫자와 플레이어가 입력한 숫자를 비교하여 스트라이크, 볼을 계산합니다.
- 시도 횟수 및 상태 관리
  - 플레이어는 각각 3번의 기회를 가집니다.
  - 유효하지 않은 입력을 했을 시 턴을 소모합니다.(틀린 자릿수/ 중복된 수/ 숫자가 아닌 문자)
- 승리, 무승부, 리셋
  - 3번 내에 3S를 맞춘 플레이어가 나오면 즉시 승리합니다.
  - 플레이어 모두 아웃되면 무승부 처리됩니다.
  - 승리 혹은 무승부 시 게임을 재시작할 수 있습니다.(숫자 및 시도횟수 리셋)
- C++ 라이브러리 분리
  - 판정과 난수 생성 로직은 별도의 C++ 라이브러리로 분리해서 구현했습니다.
  - GameMode에서는 이 라이브러리를 호출하여 결과를 받아온 후 게임 전체 흐름(채팅 처리, 시도 횟수, 승패 결정 등)을 관리합니다.

- 턴 제어 기능
  - 앞 플레이어의 턴이 끝나야 답을 입력할 수 있습니다.
- 시간 제한
  - 시간 내에 답을 입력하지 않으면 턴이 종료됩니다.
- 스코어보드
  - 플레이어와 점수가 담긴 스코어보드가 표시됩니다.

## 주요 로직

### 정답 숫자 생성 로직

- std::rangom_device로 임의의 시드를 부여한 FMath::RandInit()을 사용해서 숫자생성의 임의성을 강화
- 첫번째 자리에 0이 아닌 1 - 9의 숫자 중 하나를 배치
- 3자리가 채워질때까지 중복되지 않는 임의의 숫자를 배치
- 앞자리에 '/'를 배치하고 총 4자리를 만족하지 못하면 함수 다시 실행
- 조건이 만족되면 결과 반환

### 답 판정 로직

- 답입력 판정 로직에서 플레이어가 답입력을 시도했는지 판단
- 답입력일 시 '/'를 제외한 두번째 자리부터 반복문으로 정답숫자와 차례로 비교
- 정답숫자의 해당 자리에 같은 숫자가 있을 시 스트라이크 카운트 증가
- 해당 자리의 숫자가 정답숫자의 다른 자리에 존재할 시 볼 카운트 증가
- 반복 종료 후 스트라이크 카운트와 볼 카운트 반환

## 제작

서승우(언리얼 2기)
