// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"			// class header file at the top
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"		// components header file underneath the class h files

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm -> SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	Camera -> SetupAttachment(SpringArm);
}

