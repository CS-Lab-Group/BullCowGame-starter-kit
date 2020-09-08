// Fill out your copyright notice in the Description page of Project Settings.


#include "CowCloud.h"
#include "Engine/World.h"

// Sets default values
ACowCloud::ACowCloud()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACowCloud::BeginPlay()
{
	Super::BeginPlay();

	Spawn();



	// UBullCowCartridge* CowBull = GetOwner()->FindComponentByClass<UBullCowCartridge>();
	// CowBull->GameEnd.AddDynamic(this, &ACowCloud::Spawn);
	
} 	

// Called every frame
void ACowCloud::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACowCloud::Spawn()
{
	if(ToSpawn)
	{
		UWorld* world = GetWorld();
		if(world)
		{
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;

			FRotator rotator;

			FVector SpawnLocation = GetActorLocation();

			world->SpawnActor<AActor>(ToSpawn, SpawnLocation, rotator, spawnParams);
		}
	} 
}



