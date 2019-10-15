// Fill out your copyright notice in the Description page of Project Settings.


#include "SCDObjectiveActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ASCDObjectiveActor::ASCDObjectiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetupAttachment(MeshComp);
}

// Called when the game starts or when spawned
void ASCDObjectiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCDObjectiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

