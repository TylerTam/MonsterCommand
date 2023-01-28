// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandManager.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Highlightable.h"

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
	FindSelectables();
	
}

void UCommandManager::SelectPressed() {

	switch (currentCommandState) {
		case ECommandState::Selecting:

			if (currentHighlightedActor != nullptr) {
				UE_LOG(LogTemp, Display, TEXT("Hit Actor: %s"), *currentHighlightedActor->GetActorNameOrLabel());
				currentHighlightedActor->FindComponentByClass<UHighlightable>()->ToggleHighlight(ESelectableState::Selected);
			}
			break;
		case ECommandState::GiveOrder:
			break;
		case ECommandState::SelectAttack:
			break;
	}

}

void UCommandManager::SelectReleased() {
	if (currentHighlightedActor == nullptr) return;
	currentHighlightedActor->FindComponentByClass<UHighlightable>()->ToggleHighlight(ESelectableState::Highlighted);
}

void UCommandManager::FindSelectables() {
	FVector start, end;

	start = GetComponentLocation();
	end = start + camera->GetCameraRotation().Vector() * castDistance;
	DrawDebugLine(GetWorld(), start, end, FColor::Red);


	FHitResult res;
	FCollisionShape sphere = FCollisionShape::MakeSphere(castRadius);
	if (GetWorld()->SweepSingleByChannel(res, start, end, FQuat::Identity, ECC_GameTraceChannel1, sphere)) {

		DrawDebugSphere(GetWorld(), start + camera->GetCameraRotation().Vector() * res.Distance, castRadius, 16, FColor::Red);
		AActor* actor = res.GetActor();
		if (currentHighlightedActor != nullptr) {

		}
		if (currentHighlightedActor == actor) {
			return;
		}
		currentHighlightedActor = res.GetActor();//->FindComponentByClass<UHighlightable>();
		currentHighlightedActor->FindComponentByClass<UHighlightable>()->ToggleHighlight(ESelectableState::Highlighted);
	}
	else {
		if (currentHighlightedActor != nullptr) {
			currentHighlightedActor->FindComponentByClass<UHighlightable>()->ToggleHighlight(ESelectableState::None);
			currentHighlightedActor = nullptr;
		}
	}
}