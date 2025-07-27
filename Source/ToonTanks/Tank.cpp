// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"			// class header file at the top
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"		// components header file underneath the class h files
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm -> SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	Camera -> SetupAttachment(SpringArm);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// overriding parent function
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
}


void ATank::Move(float Value)
{
	if (Value != 0.f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Turn Input: %f"), Value);
	}
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLocation, true);
	// AddActorLocalOffset(DeltaLocation, true);	// setting sweeping to true is problematic
	
}