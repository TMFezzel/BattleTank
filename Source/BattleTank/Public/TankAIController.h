// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	void Tick(float DeltaTime) override;

private:
	//Called when pawn is created.
	void BeginPlay() override;

	//Return tank that this controller is in charge of.
	AActor* ControlledTank = nullptr;

	AActor* PlayerTank = nullptr;

	virtual void SetPawn(APawn* InPawn)override;

	UFUNCTION()
	void OnPossessedTankDeath();

protected:
	//How close can the AI tank get to the player
	UPROPERTY(EditAnywhere, Category = Movement)
	float AcceptanceRadius = 800; //8 meters
};
