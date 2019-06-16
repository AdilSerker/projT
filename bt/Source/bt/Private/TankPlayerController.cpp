// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControllerTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCroshair() {
	if (!GetControllerTank()) { return; }


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

}
