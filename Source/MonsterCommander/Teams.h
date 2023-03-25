// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */


UENUM(BlueprintType)
enum class ETeamTypeId :uint8 {
    Neutral = 0 UMETA(DisplayName = "Neutral"),
    Player = 1 UMETA(DisplayName = "Player"),
    EnemyCommander = 2 UMETA(DisplayName = "Enemy Commander"),
    Wild = 3 UMETA(DisplayName = "Wild")
};



class MONSTERCOMMANDER_API Teams
{
public:
    Teams();
	~Teams();
};
