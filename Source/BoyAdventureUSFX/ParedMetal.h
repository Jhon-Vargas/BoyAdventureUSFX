// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstaculoPared.h"
#include "ParedMetal.generated.h"

/**
 * 
 */
UCLASS()
class BOYADVENTUREUSFX_API AParedMetal : public AObstaculoPared
{
	GENERATED_BODY()

private:
	FString TipoMetal;

	float IncrementoDesplazamiento;
public:
	AParedMetal();

	virtual void Activarse() override;
	virtual void BeginPlay() override
	{
		Super::BeginPlay();
	}

protected:
	void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pared Metal")
	float DesplazamientoPuerta;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pared Metal")
	float LimiteDesplazamientoPuerta;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pared Metal")
	bool Activo;
};
