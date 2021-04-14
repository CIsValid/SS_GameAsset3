// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomCharacterDevArray.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACustomCharacterDevArray::ACustomCharacterDevArray()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Just setting the default for the collision capsule
	GetCapsuleComponent()->InitCapsuleSize(30.0f,96.0f);

	// Create camera components
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->SetRelativeLocation(FVector(23.987591f, 10.89999f, 73.0f));
	CameraComponent->SetRelativeScale3D(FVector(0.3f,0.3f,0.3f));
	CameraComponent->bUsePawnControlRotation = true;

	BaseTurnRate = 65.0f;
	BaseLookUpRate = 65.0f;
	
	bIsJumping = false;
	bIsCrouching = false;
	GetCharacterMovement()->AirControl = 1.0f;
    GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
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
	bIsCrouching ? Crouch() : UnCrouch();
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
	PlayerInputComponent->BindAxis("LookUp", this, &ACustomCharacterDevArray::LookUpAtRate);
	PlayerInputComponent->BindAxis("Turn", this, &ACustomCharacterDevArray::TurnAtRate);
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

void ACustomCharacterDevArray::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACustomCharacterDevArray::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());

}

void ACustomCharacterDevArray::CheckJump()
{
	bIsJumping = bIsJumping ? false : true;
}

void ACustomCharacterDevArray::CheckCrouch()
{
	bIsCrouching = bIsCrouching ? false : true;
}

