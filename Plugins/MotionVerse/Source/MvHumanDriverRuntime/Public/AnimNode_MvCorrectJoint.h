// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimNode_MvCorrectJoint.generated.h"

/**
 * C:\Program Files\Epic Games\UE_5.0\Engine\Source\Editor\AnimGraph\Public\AnimGraphNode_ModifyBone.h
 */
USTRUCT(BlueprintType)
struct MVHUMANDRIVERRUNTIME_API FAnimNode_MvCorrectJoint: public FAnimNode_Base
{
	GENERATED_USTRUCT_BODY()
public:
	FAnimNode_MvCorrectJoint();
	virtual ~FAnimNode_MvCorrectJoint() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Links)
	FPoseLink BasePose;

	UPROPERTY(EditAnywhere, Category="MotionVerse")
	FBoneReference BoneToModify;
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings, meta=(PinShownByDefault))
	//FString jointName="Root";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings, meta=(PinShownByDefault))
	FVector eulerAngles=FVector(0,0,90);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings, meta=(PinShownByDefault))
	FVector pos=FVector(0,0,0);
	
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual void Evaluate_AnyThread(FPoseContext& Output) override;
};
