// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimNode_MvPrintJoint.generated.h"
/**
 *  记录TPose用
 */
USTRUCT(BlueprintType)
struct MVHUMANDRIVERRUNTIME_API FAnimNode_MvPrintJoint: public FAnimNode_Base
{
	GENERATED_USTRUCT_BODY()
public:
	FAnimNode_MvPrintJoint();
	virtual ~FAnimNode_MvPrintJoint() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Links)
	FPoseLink BasePose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings, meta=(PinShownByDefault))
	FString jointName="pelvis";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings, meta=(PinShownByDefault))
	bool enablePos=true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings, meta=(PinShownByDefault))
	bool enableRot_Euler=true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings, meta=(PinShownByDefault))
	bool enableRot_Quaternion=true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings, meta=(PinShownByDefault))
	bool enableScale=true;

	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual void Evaluate_AnyThread(FPoseContext& Output) override;
};
