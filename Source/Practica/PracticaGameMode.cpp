// Copyright Epic Games, Inc. All Rights Reserved.

#include "PracticaGameMode.h"
#include "PracticaPawn.h"
#include "Enemigo.h"
#include "InventoryCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "InventoryActor.h" 
#include "Plataforma.h"

APracticaGameMode::APracticaGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AInventoryCharacter::StaticClass();
}

void APracticaGameMode::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(ControlEventos, this, &APracticaGameMode::AparecerPlataformas, 5.0f, false);
}

void APracticaGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APracticaGameMode::AparecerPlataformas()
{
	for (int32 i = 0; i < 200; i++)
	{
		float RandX = FMath::RandRange(Limites1.X, Limites2.X);
		float RandY = FMath::RandRange(Limites1.Y, Limites2.Y);
		float RandZ = FMath::RandRange(Limites1.Z, Limites2.Z);
		FVector LocacionRandom(RandX, RandY, RandZ);

		APlataforma* NuevaPlataforma = GetWorld()->SpawnActor<APlataforma>( LocacionRandom, FRotator::ZeroRotator);

		if (NuevaPlataforma) plataformas.Add(NuevaPlataforma);
	}
	GetWorldTimerManager().SetTimer(ControlEventos, this, &APracticaGameMode::IniciarMovimientos, 1.0f, false);
}

void APracticaGameMode::IniciarMovimientos()
{
	for (int32 i = 0; i < plataformas.Num(); i++)
	{
		APlataforma* Plat = plataformas[i];
		if (!Plat) continue;

		int32 TipoMovimiento = i % 10;
		FVector Direccion;

		switch (TipoMovimiento){
		case 0: Direccion = FVector(1, 0, 0); break;   
		case 1: Direccion = FVector(0, 1, 0); break;   
		case 2: Direccion = FVector(0, 0, 1); break;   
		case 3: Direccion = FVector(1, 1, 0); break;   
		case 4: Direccion = FVector(1, -1, 0); break;  
		case 5: Direccion = FVector(1, 0, 1); break;   
		case 6: Direccion = FVector(1, 0, -1); break;  
		case 7: Direccion = FVector(0, 1, 1); break;   
		case 8: Direccion = FVector(0, 1, -1); break;  
		case 9: Direccion = FVector(1, 1, 1); break;
		}

		Plat->DistanciaMover = FMath::RandRange(300.0f, 1500.0f);

		float RapidezAleatoria = FMath::RandRange(150.0f, 400.0f);
		Plat->VelocidadPlataforma = Direccion.GetSafeNormal() * RapidezAleatoria;
	}

	GetWorldTimerManager().SetTimer(ControlEventos, this, &APracticaGameMode::DesaparecerPlataformas, 1.0f, true);
}

void APracticaGameMode::DesaparecerPlataformas()
{
		int random = FMath::RandRange(0, plataformas.Num());
		if (plataformas[random]) plataformas[random]->MeshPlataforma->SetVisibility(false);
		//if (Plat) Plat->MeshPlataforma->SetVisibility(false);

	//GetWorldTimerManager().SetTimer(ControlEventos, this, &APracticaGameMode::DetenerMovimientos, 5.0f, false);
}

void APracticaGameMode::DetenerMovimientos()
{
	for (APlataforma* Plat : plataformas)
	{
		if (Plat) {
			Plat->MeshPlataforma->SetVisibility(true);
			Plat->VelocidadPlataforma = FVector::ZeroVector;
		}

	}
}



