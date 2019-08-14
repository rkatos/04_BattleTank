// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "BattleTank.h"

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

ATank* ATankPlayerController::GetControlledTank() const
{


	return Cast<ATank>(GetPawn());
}
