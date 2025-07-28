// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGamemode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGamemode : public AGameModeBase
{
	GENERATED_BODY()

public:

	virtual void ActorDied(AActor* DeadActor);

protected:
	void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

private:
	class ATank* Tank;
	class AToonTanksPlayerController* ToonTanksPlayerController;

	float StartDelay = 3.f;

	void HandleGameStart();
};
