// Copyright Epic Games, Inc. All Rights Reserved.

#include "PracticaGameMode.h"
#include "PracticaPawn.h"
#include "Enemigo.h"
#include "InventoryCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "InventoryActor.h" 
#include "Plataforma.h"
#include "PlataformaHija.h"
#include "PlataformaTerreste.h"
#include "PlatoformaAcuatica.h"

APracticaGameMode::APracticaGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AInventoryCharacter::StaticClass();
}

void APracticaGameMode::BeginPlay()
{
	Super::BeginPlay();
	APlataformaHija* hija = GetWorld()->SpawnActor<APlataformaHija>(FVector(0, 0, 1000), FRotator::ZeroRotator);
	APlataformaTerreste* terrestre = GetWorld()->SpawnActor<APlataformaTerreste>(FVector(0, 0, 1000), FRotator::ZeroRotator);
	APlatoformaAcuatica* acuatico = GetWorld()->SpawnActor<APlatoformaAcuatica>(FVector(0, 0, 1000), FRotator::ZeroRotator);
	APlataforma* plataforma = GetWorld()->SpawnActor<APlataforma>(FVector(0, 0, 1000), FRotator::ZeroRotator);

	plataforma->mensaje();
	hija->mensaje();
	terrestre->mensaje();
	acuatico->mensaje();



	TArray<APlataforma*> Plataformas;
	APlataforma* plaformaActual;

	int llave = 1;

	for (int i = 0; i < 200; i++) {
		int random = FMath::RandRange(0, 2);
		float RandX = FMath::RandRange(Limites1.X, Limites2.X);
		float RandY = FMath::RandRange(Limites1.Y, Limites2.Y);
		float RandZ = FMath::RandRange(Limites1.Z, Limites2.Z);

		FVector LocacionRandom(RandX, RandY, RandZ);
		if (random == 0) {
			plaformaActual = GetWorld()->SpawnActor<APlataformaTerreste>(LocacionRandom, FRotator::ZeroRotator);

		}
		else if (random == 1) {
			plaformaActual = GetWorld()->SpawnActor<APlatoformaAcuatica>(LocacionRandom, FRotator::ZeroRotator);
		}
		else {
			plaformaActual = GetWorld()->SpawnActor<APlataformaHija>(LocacionRandom, FRotator::ZeroRotator);
		} 
		
		if (plaformaActual) {
			plataformasMap.Add(llave, plaformaActual);
			llave++;
		}
	}

	int16 n =0;

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Catidad %i"), n));


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

	GetWorldTimerManager().SetTimer(ControlEventos, this, &APracticaGameMode::DesaparecerPlataformas, 10.0f, false);
}

void APracticaGameMode::DesaparecerPlataformas()
{
	for (APlataforma* Plat : plataformas)
	{
		float n = plataformas.Num();
		if (Plat) Plat->MeshPlataforma->SetVisibility(false);
	}

	GetWorldTimerManager().SetTimer(ControlEventos, this, &APracticaGameMode::DetenerMovimientos, 5.0f, false);
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
	GetWorldTimerManager().SetTimer(ControlEventos, this, &APracticaGameMode::ReiniciarMovimiento, 4.0f, false);
}

void APracticaGameMode::ReiniciarMovimiento()
{
	GetWorldTimerManager().SetTimer(ControlEventos, this, &APracticaGameMode::IniciarMovimientos, 1.0f, false);
}

void APracticaGameMode::OcultarSiguientePlataforma()
{
}

void APracticaGameMode::destruir()
{
	int random = FMath::RandRange(1, plataformasMap.Num());
	if (plataformasMap.Contains(random)) {
	
		APlatoformaAcuatica* p = Cast<APlatoformaAcuatica>(plataformasMap[random]);
		if (p) p->Destroy();
	}
}




