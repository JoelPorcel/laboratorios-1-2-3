// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaHija.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICA_API APlataformaHija : public APlataforma
{
	GENERATED_BODY()

	APlataformaHija();

public:
	virtual void BeginPlay() override;

	void mensaje() override;
};
