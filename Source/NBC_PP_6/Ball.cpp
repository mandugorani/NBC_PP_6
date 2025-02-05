// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "MovingPlatform.h"
#include "ARotatingPlatform.h"
#include "MovingPlatform2.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

ABall::ABall()
{
	PrimaryActorTick.bCanEverTick = true;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	RootComponent = BallMesh;

	BallMesh->SetSimulatePhysics(true);
	BallMesh->SetCollisionProfileName(TEXT("PhysicsActor"));
	BallMesh->SetAngularDamping(0.5f);
	BallMesh->SetLinearDamping(0.2f);
	if (BallPhysicsMaterial != nullptr)
	{
		BallMesh->SetPhysMaterialOverride(BallPhysicsMaterial.Get());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("BallPhysicsMaterial test(fail)"));
	}
}


void ABall::BeginPlay()
{
	Super::BeginPlay();

	BallMesh->OnComponentHit.AddDynamic(this, &ABall::OnHit);
	// 충돌 0203_2
}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (AMovingPlatform* MovingPlatform = Cast<AMovingPlatform>(OtherActor))
	{
		FVector PlatformVelocity = MovingPlatform->GetVelocity();
		BallMesh->AddImpulse(PlatformVelocity * PlatformForceMultiplier, NAME_None, true);
		// 무빙플랫폼과 충돌시 함수 0203_2
		// 스켈레탈 메시가 아니라서 NAME_None 사용한다고 함
	}

	if (AARotatingPlatform* RotatingPlatform = Cast<AARotatingPlatform>(OtherActor))
	{

		FVector ToBall = GetActorLocation() - RotatingPlatform->GetActorLocation();
		FVector Tangent = FVector::CrossProduct(RotatingPlatform->RotationAxis, ToBall).GetSafeNormal();
		// 코파일럿 훈수 0203_3

		BallMesh->AddImpulse(Tangent * RotatingPlatform->RotationSpeed * RotationForceMultiplier);
	}
}