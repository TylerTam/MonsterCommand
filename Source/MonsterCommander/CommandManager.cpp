// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandManager.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Highlightable.h"
#include "SelectableEntity_AI.h"
#include "SelectableEntity.h"




// Sets default values for this component's properties
UCommandManager::UCommandManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCommandManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	camera = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
}


// Called every frame
void UCommandManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	OutlineSelectables();
	
}


void UCommandManager::OutlineSelectables() {
	FHitResult res;
	if (PerformSphereSweep(res, castDistance, castRadius, ECC_GameTraceChannel1)) {
		USelectableEntity* entity = res.GetActor()->FindComponentByClass<USelectableEntity>();

		if (entity == nullptr) return;
		if (currentHighlightedEntity != nullptr) {
			if (currentHighlightedEntity== entity) {
				return;
			}
		}

		if (entity == currentSelectedEntity || entity == currentSecondSelectedEntity) return;
		currentHighlightedEntity = entity;
		currentHighlightedEntity->ToggleHighlight(ESelectableState::Highlighted);
	}
	else {
		if (currentHighlightedEntity != nullptr) {

			if (currentHighlightedEntity == currentSelectedEntity || currentHighlightedEntity == currentSecondSelectedEntity) return;

			currentHighlightedEntity->ToggleHighlight(ESelectableState::None);
			currentHighlightedEntity = nullptr;

		}
	}
}

bool UCommandManager::PerformSphereSweep(FHitResult& p_res, float p_dis, float p_rad, ECollisionChannel p_channel) {

	FVector start, end;

	start = GetComponentLocation();
	end = start + camera->GetCameraRotation().Vector() * castDistance;
	DrawDebugLine(GetWorld(), start, end, FColor::Red);

	FCollisionShape sphere = FCollisionShape::MakeSphere(castRadius);
	if (GetWorld()->SweepSingleByChannel(p_res, start, end, FQuat::Identity, p_channel, sphere)) {
		DrawDebugSphere(GetWorld(), start + camera->GetCameraRotation().Vector() * p_res.Distance, castRadius, 16, FColor::Red);
		return true;
	}

	return false;
}

#pragma region Input

void UCommandManager::SummonPressed() {

	if (spawnedMonster != nullptr) {
		ReturnMonsterPressed();
	}

	FVector pos;
	FHitResult res;
	if (PerformSphereSweep(res, moveOrderCastDis, castRadius, ECC_GameTraceChannel2)) {
		pos = res.Location;
	}
	else {
		FVector start, end;

		pos = GetComponentLocation();
		pos = start + camera->GetCameraRotation().Vector() * castDistance;
	}
	
	FActorSpawnParameters spawnInfo;
	spawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	pos = pos + FVector(0, 50, 0);
	spawnedMonster = GetWorld()->SpawnActor<AActor>(spawnedActor,pos, FRotator::ZeroRotator);
	

	spawnedMonster->FindComponentByClass<USelectableEntity_AI>()->InitializeMonster(tempMonsterBase, 1, 0);

}

void UCommandManager::ReturnMonsterPressed() {
	if (spawnedMonster != nullptr) {
		spawnedMonster->Destroy();
		spawnedMonster = nullptr;
	}
}

void UCommandManager::SelectPressed() {

	switch (currentCommandState) {
		case ECommandState::Selecting:

			PerformSelect();
			break;
		case ECommandState::SelectTarget:
			PerformTargetSelect();
			break;
		case ECommandState::SelectOrderAtTarget:
		case ECommandState ::SelectOrderAtLocation:
			PerformMoveOrder(currentCommandState);
			break;
	}
}

void UCommandManager::AttackPressed(int p_attackIndex) {
	switch (currentCommandState) {

		case ECommandState::SelectOrderAtTarget:
		case ECommandState::SelectOrderAtLocation:
			PerformAttackOrder(currentCommandState, p_attackIndex);
			break;
	}
}

void UCommandManager::SelectReleased() {
	if (currentHighlightedEntity == nullptr) return;
	if (currentHighlightedEntity == currentSelectedEntity || currentHighlightedEntity == currentSecondSelectedEntity) return;
	currentHighlightedEntity->ToggleHighlight(ESelectableState::Highlighted);
	
}


void UCommandManager::ClearOrder() {
	//UE_LOG(LogTemp, Log, TEXT("Cleared Order"));
	if (currentSelectedEntity != nullptr) {
		currentSelectedEntity->ToggleHighlight(ESelectableState::None);
		currentSelectedEntity = nullptr;
	}
	if (currentSecondSelectedEntity != nullptr) {
		currentSecondSelectedEntity->ToggleHighlight(ESelectableState::None);
		currentSecondSelectedEntity = nullptr;
	}
	currentCommandState = ECommandState::Selecting;
}


#pragma endregion

#pragma region Commands
void UCommandManager::PerformSelect() {
	if (currentHighlightedEntity != nullptr) {

		if (!currentHighlightedEntity->IsSelectable(this, ECommandState::Selecting))return;
		currentHighlightedEntity->ToggleHighlight(ESelectableState::Selected);
		currentSelectedEntity = currentHighlightedEntity;
		currentCommandState = ECommandState::SelectTarget;
	}
}

void UCommandManager::PerformTargetSelect() {

	currentCommandState = ECommandState::Selecting;
	if (currentSelectedEntity == nullptr) return;

	

	//If there is a current highlighted entity that isnt the selected one
	if (currentHighlightedEntity != nullptr && currentHighlightedEntity != currentSelectedEntity) {
		currentSecondSelectedEntity = currentHighlightedEntity;
		currentSecondSelectedEntity->ToggleHighlight(ESelectableState::Selected);
		currentCommandState = ECommandState::SelectOrderAtTarget;
	}

	//If no current highlighted entity
	else {
		FHitResult res;
		if (PerformSphereSweep(res, moveOrderCastDis, castRadius, ECC_GameTraceChannel2)) {
			orderAtLocation = res.Location;
			currentCommandState = ECommandState::SelectOrderAtLocation;
		}
		else {
			ClearOrder();
		}
	}

}

void UCommandManager::PerformMoveOrder(ECommandState p_commandState) {
	switch (p_commandState) {
		case ECommandState::SelectOrderAtLocation:
			currentSelectedEntity->MoveToPosition(orderAtLocation);
			break;

		case ECommandState::SelectOrderAtTarget:
			currentSelectedEntity->MoveToPosition(currentSecondSelectedEntity);
			break;
	}

	ClearOrder();
}

void UCommandManager::PerformAttackOrder(ECommandState p_commandState, int p_attackIndex) {
	switch (p_commandState) {
	case ECommandState::SelectOrderAtLocation:
		currentSelectedEntity->PerformAttackAtPosition(orderAtLocation, p_attackIndex);
		break;

	case ECommandState::SelectOrderAtTarget:
		currentSelectedEntity->PerformAttackAtPosition(currentSecondSelectedEntity->GetOwner()->GetActorLocation(), p_attackIndex);
		break;
	}

	ClearOrder();
}
#pragma endregion