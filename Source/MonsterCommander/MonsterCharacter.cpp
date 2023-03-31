// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterCharacter.h"
#include "AbilitySystemComponent.h"
#include "MonsterAttributeSet.h"

// Called when the game starts or when spawned
void AMonsterCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMonsterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMonsterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Sets default values
AMonsterCharacter::AMonsterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("MonsterAbilitySystemComp");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	Attributes = CreateDefaultSubobject<UMonsterAttributeSet>("MonsterAttributes");
}

UAbilitySystemComponent* AMonsterCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AMonsterCharacter::PossessedBy(AController* newController)
{
	Super::PossessedBy(newController);
	if (AbilitySystemComponent) {
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
	InitializeAttributes();

	//Only done on server
	GiveDefaultAbilities();
}

void AMonsterCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if (AbilitySystemComponent) {
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
	InitializeAttributes();
}

void AMonsterCharacter::InitializeAttributes()
{
	if (AbilitySystemComponent && DefaultAttributeEffect) {
		FGameplayEffectContextHandle effectContext = AbilitySystemComponent->MakeEffectContext();
		effectContext.AddSourceObject(this);
		FGameplayEffectSpecHandle specHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1, effectContext);

		if (specHandle.IsValid()) {
			FActiveGameplayEffectHandle GEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*specHandle.Data.Get());
		}
	}
}

void AMonsterCharacter::GiveDefaultAbilities()
{
	if (HasAuthority() && AbilitySystemComponent) {
		for (TSubclassOf<UGameplayAbility>& startupAbility : DefaultAbilities) {
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(startupAbility.GetDefaultObject(),1,0));
		}
	}
}

