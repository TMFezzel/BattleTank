// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

class UTankAimingComponent;

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	ControlledTank = GetPawn();
	PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (ensure(PlayerTank && ControlledTank)) {
		
		//Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);

		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		if (AimingComponent->GetFiringState() == EFiringState::Locked) {
			AimingComponent->Fire();
		}

	}
}

