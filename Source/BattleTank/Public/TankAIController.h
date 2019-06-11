// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	//Called when pawn is created.
	void BeginPlay() override;

	//Return tank that this controller is in charge of.
	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;
};
