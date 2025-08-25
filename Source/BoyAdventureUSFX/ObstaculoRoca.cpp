// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoRoca.h"
#include "Obstaculo.h"

AObstaculoRoca::AObstaculoRoca()
{
	//vamos a asignar una apariencia a la malla del obstáculo
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaObstaculo(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (ObjetoMallaObstaculo.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(ObjetoMallaObstaculo.Object);
		//MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_CobbleStone_Pebble.M_CobbleStone_Pebble'"));
	if (MaterialAsset.Succeeded())
	{
		MallaObstaculo->SetMaterial(0, MaterialAsset.Object); // El índice 0 es el primer slot de material
	}
}

void AObstaculoRoca::Activarse()
{
	UE_LOG(LogTemp, Warning, TEXT("ObstaculoRoca activado: escalando"));
	if (MallaObstaculo)
	{
		// Aumenta la roca 3 veces
		MallaObstaculo->SetWorldScale3D(FVector(3.0f, 3.0f, 3.0f));
	}
}
void AObstaculoRoca::BeginPlay()
{
	Super::BeginPlay();

	if (MallaObstaculo)
	{
		MallaObstaculo->SetWorldScale3D(FVector(3.0f, 3.0f, 3.0f));
	}

	Activarse(); // mantiene otros efectos de Activarse()
}