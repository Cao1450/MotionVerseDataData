// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MvQuatCurve.h"
#include "MvBodyData.h"
#include "AnimNode_MvBodyRawData.generated.h"

class MvRetarget_DM_UE;

/**
 *
 */
USTRUCT(BlueprintType)
struct MVHUMANDRIVERRUNTIME_API FAnimNode_MvBodyRawData : public FAnimNode_Base
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Links)
	FPoseLink BasePose;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
	FMvBodyData inBodyData;//FString BodyData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
	EMVSkeletonType MVSkeletonType = EMVSkeletonType::UE;//FString BodyData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
	bool IsMHIgnoreFinger = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
	float moveScale = 1;
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings, meta = (PinShownByDefault))
	bool bShowLog = true;//false;
	
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual void Evaluate_AnyThread(FPoseContext& Output) override;
	virtual void GatherDebugData(FNodeDebugData& DebugData) override;

	FAnimNode_MvBodyRawData();
	virtual ~FAnimNode_MvBodyRawData() override;

private:
	float sampleTime = 0;
	
	//实际采样的数据
	FMvBodyData mBodyData;
	
public:
	MvRetarget_DM_UE* retargetPtr = nullptr;
	//TSharedPtr<Retarget_DM_MH> retargetPtr;
	//Retarget_DM_MH retarget;

};
