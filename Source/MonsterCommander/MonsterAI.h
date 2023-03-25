// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "MonsterAI.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERCOMMANDER_API AMonsterAI : public AAIController
{
	GENERATED_BODY()
	
protected:


	FGenericTeamId TeamId;
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& other) const override;


public:
	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }
};
