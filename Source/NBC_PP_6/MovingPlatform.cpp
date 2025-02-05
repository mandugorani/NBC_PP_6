// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StartPoint = FVector(0, 0, 0);
	EndPoint = FVector(300, 0, 0);
	CurrentTime = 0.0f;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartPoint = GetActorLocation();
	EndPoint = StartPoint + MovementOffset;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*CurrentTime += DeltaTime * Speed;
	float Alpha = FMath::Sin(CurrentTime);
	FVector NewLocation = FMath::Lerp(StartPoint, EndPoint, Alpha);
	SetActorLocation(NewLocation);*/
	// x

	float Distance = FVector::Distance(StartPoint, EndPoint);
	float Alpha = (FMath::Sin(CurrentTime) + 1) * 0.5f; // 0-1
	FVector NewLocation = FMath::Lerp(StartPoint, EndPoint, Alpha);
	SetActorLocation(NewLocation);
	// ÄÚÆÄÀÏ·µ 0205

	CurrentTime += DeltaTime * MoveSpeed / Distance;
}

