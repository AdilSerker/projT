// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

private:
	ATank* GetControllerTank() const;
	void AimTowardsCroshair();
};
