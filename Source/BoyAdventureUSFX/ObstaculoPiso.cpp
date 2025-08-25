// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoPiso.h"

AObstaculoPiso::AObstaculoPiso()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaObstaculoTrampa(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));

	if (ObjetoMallaObstaculoTrampa.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(ObjetoMallaObstaculoTrampa.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Rock_Sandstone.M_Rock_Sandstone'"));

	if (MaterialAsset.Succeeded())
	{
		MallaObstaculo->SetMaterial(0, MaterialAsset.Object); // El índice 0 es el primer slot de material
	}
}

void AObstaculoPiso::Activarse()
{

}
