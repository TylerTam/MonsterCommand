// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SelectableEntity.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
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
protected:
	virtual void BeginPlay() override;
public:
	virtual void ToggleHighlight(ESelectableState p_newState) override;

	//Check if the current commander can select this entity
	virtual bool IsSelectable(UCommandManager* p_commander, ECommandState p_commandType)override;

	virtual void Selected()override;

	virtual void MoveToPosition(FVector position)override;
	virtual void MoveToPosition(USelectableEntity* targetEntity)override;
	
};
