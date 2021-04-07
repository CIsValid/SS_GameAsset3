// Copyright Epic Games, Inc. All Rights Reserved.

#include "SS_GameAsset3GameMode.h"
#include "SS_GameAsset3Character.h"
#include "UObject/ConstructorHelpers.h"

ASS_GameAsset3GameMode::ASS_GameAsset3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
