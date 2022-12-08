// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityCamera.h"
#include "MyEditorUtilityCamera.generated.h"

/**
 * 
 */
UCLASS()
class AMyEditorUtilityCamera : public AEditorUtilityCamera
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyEditorUtilityCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere);
	AActor* CameraOne;

	UPROPERTY(EditAnywhere);
	AActor* CameraTwo;

	float TimeToNextCameraChange;

};
