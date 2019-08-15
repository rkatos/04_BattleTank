// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "Tank.h"
#include "TankPlayerController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"



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

	auto tryout = GetPlayerTank();
	FString nameo = tryout->GetFullName();
	FString bumby = tryout->GetName();
	UE_LOG(LogTemp, Warning, TEXT("returning from GetPlayerTank, it is: %s"), *bumby);
	FString bikel = tryout->GetTransform().ToString();
	FString smog = tryout->GetTransform().GetLocation().ToString();
	float xo = tryout->GetTransform().GetLocation().X;
	UE_LOG(LogTemp, Warning, TEXT("transform =  %s"), *bikel);
	UE_LOG(LogTemp, Warning, TEXT("location =  %s"), *smog);
	UE_LOG(LogTemp, Warning, TEXT("x =  %f"), xo);
}
ATank * ATankAIController::GetPlayerTank() const
{
	/* 
we need to find the playerController, then find the tank, it's coordinates, and figure how to hit it. 
*/
	APlayerController *PlayerC;
	PlayerC = GetWorld()->GetFirstPlayerController();
	APawn *Gobo = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	 
	FString bulova = PlayerC->GetActorLabel();
	FString PawnName = Gobo->GetName();
	 UE_LOG(LogTemp, Warning, TEXT("bulova = %s"),   *bulova  );
	 UE_LOG(LogTemp, Warning, TEXT("pawn name  = %s"), *PawnName);
	if (!PlayerC)
	{
		// we have an error
		UE_LOG(LogTemp, Warning, TEXT("No PlayerC found\n"));
		return nullptr;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT(" PlayerC found\n"));
		return Cast<ATank>(Gobo);
	}
	
}
ATank* ATankAIController::GetAIControlledTank() const
{


	return Cast<ATank>(GetPawn());
}
/* 
we need to find the playerController, then find the tank, it's coordinates, and figure how to hit it. 
*/