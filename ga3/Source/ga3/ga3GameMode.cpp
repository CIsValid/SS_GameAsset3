// Copyright Epic Games, Inc. All Rights Reserved.

#include "ga3GameMode.h"
#include "ga3Character.h"
#include "UObject/ConstructorHelpers.h"

Aga3GameMode::Aga3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
