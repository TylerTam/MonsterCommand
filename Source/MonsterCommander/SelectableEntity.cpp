// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectableEntity.h"
#include "Highlightable.h"
#include "Enums.h"

// Sets default values
USelectableEntity::USelectableEntity()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts or when spawned
void USelectableEntity::BeginPlay()
{
	Super::BeginPlay();
	outlineComponent = GetOwner() -> FindComponentByClass<UHighlightable>();
	
	
}

void USelectableEntity::ToggleHighlight(ESelectableState p_newState) {
	
	if (outlineComponent != nullptr) outlineComponent->ToggleHighlight(p_newState);

}

bool USelectableEntity::IsSelectable(UCommandManager* p_commander, ECommandState p_commandType) {
	switch (p_commandType)
	{
	case Selecting:
		break;
	case SelectTarget:
		break;
	case SelectOrderAtTarget:
		break;
	default:
		break;
	}
	return canSelect;
}

void USelectableEntity::Selected() {
}

void USelectableEntity::MoveToPosition(USelectableEntity* p_target) {
	target = p_target;
	
	GetOwner()->SetActorLocation(p_target->GetOwner()->GetActorLocation());
	//UE_LOG(LogTemp, Log, TEXT("Moving to target: %s"), *p_target->GetOwner()->GetActorNameOrLabel());
}

void USelectableEntity::MoveToPosition(FVector position) {
	positionOrderLocation = position;
	//UE_LOG(LogTemp, Log, TEXT("Moving to position: %s"), *position.ToString());
	GetOwner()->SetActorLocation(position);
	
}

void  USelectableEntity::SetTargetType(ETargetType p_targetType) {
	targetType = p_targetType;
}






