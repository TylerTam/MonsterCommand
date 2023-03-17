// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_MonsterBase.generated.h"


USTRUCT(BlueprintType)
struct FMonsterStats {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int attack;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int defense;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int health;
};
/**
 * 
 */
UCLASS()
class MONSTERCOMMANDER_API UDA_MonsterBase : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		AActor* monsterActor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString monsterName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		USkeletalMesh* monsterMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UAnimBlueprint* monsterAnimBlueprint;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FMonsterStats> levelStats;
};
