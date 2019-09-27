// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "tankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"

class UTankBarrel;
class UtankAimingComponent;
class UTankTurret;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetBarrelReference(UTankBarrel * BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetTurretReference(UTankTurret *TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Fire();

private:
	UPROPERTY(EditAnywhere, Category = "Firing")
		float LaunchSpeed = 100000; //TODO find sensible default 

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3.0;

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;


		//UClass *ProjectileBluePrint; // alternative is TSubclass 

	UTankBarrel *Barrel = nullptr; // local barrel reference

	UPROPERTY(EditAnywhere, Category = "Setup")
		bool AllowFire = false;



	double LastFireTime = 0;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UtankAimingComponent* TankAimingComponent = nullptr;
	UTankMovementComponent* TankMovementComponent = nullptr;


public:	
	// Called every frame


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

   

};
