// Fill out your copyright notice in the Description page of Project Settings.


#include "RocaCae.h"
#include "Obstaculo.h"
#include "ObstaculoRoca.h"
#include "GameFramework/Actor.h"

ARocaCae::ARocaCae()
{
	PrimaryActorTick.bCanEverTick = true;

	bDebeCaer = false;
	VelocidadCaida = 300.0f;

	// Activar físicas en la malla
	if (MallaObstaculo)
	{
		MallaObstaculo->SetSimulatePhysics(true);
		MallaObstaculo->SetEnableGravity(false); // desactivar gravedad hasta que se active
	}
}


void ARocaCae::BeginPlay()
{
	Super::BeginPlay();
}

void ARocaCae::Activarse()
{
	UE_LOG(LogTemp, Warning, TEXT("RocaCae activada: empieza a caer con física"));

	if (MallaObstaculo)
	{
		MallaObstaculo->SetEnableGravity(true); // ahora sí cae verticalmente (eje Z)
	}
}

void ARocaCae::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDebeCaer)
	{
		FVector Pos = GetActorLocation();
		Pos.Z -= VelocidadCaida * DeltaTime;
		SetActorLocation(Pos);
	}
}