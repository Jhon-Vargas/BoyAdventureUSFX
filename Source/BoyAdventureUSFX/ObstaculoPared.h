// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "ObstaculoPared.generated.h"

/**
 * 
 */
UCLASS()
class BOYADVENTUREUSFX_API AObstaculoPared : public AObstaculo
{
	GENERATED_BODY()
//public:
//	AObstaculoPared()
//		: AObstaculo()
//	{
//		// Constructor logic specific to AObstaculoPared can be added here
//	}
	
protected:
	bool Activo;
	bool AbiertoCompletamente;
	float DesplazamientoPuerta;
	float LimiteDesplazamientoPuerta;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AObstaculoPared();

public:
	FString Estilo;
	FString Material;

	virtual void Activarse() override;
};
