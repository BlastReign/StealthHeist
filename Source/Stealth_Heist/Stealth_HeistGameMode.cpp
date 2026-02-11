// Copyright Epic Games, Inc. All Rights Reserved.

#include "Stealth_HeistGameMode.h"
#include "Stealth_HeistCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStealth_HeistGameMode::AStealth_HeistGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
