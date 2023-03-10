// Fill out your copyright notice in the Description page of Project Settings.

#include "SelectableEntity_AI.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Enums.h"
#include "DrawDebugHelpers.h"


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
	aiBlackBoard->SetValueAsBool(FName("OrderGiven"), true);
	SetTargetType(ETargetType::Position);
}
void USelectableEntity_AI::MoveToPosition(USelectableEntity* targetEntity) {

	FVector targetPos = targetEntity->GetOwner()->GetActorLocation();
	FVector newPos = GetOwner()->GetActorLocation();

	newPos = (newPos - targetPos).GetUnsafeNormal();

	newPos.Z = 0;
	
	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), GetOwner()->GetActorLocation() + newPos, FColor::Red, false, 1);
	newPos = targetPos + ( newPos * enemyTargetStoppingDistance) ;
	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), newPos, FColor::Cyan,false, 1);
	aiBlackBoard->SetValueAsVector(FName("TargetPos"), newPos);
	aiBlackBoard->SetValueAsBool(FName("OrderGiven"), true);
	SetTargetType(ETargetType::AttackTarget);

}
void USelectableEntity_AI::SetTargetType(ETargetType p_targetType) {
	USelectableEntity::SetTargetType(p_targetType);
	aiBlackBoard->SetValueAsEnum(FName("TargetType"), (uint8)p_targetType);
	
}
