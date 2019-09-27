// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
//#include "Tank.h"

#include "TankAIController.generated.h"


class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	//ATank* GetAIControlledTank() const;
	// ATankPlayerController *GetTankPlayerController();

		// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void BeginPlay() override;

 
		float AcceptanceRadius = 3000.0; //how close to the player

 

	 
};
 