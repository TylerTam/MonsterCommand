// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAttributeSet.h"
#include "Net/UnrealNetwork.h"

UMonsterAttributeSet::UMonsterAttributeSet()
{
}

void UMonsterAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME_CONDITION_NOTIFY(UMonsterAttributeSet, Health, COND_None, REPNOTIFY_Always);

}

void UMonsterAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMonsterAttributeSet, Health, OldHealth);
}
