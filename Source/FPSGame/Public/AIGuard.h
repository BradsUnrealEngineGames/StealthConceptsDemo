// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIGuard.generated.h"

class UPawnSensingComponent;
class AAINavigationVertex;

UENUM(BlueprintType)
enum class EAIState : uint8
{
	Idle,
	Suspicious,
	Alerted
};

UCLASS()
class FPSGAME_API AAIGuard : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIGuard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPawnSensingComponent* PawnSensingComp;

	UFUNCTION()
	void OnPawnSeen(APawn* SeenPawn);

	UFUNCTION()
	void OnPawnHeard(APawn* HeardPawn, const FVector& Location, float Volume);

	FRotator OriginalRotation;

	FTimerHandle TimerHandle_ResetOrientation;

	EAIState GuardState;

	void SetGuardState(EAIState NewState);

	UFUNCTION(BlueprintImplementableEvent, Category = "Status")
	void OnStateChanged(EAIState NewState);

	UPROPERTY(EditAnywhere, Category = "Properties")
	AAINavigationVertex* FirstPatrolPoint = nullptr;

	UPROPERTY(EditAnywhere, Category = "Properties")
	AAINavigationVertex* SecondPatrolPoint = nullptr;

	AAINavigationVertex* CurrentPatrolPoint = nullptr;

	float MoveAcceptanceRadius = 100;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCapsuleComponent* GuardCollisionComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void ResetOrientation();

	void MoveToNavVertex(AAINavigationVertex* DestinationVertex);

	UFUNCTION()
	void ChangeCurrentPatrolPoint(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
