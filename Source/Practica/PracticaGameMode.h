// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PracticaGameMode.generated.h"

UCLASS(MinimalAPI)
class APracticaGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APracticaGameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	class AEnemigo* Enemigo;
	class AEnemigo* Enemigo2;
	class AEnemigo* Enemigo3;

	class AInventoryCharacter* Player1;

	FTimerHandle TimerHandle;

	TArray<AActor*> Actores;

	void llamarCuadrilla();
};



