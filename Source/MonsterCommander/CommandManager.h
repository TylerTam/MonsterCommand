// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CommandManager.generated.h"

class USelectableEntity;


UENUM(BlueprintType)
enum ECommandState{
	Selecting,
	SelectTarget,
	SelectOrderAtTarget,
	SelectOrderAtLocation
};

UENUM(BlueprintType)
enum ECommandType {
	MoveTo,
	AttackAt
};




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MONSTERCOMMANDER_API UCommandManager : public USceneComponent
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	UCommandManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SelectPressed();	


	UFUNCTION(BlueprintCallable)
	void SummonPressed();	
	
	UFUNCTION(BlueprintCallable)
	void ReturnMonsterPressed();	
	
	UFUNCTION(BlueprintCallable)
	void AttackPressed(int p_attackIndex);

	UFUNCTION(BlueprintCallable)
	void SelectReleased();	
	
	UFUNCTION(BlueprintCallable)
	void ClearOrder();

private:
	void OutlineSelectables();

	void PerformSelect();


	void PerformTargetSelect();

	void PerformMoveOrder(ECommandState p_commandState);

	bool PerformSphereSweep(FHitResult& p_res, float p_dis, float p_rad, ECollisionChannel p_channel);

	void PerformAttackOrder(ECommandState p_commandState, int p_attackIndex);

private:
	UPROPERTY(EditAnywhere)
	float castRadius = 25;	

	UPROPERTY(EditAnywhere)
	float castDistance = 1000;
	
	UPROPERTY(EditAnywhere)
		float moveOrderCastDis = 2000;
	
	
	

	APlayerCameraManager* camera;
	TEnumAsByte<ECommandState> currentCommandState = ECommandState::Selecting;


	USelectableEntity* currentHighlightedEntity;

	//The entity you are going to give a command to
	USelectableEntity* currentSelectedEntity;

	//If you have selected an entity, this would be the entity you select for yours to attack / heal
	USelectableEntity* currentSecondSelectedEntity;

	FVector orderAtLocation;
		
};
