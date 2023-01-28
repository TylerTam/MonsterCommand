// Copyright Epic Games, Inc. All Rights Reserved.

#include "MonsterCommanderGameMode.h"
#include "MonsterCommanderCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMonsterCommanderGameMode::AMonsterCommanderGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/MonsterGame/Blueprints/BP_Player"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
