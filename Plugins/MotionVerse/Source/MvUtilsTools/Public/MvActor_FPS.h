// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MvActor_FPS.generated.h"

UCLASS()
class MVUTILSTOOLS_API AMvActor_FPS : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMvActor_FPS();

	UPROPERTY(EditAnywhere, Category = "DM_FPS")
	bool EnableCustomFps = false;
	UPROPERTY(EditAnywhere, Category = "DM_FPS")
	int CustomFps = 60;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//
	double m_during = 0;
	long m_frameNum = 0;
	
};
