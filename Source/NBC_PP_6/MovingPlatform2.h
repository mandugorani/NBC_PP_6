// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform2.generated.h"

UCLASS()
class NBC_PP_6_API AMovingPlatform2 : public AActor
{
	GENERATED_BODY()

public:
	AMovingPlatform2();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float MoveSpeed = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float MaxRange = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float DestinationChangeInterval = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float DestructionDelay = 15.0f; // 파괴되기전 대기 시간

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	bool bEnableRandomMovement = true; // 0203_1

private:
	FTimerHandle TimerHandle_ChangeDestination;
	FTimerHandle TimerHandle_Destroy;

	FVector StartPoint;
	FVector EndPoint;
	float CurrentTime;

	UFUNCTION()
	void ChangeDestination();

	UFUNCTION()
	void DestroyPlatform();
};