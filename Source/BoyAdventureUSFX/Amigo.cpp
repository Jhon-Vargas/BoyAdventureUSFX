// Fill out your copyright notice in the Description page of Project Settings.


#include "Amigo.h"

// Sets default values
AAmigo::AAmigo()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAmigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAmigo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

