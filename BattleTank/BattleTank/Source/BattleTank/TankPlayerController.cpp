// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Tank.h"
#include "Classes/Kismet/GameplayStatics.h"
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
/*	FString LevelName;
	LevelName = GetWorld()->GetCurrentLevel()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("Level=%s"),*LevelName);
	int32  RealTimeSeconds;
	float RealTimePartialSeconds;
	UGameplayStatics::GetAccurateRealTime(this, RealTimeSeconds, RealTimePartialSeconds);
	UE_LOG(LogTemp, Warning, TEXT("Real Time =%i"), RealTimeSeconds);
	*/
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
	// emptyV = { 0.f,0.f,0.f };//Out parameter
//	 UE_LOG(LogTemp, Warning, TEXT("Hit Location %s"), *emptyV.ToString());
 	if (GetSightRayHitLocation(HitLocation))
 	{
 	//	UE_LOG(LogTemp, Warning, TEXT("Look Direction %s"), *HitLocation.ToString());
		GetControlledTank()->AimAt(HitLocation);
 	}
//	float UnitVectorProof;
//	UnitVectorProof = HitLocation.X*HitLocation.X +HitLocation.Y*HitLocation.Y + HitLocation.Z*HitLocation.Z;
	 
//	UE_LOG(LogTemp, Warning, TEXT("unitVectorProof = %f"), UnitVectorProof);
	// if it hits landscape


		//tell controlled tank to aim at crosshairs.
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation)
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	FVector LookDirection;

	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation;
	ScreenLocation.X = CrossHairXLocation * ViewportSizeX;
	ScreenLocation.Y = CrossHairYLocation * ViewportSizeY;

	//	UE_LOG(LogTemp, Warning, TEXT("ViewportSizeX = %f"), ViewportSizeX);
	//	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation = %s"), *ScreenLocation.ToString());
		// 'deproject' screen position of the cursor or cross hair to a world direction
	 
	//	FVector WorldDirection;
	//	bool DeProjectSuccess = false;
	//	DeProjectSuccess = DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection);
	//	if (DeProjectSuccess)
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("success,Deproject! %s"), *WorldDirection.ToString());
	//	}
	//	return DeProjectSuccess;

	
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return true;

 


	 
	
	 
	
	 
//	DrawDebugLine(GetWorld(), StartLine,EndLine, FColor{ 255,0,0 }, false, .1f, 5, 6.0f);
		

		//	J U S T   A   N O T E
		// DrawDebugLine(GetWorld(), theStart, theEnd, FColor{ 255,0,0 }, true, 5, 5, 6.0f);

}


		ATank* ATankPlayerController::GetControlledTank( )
		{


			return Cast<ATank>(GetPawn());
		}



		bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation)
		{
			FHitResult HitResult;
			FVector StartLocation = PlayerCameraManager->GetCameraLocation();
			FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
			if (GetWorld()->LineTraceSingleByChannel(
				HitResult,
				StartLocation,
				EndLocation,
				ECollisionChannel::ECC_Visibility
			))
			{
				HitLocation = HitResult.Location;
			//	UE_LOG(LogTemp, Warning, TEXT("good Hit,tankplayctrl"));
				return true;
			}
			UE_LOG(LogTemp, Warning, TEXT("bad Hit,tankplayctrl"));
			HitLocation = FVector(0);
			return false;
		}
		bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection)
		{

			FVector CameraWorldLocation;

			/*CameraWorldLocation = this->PlayerCameraManager->GetCameraLocation();
			CameraWorldLocation = PlayerCameraManager->GetCameraLocation();*/
			bool DeProjectSuccess = false;
			return  DeprojectScreenPositionToWorld(
				ScreenLocation.X,
				ScreenLocation.Y,
				CameraWorldLocation,
				LookDirection);
		}
