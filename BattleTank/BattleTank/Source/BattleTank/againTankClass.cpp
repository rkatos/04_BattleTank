// Fill out your copyright notice in the Description page of Project Settings.


#include "againTankClass.h"

// Sets default values
AagainTankClass::AagainTankClass()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AagainTankClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AagainTankClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AagainTankClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AagainTankClass::IsThisRecognized()
{
	UE_LOG(LogTemp, Warning, TEXT("IsThisRecognized=%s"),"true");
	return false;
}

