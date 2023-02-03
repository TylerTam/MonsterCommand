// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SelectableEntity.h"
#include "Highlightable.generated.h"




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MONSTERCOMMANDER_API UHighlightable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHighlightable();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
		void ToggleHighlight(ESelectableState p_newHighlightState);

protected:
	UPROPERTY(EditAnywhere)
	UMeshComponent* objectMesh;

};
