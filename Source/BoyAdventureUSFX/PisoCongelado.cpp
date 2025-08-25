// PisoCongelado.cpp

#include "PisoCongelado.h"
#include "PisoCongelado.h"
#include "BoyAdventureUSFX.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "RocaCae.h"
APisoCongelado::APisoCongelado()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaObstaculo(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));

	if (ObjetoMallaObstaculo.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(ObjetoMallaObstaculo.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialParedAsset(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));
	// ?? aquí podrías usar un material de hielo si existe, o cambiarlo luego

	if (MaterialParedAsset.Succeeded())
	{
		MallaObstaculo->SetMaterial(0, MaterialParedAsset.Object);
	}

	MallaObstaculo->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MallaObstaculo->SetCollisionResponseToAllChannels(ECR_Overlap);
	MallaObstaculo->SetGenerateOverlapEvents(true);

	MallaObstaculo->OnComponentBeginOverlap.AddDynamic(this, &APisoCongelado::OnMeshBeginOverlap);
	MallaObstaculo->OnComponentEndOverlap.AddDynamic(this, &APisoCongelado::OnMeshEndOverlap);
}

void APisoCongelado::BeginPlay()
{
	Super::BeginPlay();
}

void APisoCongelado::OnMeshBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Overlap Begin: Congelado"));

	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (Character)
	{
		Activarse(Character);
	}
}

void APisoCongelado::OnMeshEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// En este caso no hacemos nada porque el congelamiento es por tiempo fijo
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Overlap End: no afecta, congelamiento es por tiempo"));
}

void APisoCongelado::Activarse(ACharacter* Character)
{
	if (Character)
	{
		UCharacterMovementComponent* Movement = Character->GetCharacterMovement();
		VelocidadOriginal = Movement->MaxWalkSpeed;
		Movement->DisableMovement();


		FTimerHandle TimerHandle;
		FTimerDelegate TimerDel;
		TimerDel.BindLambda([=]()
			{
				if (Character && Character->GetCharacterMovement())
				{
					Character->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
					Character->GetCharacterMovement()->MaxWalkSpeed = VelocidadOriginal;
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("El personaje se descongeló"));
				}
			});

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, 5.f, false);

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("El personaje está congelado por 5 segundos"));
	}
	// --- Spawnear roca encima del jugador ---
	if (Character && GetWorld())
	{
		FVector PlayerPos = Character->GetActorLocation();
		FVector SpawnLocation(PlayerPos.X, PlayerPos.Y, PlayerPos.Z + 1000.f); // 1000 unidades arriba
		FRotator SpawnRotation = FRotator::ZeroRotator;

		// Spawn de la roca
		ARocaCae* Roca = GetWorld()->SpawnActor<ARocaCae>(ARocaCae::StaticClass(), SpawnLocation, SpawnRotation);
		if (Roca)
		{
			Roca->Activarse(); // Hace que caiga automáticamente
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("¡Roca cayó sobre el jugador!"));
		}
	}
}