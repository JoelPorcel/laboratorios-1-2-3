// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaTerreste.h"

// Sets default values
APlataformaTerreste::APlataformaTerreste()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlataformaTerreste::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlataformaTerreste::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlataformaTerreste::mensaje()
{
	Super::mensaje();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("clase APlataformaTerreste preparandose para contruir una montania"));
}

