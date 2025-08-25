// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoTrampa.h"

AObstaculoTrampa::AObstaculoTrampa() : AObstaculo()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaObstaculoTrampa(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));

	if (ObjetoMallaObstaculoTrampa.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(ObjetoMallaObstaculoTrampa.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));

	if (MaterialAsset.Succeeded())
	{
		MallaObstaculo->SetMaterial(0, MaterialAsset.Object); // El índice 0 es el primer slot de material
	}
}

void AObstaculoTrampa::Activarse()
{
	
}
