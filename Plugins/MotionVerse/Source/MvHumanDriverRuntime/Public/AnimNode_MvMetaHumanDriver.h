// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include <Animation/AnimInstanceProxy.h>
#include <Components/SkeletalMeshComponent.h>
#include "CoreMinimal.h"
#include <Animation/AnimNodeBase.h>
#include "AnimNode_MvMetaHumanDriver.generated.h"

//class MetaHuman_Skeleton;

/**
 * 
 */
USTRUCT(BlueprintType)
struct MVHUMANDRIVERRUNTIME_API FAnimNode_MvMetaHumanDriver : public FAnimNode_Base
{
	GENERATED_USTRUCT_BODY()

	/** Base Pose - This Can Be Entire Anim Graph Up To This Point, or Any Combination of Other Nodes*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Links)//UPROPERTY(EditAnywhere, Category=Settings)
	FPoseLink inBodyPose; //m_InPose; m_开头的变量在蓝图上会出问题

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Links, meta = (PinShownByDefault))//UPROPERTY(EditAnywhere, Category=Settings)
	//bool tPose = false; //m_InPose; m_开头的变量在蓝图上会出问题

	//UPROPERTY(EditAnywhere, Category = Links, meta = (PinShownByDefault))
	//bool UseInnerHandsData = false;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Links, meta = (PinShownByDefault))
	//USkeletalMeshComponent* dmSkeletal;//USkeletalMesh* dmSkeletal;

	//UPARAM(ref)
	//FTransform rootPose;

	UPROPERTY(EditAnywhere, Category = Links, meta = (PinShownByDefault, ClampMin = "0.1", ClampMax = "2.0", ToolTip = "当前角色与动捕演员的腿长比例"))
	float legRatio=1.0;
	
public:
	FAnimNode_MvMetaHumanDriver();
	virtual ~FAnimNode_MvMetaHumanDriver();

	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual void Evaluate_AnyThread(FPoseContext& Output) override;

	virtual void GatherDebugData(FNodeDebugData& DebugData) override;

private:
	AActor* m_owningActor = nullptr;
};
