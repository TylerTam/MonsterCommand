// Fill out your copyright notice in the Description page of Project Settings.


#include "TeamAttitudeManager.h"

// Sets default values for this component's properties
UTeamAttitudeManager::UTeamAttitudeManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


ETeamAttitude::Type UTeamAttitudeManager::GetTeamAttitudeTowards(const AActor& other) const {
	UE_LOG(LogTemp, Warning, TEXT("Checking Attitude"));
	return ETeamAttitude::Friendly;
	const APawn* OtherPawn = Cast<APawn>(&other);
	if (OtherPawn == nullptr) return ETeamAttitude::Neutral;

	auto TeamInterface = Cast<IGenericTeamAgentInterface>(&other);
	class IGenericTeamAgentInterface* BTI = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController());

	if (TeamInterface == nullptr && BTI == nullptr) return ETeamAttitude::Neutral;

	FGenericTeamId otherActorTeam = NULL;
	if (BTI == nullptr) otherActorTeam = TeamInterface->GetGenericTeamId();
	else if (TeamInterface == nullptr) otherActorTeam = BTI->GetGenericTeamId();

	FGenericTeamId thisId = GetGenericTeamId();

	if (otherActorTeam == 0) return ETeamAttitude::Neutral;
	if (otherActorTeam == thisId) return ETeamAttitude::Friendly;
	return ETeamAttitude::Hostile;

}

