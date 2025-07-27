// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"			// class header file at the top
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"		// components header file underneath the class h files
#include "Components/InputComponent.h"

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm -> SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	Camera -> SetupAttachment(SpringArm);
}

void ATank::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// overriding parent function
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
}


void ATank::Move(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("value %f"), Value);
}