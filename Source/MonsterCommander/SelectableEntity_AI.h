// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SelectableEntity.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "DA_MonsterBase.h"
#include "Health.h"
#include "SelectableEntity_AI.generated.h"
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MONSTERCOMMANDER_API USelectableEntity_AI : public USelectableEntity
{
	GENERATED_BODY()


private:
	UBlackboardComponent* aiBlackBoard;
	AAIController* aiController;
	UHealth* aiHealth;

protected:
	UPROPERTY(EditAnywhere)
		float enemyTargetStoppingDistance;

public:

	UPROPERTY(BlueprintReadOnly)
		int attackIndex;

	UPROPERTY(EditAnywhere)
		UDA_MonsterBase* monsterData;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		FMonsterStats currentMonsterStats;

	UPROPERTY(EditAnywhere)
		int experience;

	UPROPERTY(EditAnywhere)
		int level;



protected:
	virtual void BeginPlay() override;
	virtual void SetTargetType(ETargetType p_targetType) override;

public:
	virtual void ToggleHighlight(ESelectableState p_newState) override;

	//Check if the current commander can select this entity
	virtual bool IsSelectable(UCommandManager* p_commander, ECommandState p_commandType)override;

	virtual void Selected()override;

	virtual void MoveToPosition(FVector position)override;
	virtual void MoveToPosition(USelectableEntity* targetEntity)override;

	virtual void PerformAttackAtPosition(FVector p_position, int p_attackIndex) override;

	UFUNCTION(BlueprintCallable)
	virtual void InitializeMonster(UDA_MonsterBase* p_monsterBase, int p_monsterLevel, int p_experience);

};
