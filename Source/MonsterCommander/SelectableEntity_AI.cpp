// Fill out your copyright notice in the Description page of Project Settings.

#include "SelectableEntity_AI.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Enums.h"
#include "DrawDebugHelpers.h"


void USelectableEntity_AI::BeginPlay() {
	USelectableEntity::BeginPlay();

	aiController = UAIBlueprintHelperLibrary::GetAIController(GetOwner());
	
	///////////////////////// .this is causing the spawning crash (Note: The crash was because a controller was trying to be fetched,  
	// but the AI did not have the controller automatically assigned when it was spawned in the editor, thus a null ptr
	//APawn* actorPawn = Cast<APawn>(GetOwner());
	//if (actorPawn == nullptr) {
	//	UE_LOG(LogTemp, Warning, TEXT("actor is null"));
	//	return;
	//}
	//AController* aCont = actorPawn->GetController();
	//if (aCont == nullptr) {
	//	UE_LOG(LogTemp, Warning, TEXT("controlleris null"));
	//	return;
	//}
	//aiController = Cast<AAIController>(aCont);
	//if (aiController == nullptr) {
	//	UE_LOG(LogTemp, Warning, TEXT("AI Cont is null"));
	//	return;
	//}
	/////////////////////////////////

	aiBlackBoard = aiController->GetBlackboardComponent();
	aiHealth = GetOwner()->FindComponentByClass<UHealth>();
	
}

void USelectableEntity_AI::InitializeMonster(UDA_MonsterBase* p_monsterBase, int p_monsterLevel, int p_experience) {


	monsterData = p_monsterBase;
	experience = p_experience;
	level = p_monsterLevel-1;

	currentMonsterStats = monsterData->levelStats[level];

	aiHealth->InitHealth(currentMonsterStats.health, currentMonsterStats.health);

	USkeletalMeshComponent* skeletalMesh = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
	
	skeletalMesh->SetSkeletalMesh(monsterData->monsterMesh);
	skeletalMesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	//Why cant I dereference a dataasset?
	//UDA_MonsterBase anim = *monsterData;

	//Since UAnimBlueprint doesnt inherit from UClass, you have to get the UClass variant of it, which is the generatedClass
	if (monsterData->monsterAnimBlueprint == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Anim blueprint is null"));
	}
	else {
		skeletalMesh->SetAnimInstanceClass(monsterData->monsterAnimBlueprint->GetAnimBlueprintGeneratedClass());
	}
}

void USelectableEntity_AI::ToggleHighlight(ESelectableState p_newState) {
	USelectableEntity::ToggleHighlight(p_newState);
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
	aiBlackBoard->SetValueAsEnum(FName("CommandType"), (uint8)ECommandType::MoveTo);
	SetTargetType(ETargetType::Position);
}
void USelectableEntity_AI::MoveToPosition(USelectableEntity* targetEntity) {

	FVector targetPos = targetEntity->GetOwner()->GetActorLocation();
	FVector newPos = GetOwner()->GetActorLocation();
	newPos = (newPos - targetPos).GetUnsafeNormal();
	newPos.Z = 0;
	newPos = targetPos + ( newPos * enemyTargetStoppingDistance) ;

	
	aiBlackBoard->SetValueAsVector(FName("TargetPos"), newPos);
	aiBlackBoard->SetValueAsBool(FName("OrderGiven"), true);
	aiBlackBoard->SetValueAsEnum(FName("CommandType"), (uint8)ECommandType::MoveTo);
	SetTargetType(ETargetType::AttackTarget);

}
void USelectableEntity_AI::SetTargetType(ETargetType p_targetType) {
	USelectableEntity::SetTargetType(p_targetType);
	aiBlackBoard->SetValueAsEnum(FName("TargetType"), (uint8)p_targetType);
}

void USelectableEntity_AI::PerformAttackAtPosition(FVector p_position, int p_attackIndex) {
	FVector targetPos = p_position;
	FVector newPos = GetOwner()->GetActorLocation();
	newPos = (newPos - targetPos).GetUnsafeNormal();
	newPos.Z = 0;
	newPos = targetPos + (newPos * enemyTargetStoppingDistance);

	attackIndex = p_attackIndex;
	aiBlackBoard->SetValueAsVector(FName("TargetPos"), newPos);
	aiBlackBoard->SetValueAsBool(FName("OrderGiven"), true);
	aiBlackBoard->SetValueAsEnum(FName("CommandType"), (uint8)ECommandType::AttackAt);
	aiBlackBoard->SetValueAsInt(FName("AttackIndex"), p_attackIndex);
}
