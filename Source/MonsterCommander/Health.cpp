// Fill out your copyright notice in the Description page of Project Settings.


#include "Health.h"

// Sets default values for this component's properties
UHealth::UHealth()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealth::BeginPlay()
{
	Super::BeginPlay();

	currentHealth = maxHealth;
	isAlive = true;
	
}

void UHealth::TakeDamage(int p_damage) {
	if (!isAlive)return;
	currentHealth -= p_damage;
	if (currentHealth <= 0) {
		OnIDied.Broadcast();
		isAlive = false;
	}
}

void UHealth::Heal(int p_healAmount) {
	if(!isAlive) return;
	currentHealth += p_healAmount;
	if (currentHealth > maxHealth) currentHealth = maxHealth;
}

void UHealth::InitHealth(int p_maxHealth, int p_currentHealth) {
}
