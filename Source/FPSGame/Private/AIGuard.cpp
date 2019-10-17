// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuard.h"
#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AAIGuard::AAIGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));

	PawnSensingComp->OnSeePawn.AddDynamic(this, &AAIGuard::OnPawnSeen);
	PawnSensingComp->OnHearNoise.AddDynamic(this, &AAIGuard::OnPawnHeard);
}

// Called when the game starts or when spawned
void AAIGuard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAIGuard::OnPawnSeen(APawn* SeenPawn) {
	if (!SeenPawn) { return; }
	DrawDebugSphere(GetWorld(), SeenPawn->GetActorLocation(), 32.f, 12, FColor::Yellow, false, 10.f);
}

void AAIGuard::OnPawnHeard(APawn* HeardPawn, const FVector& Location, float Volume) {
	if (!Instigator) { return; }
	DrawDebugSphere(GetWorld(), HeardPawn->GetActorLocation(), 32.f, 12, FColor::Red, false, 10.f);
}

