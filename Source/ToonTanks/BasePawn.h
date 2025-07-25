// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	UPROPERTY(VisibleAnywhere)
	int32 VisibleAnywhereInt = 12;

	UPROPERTY(EditAnywhere)
	int32 EditAnywhereInt = 22;

	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnlyInt = 11;

	UPROPERTY(EditAnywhere)
	float Speed = 400.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY()				// a macro that helps the code to perform as unreal engine's reflection system
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY()			
	UStaticMeshComponent* BaseMesh;

	UPROPERTY()	
	UStaticMeshComponent* TurretMesh;

	UPROPERTY()	
	USceneComponent* ProjectileSpawnPoint;
};
