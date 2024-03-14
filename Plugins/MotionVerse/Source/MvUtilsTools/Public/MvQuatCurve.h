// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math/UnrealMathUtility.h"
#include "MvQuatCurve.generated.h"

USTRUCT()
struct FMvQuatCurveKey
{
	GENERATED_USTRUCT_BODY()

	//UPROPERTY()
	float time;

	//UPROPERTY()
	FQuat quat;

	// //UPROPERTY()
	// float w;
	// //UPROPERTY()
	// float x;
	// //UPROPERTY()
	// float y;
	// //UPROPERTY()
	// float z;

	virtual ~FMvQuatCurveKey();
};

/**
 * 
 */
USTRUCT()
struct MVUTILSTOOLS_API FMvQuatCurve
{
	GENERATED_USTRUCT_BODY()

	FMvQuatCurve();
	virtual ~FMvQuatCurve();
	
	FQuat Evaluate(float time, float KeyTimeTolerance = KINDA_SMALL_NUMBER) const;
	void UpdateOrAddKey(float time, const FQuat& quat, float KeyTimeTolerance = KINDA_SMALL_NUMBER);

	static FQuat halfSearch(const float time, const TArray<FMvQuatCurveKey>& keys, const int startIndex, const int endIndex, const float KeyTimeTolerance = KINDA_SMALL_NUMBER);

	//UPROPERTY()
	TArray<FMvQuatCurveKey> m_keys;

	//static FQuat MakeFQuat(const FQuatCurveKey& key);
};
