// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCowOrBull);



struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows  = 0;
};

// DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameEnded);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge	
{
	GENERATED_BODY()

	public:

	// UPROPERTY(BlueprintAssignable, Category = "EventDispatchers")
	// FGameEnded GameEnd;
	
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void SetupGame();
	void EndGame();
	void ProcessGuess(const FString& Guess); 
	bool IsIsogram(const FString& Word) const;
	TArray<FString> GetValidWords(const TArray<FString>& WordList) const;
	FBullCowCount GetBullCows(const FString& Guess) const;

	UPROPERTY(bluePrintAssignable, Category = "EventDispacher")
	FCowOrBull CowOrBullIncreased;

	// Your declarations go below!
	private:
	FString HiddenWord;
	int32 Lives;
	bool bGameOver;
	TArray<FString> Isograms;
	
};
