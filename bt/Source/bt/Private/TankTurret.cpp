// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed) {
	float ElevationChange = RelativeSpeed * MaxDegressPerSec * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Yaw + ElevationChange;

	SetRelativeRotation(FRotator(0, RawNewElevation, 0));
}

