// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "Engine/Classes/Camera/PlayerCameraManager.h"

ATank* ATankPlayerController::GetControllerTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCroshair() {
	ATank* tank = GetControllerTank();

	if (!tank) { return; }

	FVector hitLocation;
	GetSightRayHitLocation(hitLocation);

	tank->AimAt(hitLocation);

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLocation) const {
	int32 vpSizeX, vpSizeY;
	GetViewportSize(vpSizeX, vpSizeY);

	auto ScreenLocation = FVector2D(vpSizeX * CrossHairXLocation, vpSizeY * CrossHairYLocation);

	FVector WorldDirection;

	if (GetLookDirection(ScreenLocation, WorldDirection)) {
		GetLookVectorHitLocation(WorldDirection, hitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WordlLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WordlLocation, LookDirection);;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& hitLcoation) const
{	
	FHitResult result;
	FVector startLocation = PlayerCameraManager->GetCameraLocation();
	FVector endLocation = startLocation + (LookDirection * LineTraceRange);

	bool isIntersect = GetWorld()->LineTraceSingleByChannel(
		result,
		startLocation,
		endLocation,
		ECollisionChannel::ECC_Visibility
	);

	if (isIntersect) {
		hitLcoation = result.Location;
		return true;
	}
	hitLcoation = FVector(0.0f);
	return false;
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	ATank* myTank = GetControllerTank();

	if (!myTank) {
		UE_LOG(LogTemp, Warning, TEXT("Tank is not init"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Tank name %s"), *myTank->GetName())
	}

}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCroshair();
}
