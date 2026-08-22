// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"

// Sets default values
AEnemigo::AEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if(MeshAsset.Succeeded()) MeshComponent->SetStaticMesh(MeshAsset.Object);
	SetRootComponent(MeshComponent);

}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	posicionInicialY = GetActorLocation() + FVector(0.0f, 220.0f, 0.0f);
	posicionActualY = posicionInicialY;
	posicionFinalY = posicionActualY + FVector(0.0f, -480.0f, 0.0f);
	incremento = 10.0f;
	moverse = true;
	SetMoverseY(true);
	
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	movimientoY();

}

void AEnemigo::movimientoY()
{
	if (GetMoverseY()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Moviendose hacia abajo"));
		if (moverse)
		{
			if (posicionActualY.Y > posicionFinalY.Y) posicionActualY.Y -= incremento;
			else moverse = false;
		}
		else
		{
			if (posicionActualY.Y < posicionInicialY.Y) posicionActualY.Y += incremento;
			else moverse = true;
		}

		SetActorLocation(posicionActualY);
	}
}

