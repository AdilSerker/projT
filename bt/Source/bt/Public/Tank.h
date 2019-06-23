// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;

UCLASS()
class BT_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* barrel);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class UTankAimingComponent* tankAimingComponent = nullptr;

private:
	UPROPERTY(EditAnywhere, Category = Firing)
	float launchSpeed = 100000;
	

};
