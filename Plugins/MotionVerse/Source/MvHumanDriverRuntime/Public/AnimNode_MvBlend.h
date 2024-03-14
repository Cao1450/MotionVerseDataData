// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/InputScaleBias.h"
#include "Animation/AnimNodeBase.h"

#include "AnimNode_MvBlend.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct MVHUMANDRIVERRUNTIME_API FAnimNode_MvBlend : public FAnimNode_Base
{

	GENERATED_USTRUCT_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Links)
	FPoseLink ExternPose;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Links)
	FPoseLink IdlePose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings, meta=(PinShownByDefault))
	bool EnableBlend=false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings, meta=(PinShownByDefault))
	float ExternPoseTime=0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings, meta=(PinShownByDefault))
	float BlendTime=0.2f;

public:
	FAnimNode_MvBlend();

	// FAnimNode_Base interface
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual void Evaluate_AnyThread(FPoseContext& Output) override;
	virtual void GatherDebugData(FNodeDebugData& DebugData) override;
	// End of FAnimNode_Base interface

private:
	float lerpVal=0;
	float curTime=0;

	float enterBlendTime0=0;
	float enterBlendTime1=0;

	float exitBlendTime0=0;
	float exitBlendTime1=0;
	
};
