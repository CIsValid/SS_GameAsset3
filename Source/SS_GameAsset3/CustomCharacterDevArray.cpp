// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomCharacterDevArray.h"

// Sets default values
ACustomCharacterDevArray::ACustomCharacterDevArray()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Just setting the default for the collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.0f,96.0f);

	// Create camera components
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.0f));
	CameraComponent->bUsePawnControlRotation = true;

	bIsJumping = false;
	bIsCrouching = false;

}

// Called when the game starts or when spawned
void ACustomCharacterDevArray::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomCharacterDevArray::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bIsJumping){ Jump(); }
	if(bIsCrouching){ Crouch(); }
}

void ACustomCharacterDevArray::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// Keyboard axis bindings
	PlayerInputComponent->BindAxis("MoveForward", this, &ACustomCharacterDevArray::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACustomCharacterDevArray::MoveRight);

	// Keyboard action binding
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACustomCharacterDevArray::CheckJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACustomCharacterDevArray::CheckJump);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ACustomCharacterDevArray::CheckCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ACustomCharacterDevArray::CheckCrouch);
	
	// Mouse axis bindings
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

void ACustomCharacterDevArray::MoveForward(float Value)
{
	if(Value != 0)
	{
		AddMovementInput(GetActorForwardVector(),Value);
	}
}

void ACustomCharacterDevArray::MoveRight(float Value)
{
	if(Value != 0)
	{
		AddMovementInput(GetActorRightVector(),Value);
	}
}

void ACustomCharacterDevArray::CheckJump()
{
	bIsJumping = bIsJumping ? false : true;
}

void ACustomCharacterDevArray::CheckCrouch()
{
	bIsCrouching = bIsCrouching ? false : true;
}

