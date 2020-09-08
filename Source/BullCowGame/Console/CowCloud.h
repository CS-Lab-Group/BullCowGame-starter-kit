// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BullCowCartridge.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CowCloud.generated.h"

UCLASS()
class BULLCOWGAME_API ACowCloud : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACowCloud();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> ToSpawn;

	UFUNCTION(BlueprintCallable)
	void Spawn();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
