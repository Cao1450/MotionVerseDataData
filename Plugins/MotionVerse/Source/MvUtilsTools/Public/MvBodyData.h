// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MvQuatCurve.h"
#include "Animation/AnimCurveTypes.h"
#include "MvBodyData.generated.h"

UENUM(BlueprintType)
enum class EMVSkeletonType : uint8
{
	DM,
	UE,
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct MVUTILSTOOLS_API FMvBodyData
{
	GENERATED_USTRUCT_BODY()
	
public:
	FMvBodyData();
	virtual ~FMvBodyData();

	UPROPERTY(BlueprintReadWrite, Category="MotionVerse")
	int64 id=0;
	
	UPROPERTY(BlueprintReadWrite, Category="MotionVerse")
	float totalTime=0;

	//UPROPERTY(BlueprintReadWrite, Category="MotionVerse")
	TArray<FString> bodyNames;

	//UPROPERTY(BlueprintReadWrite, Category="MotionVerse")
	TArray<TArray<FQuat>> bodyQuatss;

	//UPROPERTY(BlueprintReadWrite, Category="MotionVerse")
	TArray<FMvQuatCurve> bodyQuatCurves;

	//UPROPERTY(BlueprintReadWrite, Category="MotionVerse")
	FVectorCurve bodyHipsPosCurve;

	//UPROPERTY(BlueprintReadWrite, Category="MotionVerse")
	FVector bodyHipsPosFirst;

	FString GetNamesStr() const
	{
		FString ret = "";
		for(auto bodyName : bodyNames)
		{
			ret+=bodyName+",";
		}
		return ret;
	}
};


///**
// * 
// */
//USTRUCT(BlueprintType)
//struct MVUTILSTOOLS_API FMvConfigData
//{
//	GENERATED_USTRUCT_BODY()
//
//public:
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	TArray<FName> locks;
//	
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	TMap<FName, float> Weights;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	float moveScale = 1;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	float bsScale = 1;
//};
