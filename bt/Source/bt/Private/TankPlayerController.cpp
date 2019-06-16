// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControllerTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCroshair() {
	if (!GetControllerTank()) { return; }

	FVector hitLocation;
	if (GetSightRayHitLocation(hitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *hitLocation.ToString())
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLcoation) const {
	int32 vpSizeX, vpSizeY;
	GetViewportSize(vpSizeX, vpSizeY);

	FVector2D ScreenLocation(vpSizeX * CrossHairXLocation, vpSizeY * CrossHairYLocation);

	FVector WordlLocation, WorldDirection;

	bool b = DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WordlLocation, WorldDirection);

	if (b) {
		UE_LOG(LogTemp, Warning, TEXT("WordlLocation %s"), *WordlLocation.ToString())
		UE_LOG(LogTemp, Warning, TEXT("WorldDirection %s"), *WorldDirection.ToString())
	}
		

	return true;
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
