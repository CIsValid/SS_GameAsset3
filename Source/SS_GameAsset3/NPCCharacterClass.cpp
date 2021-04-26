// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCCharacterClass.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ANPCCharacterClass::ANPCCharacterClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Just setting the default for the collision capsule
	GetCapsuleComponent()->InitCapsuleSize(30.0f,96.0f);


}

// Called when the game starts or when spawned
void ANPCCharacterClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCCharacterClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPCCharacterClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

