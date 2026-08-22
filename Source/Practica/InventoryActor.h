// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InventoryActor.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICA_API AInventoryActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
	AInventoryActor();

public:
	virtual void PickUp();
	virtual void PutDown(FTransform TargetLocation);

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComponent;
};
