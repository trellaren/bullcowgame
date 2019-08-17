// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Math/UnrealMathUtility.h"

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
    // if(GuessCount >= 1)
    // {
    PrintGuesses();
    if(GuessesRemaining > 0)
    {
        if(Input != HiddenWord)
        {
            PrintLine(TEXT("Wrong! You guessed: " + Input));
            --GuessesRemaining;    
            ++GuessCount;
        }
        else
        {
            PrintLine(TEXT("Good job! " + Input + " is correct."));
            PrintLine(TEXT("\nWould you like to start a new game? \n(y for yes and n for no)"));
            if(Input == "y")
            {
                // ClearScreen();
                InitGame();
            }
            else
            {
                ClearScreen();
                
                // GIsRequestingExit = 1; // Shuts the game down.
            }
        }
    }
    else
    {
        ClearScreen();
        PrintLine(TEXT("The word was: " + HiddenWord));
        PrintLine(TEXT("\nWould you like to start a new game? \n(y for yes and n for no)"));
        if(Input == "y")
        {
            // ClearScreen();
            InitGame();
        }

    }
    // }
    // else
    // {
    //     PrintGuesses();
    //     ++GuessCount;
    // }
}

void UBullCowCartridge::InitGame()
{
    GetRandomWord();
    HiddenWord = RandomWord;
    WordLength = HiddenWord.Len();
    WordLen = HiddenWord.FromInt(WordLength);
    GuessesRemaining = WordLength - 1;
    GuessCount = 0;
    NormalWord = HiddenWord.GetCharArray();
    ScrambledWord.Empty();
    AppendScrambledChars();
}

void UBullCowCartridge::PrintGuesses()
{
    PrintLine(TEXT("Word Length: " + WordLen));
    PrintLine(TEXT("Available Letters: [" + ScrambledWord + "]"));
    PrintLine(TEXT("Remaining Guesses: " + GuessString.FromInt(GuessesRemaining)));
}

void UBullCowCartridge::GetRandomWord()
{
    ListOfWords = {"consider", "minute", "accord", "evident", "practice", "intend", "concern", "commit", "issue", 
    "approach", "establish", "utter", "conduct", "engage", "obtain", "scarce", "policy", "straight", "stock", 
    "apparent", "property", "fancy", "concept", "court", "appoint", "passage", "vain", "instance", "coast", 
    "project", "commission", "constant", "circumstances", "constitute", "level", "affect", "institute", 
    "render", "appeal", "generate", "theory", "range", "campaign", "league", "labor", "confer", "grant", 
    "dwell", "entertain", "contract", "earnest", "yield", "wander", "insist", "knight", "convince", 
    "inspire", "convention", "skill", "harry", "financial", "reflect", "novel", "furnish", "compel", 
    "venture", "territory", "temper", "bent", "intimate", "undertake", "majority", "assert", "crew", 
    "chamber", "humble", "scheme", "keen", "liberal", "despair", "tide", "attitude", "justify", "flag", 
    "merit", "manifest", "notion", "scale", "formal", "resource", "persist", "contempt", "tour", "plead", 
    "weigh", "mode", "distinction", "inclined", "attribute", "exert", "oppress", "contend", "stake", 
    "toil", "perish", "disposition", "rail", "cardinal", "boast", "advocate", "bestow", "allege", "notwithstanding", 
    "lofty", "multitude", "steep", "heed", "modest", "partial", "apt", "esteem", "credible", "provoke", "tread", 
    "ascertain", "fare", "cede", "perpetual", "decree", "contrive", "derived", "elaborate", "substantial", 
    "frontier", "facile", "cite", "warrant", "sob", "rider", "dense", "afflict", "flourish", "ordain", "pious", 
    "vex", "gravity", "suspended", "conspicuous", "retort", "jet", "bolt", "assent", "purse", "plus", "sanction", 
    "proceeding", "exalt", "siege"};


    RandomNumber = FMath::RandHelper(ListOfWords.Max());
    RandomWord = ListOfWords[RandomNumber];
}

// TODO: Fix this function
void UBullCowCartridge::AppendScrambledChars()
{
    NormalWord.HeapSort();

    for(auto var : NormalWord)
    {
        ScrambledWord.AppendChar(var);
    }
}