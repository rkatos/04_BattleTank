// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank_BP.h"

// Sets default values
ATank_BP::ATank_BP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank_BP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank_BP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank_BP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

