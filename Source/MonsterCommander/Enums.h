// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */


UENUM(BlueprintType)
enum class ETargetType:uint8{
    Position       UMETA(DisplayName = "Position"),
    AttackTarget        UMETA(DisplayName = "AttackTarget"),
    AllyTarget        UMETA(DisplayName = "AllyTarget"),
};



class MONSTERCOMMANDER_API Enums
{
public:
	Enums();
	~Enums();
};
