// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatoformaAcuatica.h"

// Sets default values
APlatoformaAcuatica::APlatoformaAcuatica()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlatoformaAcuatica::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatoformaAcuatica::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatoformaAcuatica::mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, TEXT("clase APlataformaAcuatica trayendo agua"));
}

