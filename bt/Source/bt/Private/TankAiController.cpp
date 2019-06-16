// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAiController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

ATank* ATankAiController::GetControllerTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank() const
{
	APlayerController* player = nullptr;
	player = GetWorld()->GetFirstPlayerController();
	if (player) {
		return Cast<ATank>(player->GetPawn());
	}

	return nullptr;
}

void ATankAiController::BeginPlay() {
	Super::BeginPlay();

	ATank* playerTank = GetPlayerTank();

	if (!playerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Tank is not found"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("player Tank name %s"), *playerTank->GetName())
	}

}