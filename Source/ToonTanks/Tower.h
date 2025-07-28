// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	// to avoid adding tank.h here, we forward declared the tank pointer by having class at front
	class ATank* Tank;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	float FireRange = 300.f;

	FTimerHandle FireRateTimerHandle;
	float FireRate = 2.f;
	void CheckFireCondition();

	bool InFireRange();
};
