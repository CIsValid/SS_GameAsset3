// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Fmod3DAudioEmitter.generated.h"

UCLASS()
class SS_GAMEASSET3_API AFmod3DAudioEmitter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFmod3DAudioEmitter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
