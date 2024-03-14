// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MvFaceData.h"
#include "AnimNode_MvFaceRawdata.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct MVHUMANDRIVERRUNTIME_API FAnimNode_MvFaceRawdata : public FAnimNode_Base
{
	GENERATED_USTRUCT_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Links)
	FPoseLink BasePose;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings, meta=(PinShownByDefault))
	FMvFaceData inFaceData;//FString FaceData;
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta=(PinShownByDefault))
	bool bShowLog=true;//false;
	
	FAnimNode_MvFaceRawdata();
	~FAnimNode_MvFaceRawdata();

	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual void Evaluate_AnyThread(FPoseContext& Output) override;

private:
	float sampleTime=0;

	//实际采样的数据
	FMvFaceData mFaceData;
};
