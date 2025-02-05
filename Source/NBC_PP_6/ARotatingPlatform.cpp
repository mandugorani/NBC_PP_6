// Fill out your copyright notice in the Description page of Project Settings.


#include "ARotatingPlatform.h"

// Sets default values
AARotatingPlatform::AARotatingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RotationSpeed = 30.0f; // 회전 속도
	RotationAxis = FVector(0, 0, 1); // Z축 회전이라면 이렇게
	InitialRotation = GetActorRotation().Quaternion();

}

// Called when the game starts or when spawned
void AARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float RotationDelta = RotationSpeed * DeltaTime;
	FQuat DeltaRotation = FQuat(RotationAxis, FMath::DegreesToRadians(RotationDelta));
	AddActorLocalRotation(DeltaRotation);

}

