// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GenericTeamAgentInterface.h"
#include "TeamAttitudeManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MONSTERCOMMANDER_API UTeamAttitudeManager : public UActorComponent, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTeamAttitudeManager();


	FGenericTeamId TeamId;
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& other) const override;


public:
	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }
};
