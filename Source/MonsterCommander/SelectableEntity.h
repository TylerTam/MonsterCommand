// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CommandManager.h"
#include "SelectableEntity.generated.h"

class UHighlightable;


UENUM(BlueprintType)
enum ESelectableState {
	None,
	Highlighted,
	Selected
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MONSTERCOMMANDER_API USelectableEntity : public UActorComponent
{
	GENERATED_BODY()
	

public:	
	// Sets default values for this actor's properties
	USelectableEntity();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	virtual void ToggleHighlight(ESelectableState p_newState);

	//Check if the current commander can select this entity
	virtual bool IsSelectable(UCommandManager* p_commander, ECommandState p_commandType);

	virtual void Selected();

	virtual void MoveToPosition(FVector position);
	virtual void MoveToPosition(USelectableEntity* targetEntity);


private:
	UHighlightable* outlineComponent;

	UPROPERTY(EditAnywhere)
		bool canSelect;

	FVector positionOrderLocation;
	USelectableEntity* target;
};
