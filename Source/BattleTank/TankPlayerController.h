// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	//Called when pawn is created.
	void BeginPlay() override;

	void Tick(float DeltaTime) override;

private: 
	

	//Return tank that this controller is in charge of.
	ATank* GetControlledTank() const;
	
	void AimTowardsCrosshair();

	//Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 10000000.f;
};
