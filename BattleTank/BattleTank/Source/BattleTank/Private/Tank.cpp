// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "tankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Engine.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "..\Public\Tank.h"
// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// no need to protect pointers as added at construction
	TankAimingComponent = CreateDefaultSubobject<UtankAimingComponent>(FName("AimingComponent"));
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("MovementComponent"));
}



// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("tank.cpp BeginPlay"));
	
}

// Called every frame


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ATank::SetBarrelReference(UTankBarrel *BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}
void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation,LaunchSpeed);
	//	auto OurTankName = GetName();

	//	UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *OurTankName, *HitLocation.ToString());
}

void ATank::SetTurretReference(UTankTurret *TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
 
	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (IsReloaded && Barrel && AllowFire) {
		UE_LOG(LogTemp, Warning, TEXT("Fire"));

		auto Projectile = 
			GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
				Barrel->GetSocketLocation(FName("Projectile")), 
				Barrel->GetSocketRotation(FName("Projectile"))
				);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}

	
}
