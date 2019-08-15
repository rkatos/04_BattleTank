// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "BattleTank.h"

// tick
	//super
	// aim towards crosshair()

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();

//	UE_LOG(LogTemp, Warning, TEXT("@GetControllerTank"));



	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("@GetControllerTank true   %s"), *ControlledTank->GetName()); 
		//UE_LOG(LogTemp, Warning, TEXT("logTank == true:%s"), *ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("@GetControllerTank False"));
		//UE_LOG(LogTemp, Warning, TEXT("logTank == false"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("."));

		// aim towards crosshair()
	aimTowardCrosshair();

}

void ATankPlayerController::aimTowardCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}
	// get world location if linetrace through crosshair
	// if it hits landscape
		//tell controlled tank to aim at crosshairs.
}

ATank* ATankPlayerController::GetControlledTank() const
{


	return Cast<ATank>(GetPawn());
}
