// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class NBC_PP_6_API ABall : public AActor
{
    GENERATED_BODY()

public:
    ABall();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* BallMesh;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
    float PlatformForceMultiplier = 500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
    float RotationForceMultiplier = 300.0f;
    // 여기까지 0203_2
    UPROPERTY(EditDefaultsOnly, Category = "Physics", meta = (DisplayName = "Ball Physics Material"))
    TObjectPtr<UPhysicalMaterial> BallPhysicsMaterial;

private:
    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};

