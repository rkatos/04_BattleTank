// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"
#include "TankPlayerController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
//	auto ControlledTank = GetAIControlledTank();



}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		// TODO move towards player

		// Aim towards the player

		// fire if ready
		ControlledTank->AimAt(PlayerTank->GetActorLocation());


		//GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		 ControlledTank->Fire(); //TODO Limit Firing Rate!
	}

}



