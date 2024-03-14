// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimCurveTypes.h"
#include "MvFaceData.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct MVUTILSTOOLS_API FMvFaceData
{
	GENERATED_USTRUCT_BODY()

public:
	FMvFaceData();
	virtual ~FMvFaceData();

	UPROPERTY(BlueprintReadWrite, Category="MotionVerse")
	int64 id=0;
	
	UPROPERTY(BlueprintReadWrite, Category="MotionVerse")
	float totalTime = 0;

	TArray<FString> curveNames;
	
	//UPROPERTY(BlueprintReadWrite, Category="MotionVerse")
	TArray<TArray<float>> rawdata;

	//UPROPERTY(BlueprintReadWrite, Category="MotionVerse")
	TArray<FFloatCurve> curves;
};