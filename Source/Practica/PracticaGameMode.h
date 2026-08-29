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
	
	FVector Limites1 = FVector(-2290, -2210, 490);
	FVector Limites2 = FVector(2090, 1940, 1890);

	TArray<class APlataforma*> plataformas;
	FTimerHandle ControlEventos;

	void AparecerPlataformas();
	
	void IniciarMovimientos();

	void DesaparecerPlataformas();

	void DetenerMovimientos();

	void desaparecer1();
	void desaparecer2();
};



