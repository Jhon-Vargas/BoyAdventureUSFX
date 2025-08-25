// Fill out your copyright notice in the Description page of Project Settings.


#include "TrampaSierra.h"

ATrampaSierra::ATrampaSierra() : AObstaculoTrampa()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaTrampaSierra(TEXT("StaticMesh'/Game/Assets/Rusty_Saw_Blade_wcvodba_High.Rusty_Saw_Blade_wcvodba_High'"));

	if (ObjetoMallaTrampaSierra.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(ObjetoMallaTrampaSierra.Object);

		//MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	// Cargar el material
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));

	if (MaterialAsset.Succeeded())
	{
		MallaObstaculo->SetMaterial(0, MaterialAsset.Object); // El índice 0 es el primer slot de material
	}
}
