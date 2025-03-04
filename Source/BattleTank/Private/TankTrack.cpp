// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Math/UnrealMathUtility.h"
#include "SpawnPoint.h"
#include "SprungWheel.h"

UTankTrack::UTankTrack() {
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::SetThrottle(float Throttle) {
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(CurrentThrottle);
}

TArray<ASprungWheel*> UTankTrack::GetWheels() const {
	TArray<ASprungWheel*> ResultArray;
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);
	for (USceneComponent* Child : Children) {
		auto SpawnPointChild = Cast<USpawnPoint>(Child);
		if (!SpawnPointChild) { continue; } //Stop this item and continue for loop

		AActor* SpawnedChild = SpawnPointChild->GetSpawnedActor();
		auto SprungWheel = Cast<ASprungWheel>(SpawnedChild);

		if (!SprungWheel) { continue; }
		ResultArray.Add(SprungWheel);
	}
	return ResultArray;
}

void UTankTrack::DriveTrack(float CurrentThrottle) 
{
	//TODO Clamp throttle so it cant be increased above one by player editing control settings.
	auto ForceApplied = CurrentThrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();
	for (ASprungWheel* Wheel : Wheels) {
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}
