#pragma once

#include "CoreMinimal.h"
#include "ObstaculoPiso.h"
#include "PisoCongelado.generated.h"

class ACharacter;

UCLASS()

class BOYADVENTUREUSFX_API APisoCongelado : public AObstaculoPiso
{
    GENERATED_BODY()

public:
    APisoCongelado();

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

private:
    // Guardamos la velocidad original para restaurarla
    float VelocidadOriginal;
};