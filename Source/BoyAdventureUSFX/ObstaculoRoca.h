// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "ObstaculoRoca.generated.h"

/**
 *
 */
UCLASS()
class BOYADVENTUREUSFX_API AObstaculoRoca : public AObstaculo
{
	GENERATED_BODY()
public:
	AObstaculoRoca();
	virtual void BeginPlay() override;
	virtual void Activarse() override;
};