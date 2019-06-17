// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Engine/World.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	ControlledTank = Cast<ATank>(GetPawn());
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank && ControlledTank) {
		//TODO Move towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}
}

