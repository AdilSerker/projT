// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::AimAt(FVector hitLocation, float launchSpeed) {
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;

	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));


	bool isHaveAimSolutuin = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		hitLocation,
		launchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (isHaveAimSolutuin) {
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}

}


void UTankAimingComponent::MoveBarrelTowards(FVector AimDirrection)
{
	FRotator barrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator aimRotation = AimDirrection.Rotation();

	FRotator deltaRotation = aimRotation - barrelRotation;

	Barrel->Elevate(5);
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* barrelToSet) {
	this->Barrel = barrelToSet;
}

