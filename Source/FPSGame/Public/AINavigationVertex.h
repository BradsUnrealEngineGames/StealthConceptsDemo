// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AINavigationVertex.generated.h"

class USphereComponent;

UCLASS()
class FPSGAME_API AAINavigationVertex : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAINavigationVertex();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* VisualAidSphere;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
