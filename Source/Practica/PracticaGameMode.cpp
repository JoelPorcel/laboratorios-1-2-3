// Copyright Epic Games, Inc. All Rights Reserved.

#include "PracticaGameMode.h"
#include "PracticaPawn.h"
#include "Enemigo.h"
#include "InventoryCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "InventoryActor.h" 

APracticaGameMode::APracticaGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AInventoryCharacter::StaticClass();
}

void APracticaGameMode::BeginPlay()
{
	Super::BeginPlay();
	Enemigo = GetWorld()->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), FVector(-430, -220,250), FRotator::ZeroRotator);
	Enemigo2 = GetWorld()->SpawnActor<AEnemigo>(AEnemigo::StaticClass(),FVector(-430, 60, 250), FRotator::ZeroRotator);
	Enemigo3 = GetWorld()->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), FVector(-430, 800, 250), FRotator::ZeroRotator);
	Player1 = Cast<AInventoryCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	AInventoryActor* InventoryItem = GetWorld()->SpawnActor<AInventoryActor>(FVector(0,0,0), FRotator::ZeroRotator);
	AInventoryActor* InventoryItem2 = GetWorld()->SpawnActor<AInventoryActor>(FVector(0, 0, 0), FRotator::ZeroRotator);
	Player1->TakeItem(InventoryItem);
	Player1->TakeItem(InventoryItem2);

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &APracticaGameMode::llamarCuadrilla, 5.0f, false);
	Actores.Add(Enemigo);
	Actores.Add(Enemigo2);
	Actores.Add(Enemigo3);
}

void APracticaGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APracticaGameMode::llamarCuadrilla()
{
	for (AActor* actor : Actores) {
		actor->Destroy();
	}
	AEnemigo* Enemigo4 = GetWorld()->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), FVector(-430, -220, 250), FRotator::ZeroRotator);
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("Llamando a la cuadrilla"));
}

