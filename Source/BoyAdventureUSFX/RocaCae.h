// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstaculoRoca.h"
#include "RocaCae.generated.h"

/**
 *
 */
UCLASS()
class BOYADVENTUREUSFX_API ARocaCae : public AObstaculoRoca
{
	GENERATED_BODY()
public:
	ARocaCae();

	virtual void Activarse() override;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:

	bool bDebeCaer;
	float VelocidadCaida;
};