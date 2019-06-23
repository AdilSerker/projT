// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) {

	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);

	float ElevationChange = RelativeSpeed * MaxDegressPerSec * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;


	float BarrelAngle = FMath::Clamp(RawNewElevation, MinElevationDegress, MaxElevationDegress);

	SetRelativeRotation(FRotator(BarrelAngle, 0, 0));
}