// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    InitGame();

    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the " + WordLen + " letter word!")); 
    PrintLine(TEXT("Press tab then enter when you are ready to continue...")); // Tab likely only an issue in build mode.
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    if(GuessCount >= 1)
    {
        PrintLine(TEXT("You're looking for a word that is " + WordLen + " letters long."));
        PrintGuesses();
        if(GuessesRemaining > 0)
        {
            if(Input != HiddenWord)
            {
                PrintLine(TEXT("Wrong! You guessed: " + Input + ". \n Try again."));
                --GuessesRemaining;    
                ++GuessCount;
            }
            else
            {
                PrintLine(TEXT("Good job! " + Input + " is correct."));
            }
        }
        else
        {
            ClearScreen();
            PrintLine(TEXT("You've got no guesses left! \nWould you like to start a new game? \n(y for yes and n for no)"));
            if(Input == "y")
            {
                ClearScreen();
                InitGame();
                PrintLine(TEXT("You're looking for a word that is " + WordLen + " letters long."));
                PrintGuesses();
            }
            else
            {
                PrintLine(TEXT("Please come back soon... \nor don't, I don't give a fuck."));
                // GIsRequestingExit = 1; // Shuts the game down.
            }
            
        }
    }
    else
    {
        PrintLine(TEXT("You're looking for a word that is " + WordLen + " letters long."));
        PrintGuesses();
        ++GuessCount;
    }
    
    // Check if Isogram
    // Decrement Lives
    // Show Lives Remaining
}

void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("scarper");
    WordLength = HiddenWord.Len();
    WordLen = HiddenWord.FromInt(WordLength);
    GuessesRemaining = WordLength - 1;
    GuessCount = 0;
}

void UBullCowCartridge::PrintGuesses()
{
    PrintLine(TEXT("You've got " + GuessString.FromInt(GuessesRemaining) + " guesses to get it right."));
}