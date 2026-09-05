// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaHija.h"

APlataformaHija::APlataformaHija()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset2(TEXT("StaticMesh'/Game/StarterContent/Architecture/Floor_400x400.Floor_400x400'"));
	if (MeshAsset2.Succeeded())
	{
		MeshPlataforma->SetStaticMesh(MeshAsset2.Object);
		UE_LOG(LogTemp, Warning, TEXT("Malla hija asignada correctamente"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("FALLÓ el FObjectFinder para SM_AssetPlatform"));
	}
}

void APlataformaHija::BeginPlay()
{

}

void APlataformaHija::mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("clase APlataformaHija hablandote para destruir el escenario"));
}
