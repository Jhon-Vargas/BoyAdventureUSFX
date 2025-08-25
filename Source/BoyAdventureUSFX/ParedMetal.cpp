// Fill out your copyright notice in the Description page of Project Settings.


#include "ParedMetal.h"

AParedMetal::AParedMetal():AObstaculoPared()
{
    PrimaryActorTick.bCanEverTick = true;

    // Cargar el material
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaObstaculo(TEXT("StaticMesh'/Game/Assets/Roman_Column_wj3kdjtqx_Raw.Roman_Column_wj3kdjtqx_Raw'"));

    if (ObjetoMallaObstaculo.Succeeded())
    {
        MallaObstaculo->SetStaticMesh(ObjetoMallaObstaculo.Object);

        //MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }

    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialParedAsset(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));

    if (MaterialParedAsset.Succeeded())
    {
        MallaObstaculo->SetMaterial(0, MaterialParedAsset.Object); // El índice 0 es el primer slot de material
    }
	DesplazamientoPuerta = 0.0f; // Inicializa el desplazamiento de la puerta
    LimiteDesplazamientoPuerta = 150.0f; // Define el límite de desplazamiento de la puerta
    Activo = true; // Inicialmente el obstáculo e
	IncrementoDesplazamiento = 0.8f; // Valor de incremento del desplazamiento
}

void AParedMetal::Activarse()
{

    if (DesplazamientoPuerta >= LimiteDesplazamientoPuerta)
    {
        IncrementoDesplazamiento = -FMath::Abs(IncrementoDesplazamiento);
    }
	else if (DesplazamientoPuerta <= 0.0f)
	{
		IncrementoDesplazamiento = FMath::Abs(IncrementoDesplazamiento);
	}

    if (Activo) {

		FVector RotacionActual = GetActorRotation().Euler();

        FVector PosicionActual = GetActorLocation();
        float NuevoY = PosicionActual.Y + IncrementoDesplazamiento;
        DesplazamientoPuerta += IncrementoDesplazamiento; // Incrementa el desplazamiento de la puerta
        FVector NuevaPosicion = FVector(PosicionActual.X, NuevoY, PosicionActual.Z);
        SetActorLocation(NuevaPosicion);
		SetActorRotation(FRotator(RotacionActual.X, RotacionActual.Y, RotacionActual.Z));

    }
}

void AParedMetal::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Activarse();
}
