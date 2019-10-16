// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackHole.h"
#include "Components/SphereComponent.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Maw = CreateDefaultSubobject<USphereComponent>(FName("Maw"));
	Maw->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	RootComponent = Maw;

	SphereOfEffect = CreateDefaultSubobject<USphereComponent>(FName("SphereOfEffect"));
	SphereOfEffect->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereOfEffect->SetupAttachment(Maw);
}

// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TSet<UPrimitiveComponent*> OutOverlappingComponents;
	SphereOfEffect->GetOverlappingComponents(OutOverlappingComponents);
	for (UPrimitiveComponent* Component: OutOverlappingComponents) {
		if (Component && Component->IsSimulatingPhysics()) {
			Component->AddRadialForce(GetActorLocation(), SphereOfEffect->GetScaledSphereRadius(), -5000000, ERadialImpulseFalloff::RIF_Constant);
		}
	}
	TSet<UPrimitiveComponent*> OutOverlappingComponents2;
	Maw->GetOverlappingComponents(OutOverlappingComponents2);
	for (UPrimitiveComponent* Component : OutOverlappingComponents2) {
		AActor* Owner = Component->GetOwner();
		if(!Cast<ABlackHole>(Owner)) {
			Owner->Destroy();
		}
	}
}

