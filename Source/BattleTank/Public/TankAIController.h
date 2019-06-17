// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

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
	ATank* ControlledTank = nullptr;

	ATank* PlayerTank = nullptr;
};
