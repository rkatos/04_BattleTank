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
	FVector emptyV = { 0.f,0.f,0.f };//Out parameter
//	 UE_LOG(LogTemp, Warning, TEXT("Hit Location %s"), *emptyV.ToString());
	if (GetSightRayHitLocation(emptyV))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction %s"), *emptyV.ToString());
	}
//	 UE_LOG(LogTemp, Warning, TEXT("Hit Location X= %f"),  emptyV.X);
	// if it hits landscape
		//tell controlled tank to aim at crosshairs.
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &anyFV)
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;

	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation;
	ScreenLocation.X = CrossHairXLocation* ViewportSizeX;
	ScreenLocation.Y = CrossHairYLocation * ViewportSizeY;
	UE_LOG(LogTemp, Warning, TEXT("ViewportSizeX = %f"), ViewportSizeX);
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation = %s"), *ScreenLocation.ToString());
	// 'deproject' screen position of the cursor or cross hair to a world direction
	// line trace along that direction, see what we hit, to max range

	//map screen coordinates to 3D world, return is it landscape false, or true.
	// make a list of all tanks, get their locations, add some buffer size for around the tank
	// if crosshairs don't land in the field, return false
	anyFV.X = 20.0;
	anyFV.Y = 30.0;
	anyFV.Z = 40.0;

	bool success = false;

	/*

	F R O M  T H E   D O C U M E N T A T I O N   https://docs.unrealengine.com/en-US/API/Runtime/Engine/Engine/UWorld/LineTraceSingleByChannel/index.html

	bool LineTraceSingleByChannel
(
    struct FHitResult & OutHit,
    const FVector & Start,
    const FVector & End,
    ECollisionChannel TraceChannel,
    const FCollisionQueryParams & Params,
    const FCollisionResponseParams & ResponseParam
) const

bool ActorLineTraceSingle
(
	struct FHitResult & OutHit,
	const FVector & Start,
	const FVector & End,
	ECollisionChannel TraceChannel,
	const struct FCollisionQueryParams & Params
)

*/
	FHitResult mombo;
/*	UE_LOG(LogTemp, Warning, TEXT("in actor line trace GetPawn name %s"), *GetPawn()->GetName());
	UE_LOG(LogTemp, Warning, TEXT("in actor line trace transform %s"), *GetPawn()->GetTransform().ToString()); */
	FVector theStart = GetPawn()->GetTransform().GetLocation();
	FVector theEnd = GetPawn()->GetActorForwardVector() + FVector{ 5000.f,0.f,-100.f };
	ECollisionChannel ECollisonChannelMendez = ECC_Visibility;
	
	FCollisionQueryParams FColQparams = ECC_MAX;
		FCollisionResponseParams FColResParm = ECR_MAX;
		/*
		void DrawDebugLine
(
    const UWorld * InWorld, 
    FVector const & LineStart,
    FVector const & LineEnd,
    FColor const & Color,
    bool bPersistentLines,
    float LifeTime,
    uint8 DepthPriority,
    float Thickness
)*/
	DrawDebugLine(GetWorld(), theStart, theEnd, FColor{ 255,0,0 }, true, 5, 5, 6.0f);
	success = ActorLineTraceSingle(mombo, theStart, theEnd, ECollisonChannelMendez, FColQparams);
 	//anyFV = mombo.GetActor()->GetTransform().GetLocation();
//	UE_LOG(LogTemp, Warning, TEXT("in actor line trace GetActorLocation %s"), &mombo.GetActor()->GetTransform().GetLocation().ToString());
	if (success)
	{
		UE_LOG(LogTemp, Warning, TEXT("success, a hit! %s"));
	}
	return success;
}

ATank* ATankPlayerController::GetControlledTank( ) 
{


	return Cast<ATank>(GetPawn());
}
