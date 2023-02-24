// Fill out your copyright notice in the Description page of Project Settings.

#include "SelectableEntity_AI.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"


void USelectableEntity_AI::BeginPlay() {
	USelectableEntity::BeginPlay();
	aiController = UAIBlueprintHelperLibrary::GetAIController(GetOwner());
	aiBlackBoard = aiController->GetBlackboardComponent();
}
void USelectableEntity_AI::ToggleHighlight(ESelectableState p_newState) {
	USelectableEntity::ToggleHighlight(p_newState);
	UE_LOG(LogTemp, Warning, TEXT("HERERERERE: Toggle"));
}


bool USelectableEntity_AI::IsSelectable(UCommandManager* p_commander, ECommandState p_commandType) {
	return USelectableEntity::IsSelectable(p_commander, p_commandType);
}

void USelectableEntity_AI::Selected() {
	USelectableEntity::Selected();
}

void USelectableEntity_AI::MoveToPosition(FVector position) {
	//USelectableEntity::MoveToPosition(position);
	aiBlackBoard->SetValueAsVector(FName("TargetPos"), position);
}
void USelectableEntity_AI::MoveToPosition(USelectableEntity* targetEntity) {
	USelectableEntity::MoveToPosition(targetEntity);
}