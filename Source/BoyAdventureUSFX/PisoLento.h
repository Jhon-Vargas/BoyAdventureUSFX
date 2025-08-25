// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstaculoPiso.h"
#include "PisoLento.generated.h"

class ACharacter;

UCLASS()
class BOYADVENTUREUSFX_API APisoLento : public AObstaculoPiso
{
	GENERATED_BODY()
	
public:
	APisoLento();

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnMeshBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnMeshEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void Activarse(ACharacter* Character);

 };