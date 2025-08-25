// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoPared.h"

AObstaculoPared::AObstaculoPared() : AObstaculo()
{


    PrimaryActorTick.bCanEverTick = true;
    // Constructor logic specific to AObstaculoPared can be added here
    Estilo = "Pared no definido";
    Material = "Material no definico";
    Activo = true;
    AbiertoCompletamente = false;
    DesplazamientoPuerta = 0.0f;
	LimiteDesplazamientoPuerta = 150.0f;
    // Cargar el material
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Ground_Gravel.M_Ground_Gravel'"));
    
    if (MaterialAsset.Succeeded())
    {
        MallaObstaculo->SetMaterial(0, MaterialAsset.Object); // El índice 0 es el primer slot de material
    }
}

void AObstaculoPared::Activarse()
{
    if (DesplazamientoPuerta >= LimiteDesplazamientoPuerta)
    {
        AbiertoCompletamente = true;
        Activo = false; // Desactiva el obstáculo si se ha abierto completamente
        UE_LOG(LogTemp, Warning, TEXT("Obstáculo abierto completamente"));
    }
    else if (Activo) {

        FVector PosicionActual = GetActorLocation();
        float NuevoX = PosicionActual.X + 0.8f;
        DesplazamientoPuerta += 0.8f; // Incrementa el desplazamiento de la puerta
        FVector NuevaPosicion = FVector(NuevoX, PosicionActual.Y, PosicionActual.Z);
        SetActorLocation(NuevaPosicion);
    }
}

void AObstaculoPared::BeginPlay()
{
	Super::BeginPlay();
}

void AObstaculoPared::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    Activarse();
}


