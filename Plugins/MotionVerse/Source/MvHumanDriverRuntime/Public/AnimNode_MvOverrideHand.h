// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AnimNode_MvOverrideHand.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct MVHUMANDRIVERRUNTIME_API FAnimNode_MvOverrideHand : public FAnimNode_Base
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Links)
	FPoseLink BasePose;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Links)
	FPoseLink OverridePose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta=(PinShownByDefault))
	bool IsMH=true;
	
public:
	FAnimNode_MvOverrideHand();
	~FAnimNode_MvOverrideHand();


	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual void Evaluate_AnyThread(FPoseContext& Output) override;

private:
	TArray<int32> meshPoseIndexs;
};
