// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BoyAdventureUSFXGameMode.generated.h"

class AObstaculoPared;
class AParedMetal;
class ATrampaSierra;

UCLASS(minimalapi)
class ABoyAdventureUSFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABoyAdventureUSFXGameMode();

	void MoverActorAleatoriamente();

public:
	virtual void BeginPlay() override;

private:
	AObstaculoPared* Obstaculo;
	AParedMetal* ParedMetal01;

	ATrampaSierra* ts01;
	ATrampaSierra* ts02;

private:
	FTimerHandle MovimientoTimer;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float Intervalo = 4.0f;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	FVector RangoMovimiento = FVector(500.0f, 500.0f, 0.0f); // Solo X e Y

};



