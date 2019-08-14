// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
#include "TankPlayerController.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetAIControlledTank();

	//	UE_LOG(LogTemp, Warning, TEXT("@GetControllerTank"));



	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("@GetController_AI_Tank true   %s"), *ControlledTank->GetName());
		//UE_LOG(LogTemp, Warning, TEXT("logTank == true:%s"), *ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("@GetController_AI_Tank False"));
		//UE_LOG(LogTemp, Warning, TEXT("logTank == false"));
	}
}
ATank* ATankAIController::GetAIControlledTank() const
{


	return Cast<ATank>(GetPawn());
}
