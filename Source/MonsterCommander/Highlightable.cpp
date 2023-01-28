// Fill out your copyright notice in the Description page of Project Settings.


#include "Highlightable.h"

// Sets default values for this component's properties
UHighlightable::UHighlightable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHighlightable::BeginPlay()
{
	Super::BeginPlay();
	objectMesh = GetOwner()->FindComponentByClass<UMeshComponent>();
	ToggleHighlight(ESelectableState::None);
	// ...
	
}


void UHighlightable::ToggleHighlight(ESelectableState p_newHighlightState) {

	switch (p_newHighlightState) {
	case ESelectableState::None:
		objectMesh->SetCustomDepthStencilValue(0);
		break;
	case ESelectableState::Highlighted:
		objectMesh->SetCustomDepthStencilValue(1);
		break;
	case ESelectableState::Selected:
		objectMesh->SetCustomDepthStencilValue(2);
		break;
	}
	
}
