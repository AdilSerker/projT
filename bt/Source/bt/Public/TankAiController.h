// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class BT_API ATankAiController : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

private:
	ATank* GetControllerTank() const;

	ATank* GetPlayerTank() const;
	
};
