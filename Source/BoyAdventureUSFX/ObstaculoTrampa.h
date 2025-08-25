// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "ObstaculoTrampa.generated.h"

/**
 * 
 */
UCLASS()
class BOYADVENTUREUSFX_API AObstaculoTrampa : public AObstaculo
{
	GENERATED_BODY()

public:
	AObstaculoTrampa();
	
protected:
	FString TipoTrampa;

public:
	virtual void Activarse() override;



};
