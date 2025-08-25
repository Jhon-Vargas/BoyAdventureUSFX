// Fill out your copyright notice in the Description page of Project Settings.


#include "PisoLento.h"
#include "BoyAdventureUSFX.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

APisoLento::APisoLento()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaObstaculo(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));

	if (ObjetoMallaObstaculo.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(ObjetoMallaObstaculo.Object);
	}
	
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialParedAsset(TEXT("Material'/Game/StarterContent/Materials/M_Rock_Sandstone.M_Rock_Sandstone'"));

	if (MaterialParedAsset.Succeeded())
	{
		MallaObstaculo->SetMaterial(0, MaterialParedAsset.Object); // El índice 0 es el primer slot de material
	}
	
	MallaObstaculo->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MallaObstaculo->SetCollisionResponseToAllChannels(ECR_Overlap);
	MallaObstaculo->SetGenerateOverlapEvents(true);

	MallaObstaculo->OnComponentBeginOverlap.AddDynamic(this, &APisoLento::OnMeshBeginOverlap);
	MallaObstaculo->OnComponentEndOverlap.AddDynamic(this, &APisoLento::OnMeshEndOverlap);
}

void APisoLento::BeginPlay()
{
	Super::BeginPlay();
}

void APisoLento::OnMeshBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Overlap Begin detected"));

	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (Character)
	{
		Activarse(Character);
	}
}

void APisoLento::OnMeshEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Overlap End detected"));

	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (Character)
	{
		Character->GetCharacterMovement()->MaxWalkSpeed /= 0.1f;
	}
}

void APisoLento::Activarse(ACharacter* Character)
{
	if (Character)
	{
		Character->GetCharacterMovement()->MaxWalkSpeed *= 0.1f;
	}
}
