// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEditorUtilityCamera.h"
#include "kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"


// Sets default values
AMyEditorUtilityCamera::AMyEditorUtilityCamera()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyEditorUtilityCamera::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyEditorUtilityCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float TimeBetweenCameraChanges = 2.0f;
	const float SmoothBlendTime = 0.75f;

	TimeToNextCameraChange -= DeltaTime;

	if (TimeToNextCameraChange <= 0.0f)
	{
		TimeToNextCameraChange += TimeBetweenCameraChanges;

		APlayerController* OurPlayer = UGameplayStatics::GetPlayerController(this, 0);

		if (OurPlayer)
		{
			if (CameraTwo && (OurPlayer->GetViewTarget() == CameraOne))
			{
				OurPlayer->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
			}
			else if (CameraOne)
			{
				OurPlayer->SetViewTarget(CameraOne);
			}
		}
	}

}

