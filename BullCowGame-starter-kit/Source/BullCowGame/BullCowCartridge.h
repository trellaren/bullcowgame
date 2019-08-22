// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void InitGame();
	void PrintGuesses();
	void GetRandomWord();
	void AppendScrambledChars();

	// Your declarations go below!
	private:
	FString HiddenWord;
	int32 WordLength;
	FString WordLen;
	FString GuessString;
	int32 GuessCount;
	int32 GuessesRemaining;
	TArray<FString> ListOfWords;
	int32 RandomNumber;
	FString RandomWord;
	TArray<TCHAR> NormalWord;
	FString ScrambledWord;
};
