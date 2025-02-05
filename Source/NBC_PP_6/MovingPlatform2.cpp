// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform2.h"
#include "TimerManager.h"


AMovingPlatform2::AMovingPlatform2()
{
    PrimaryActorTick.bCanEverTick = true;

    StartPoint = FVector::ZeroVector;
    EndPoint = FVector::ZeroVector;
    CurrentTime = 0.0f;
}

void AMovingPlatform2::BeginPlay()
{
    Super::BeginPlay();

    StartPoint = GetActorLocation();
    EndPoint = StartPoint + FVector(
        FMath::RandRange(-MaxRange, MaxRange),
        FMath::RandRange(-MaxRange, MaxRange),
        0
    );

    // Å¸ÀÌ¸Ó
    if (bEnableRandomMovement)
    {
        GetWorld()->GetTimerManager().SetTimer(
            TimerHandle_ChangeDestination,
            this,
            &AMovingPlatform2::ChangeDestination,
            DestinationChangeInterval,
            true
        );
    }

    GetWorld()->GetTimerManager().SetTimer(
        TimerHandle_Destroy,
        this,
        &AMovingPlatform2::DestroyPlatform,
        DestructionDelay,
        false
    );
}

void AMovingPlatform2::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    float Distance = FVector::Distance(StartPoint, EndPoint);
    CurrentTime += DeltaTime * (MoveSpeed / Distance);

    float Alpha = (FMath::Sin(CurrentTime) + 1) * 0.5f; // 0~1
    FVector NewLocation = FMath::Lerp(StartPoint, EndPoint, Alpha);
    SetActorLocation(NewLocation);
}

void AMovingPlatform2::ChangeDestination()
{
    StartPoint = GetActorLocation();
    EndPoint = StartPoint + FVector(
        FMath::RandRange(-MaxRange, MaxRange),
        FMath::RandRange(-MaxRange, MaxRange),
        0
    );
}

void AMovingPlatform2::DestroyPlatform()
{
    Destroy();
}

