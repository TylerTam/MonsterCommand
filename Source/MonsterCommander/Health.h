// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Health.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeadEventTrigger);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MONSTERCOMMANDER_API UHealth : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	virtual void TakeDamage(int p_damageTaken);

	UFUNCTION(BlueprintCallable)
	virtual void Heal(int p_healAmount);


	UPROPERTY(BlueprintAssignable, Category = "Custom/Health")
	FOnDeadEventTrigger OnIDied;

public:
	int maxHealth;

private:
	int currentHealth;
	bool isAlive;
		
	
};
