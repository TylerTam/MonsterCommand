// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAI.h"



ETeamAttitude::Type AMonsterAI::GetTeamAttitudeTowards(const AActor& other) const {
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