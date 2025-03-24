# Bulls and Cows

작업기간 : 2025.03.13(목) - 2025.03.25(월)


## 프로젝트 소개

![image](https://github.com/user-attachments/assets/8a045509-ec0f-4418-b233-91ce32087b76)

### BUlls and Cows

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

![NinthWork-페이지-3 drawio](https://github.com/user-attachments/assets/ec9af11e-1fc9-47a1-afee-5f80735df52f)

## 주요 로직

### 정답 숫자 생성 로직

- std::rangom_device로 임의의 시드를 부여한 FMath::RandInit()을 사용해서 숫자생성의 임의성을 강화
- 첫번째 자리에 0이 아닌 1 - 9의 숫자 중 하나를 배치
- 3자리가 채워질때까지 중복되지 않는 임의의 숫자를 배치
- 앞자리에 '/'를 배치하고 총 4자리를 만족하지 못하면 함수 다시 실행
- 조건이 만족되면 결과 반환

FString UMake3RandNum::Make3RandNum()
{
	FString GoalNumber = "";
	std::random_device randDevice;
	FMath::RandInit(randDevice());

	while (GoalNumber.IsEmpty())
	{
		int32 RandomNumber = FMath::RandRange(0, 9);
		if (RandomNumber != 0)
		{
			GoalNumber.AppendInt(RandomNumber);
		}
	}

	while (GoalNumber.Len() <= 2)
	{
		bool bIsUnique = true;
		int32 RandomNumber = FMath::RandRange(0, 9);

		for (int i = 0; i < GoalNumber.Len(); i++)
		{
			if (GoalNumber[i] == TCHAR('0' + RandomNumber))
			{
				bIsUnique = false;
				break;
			}
		}

		if (bIsUnique)
		{
			GoalNumber.AppendInt(RandomNumber);
		}
	}

	GoalNumber.InsertAt(0, TEXT("/"));

	if (GoalNumber.Len() != 4)
	{
		Make3RandNum();
	}

	return GoalNumber;
}


### 답 판정 로직

