// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("No controlled tank for AI controller"));
	}

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("No player tank found by AI controller"));
	}
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

