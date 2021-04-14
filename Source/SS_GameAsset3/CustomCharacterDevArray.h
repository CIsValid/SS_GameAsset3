// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "CustomCharacterDevArray.h"
#include "CustomCharacterDevArray.generated.h"

UCLASS()
class SS_GAMEASSET3_API ACustomCharacterDevArray : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACustomCharacterDevArray();

	// First person camera
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=Camera,meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void CheckJump();
	void CheckCrouch();
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=Checks)
	bool bIsJumping;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=Checks)
	bool bIsCrouching;

};
