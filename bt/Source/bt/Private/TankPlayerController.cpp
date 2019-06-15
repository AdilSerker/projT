// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControllerTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController -> begin play"))
}

void ATankPlayerController::Tick(float DeltaTime) {
	ATank* myTank = GetControllerTank();

	UE_LOG(LogTemp, Warning, TEXT("Tankname %s"), *myTank->GetName())
}
