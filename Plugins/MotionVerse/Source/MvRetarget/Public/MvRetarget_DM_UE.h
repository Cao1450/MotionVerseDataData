// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class MvSkeletonTreeDM;
class MvSkeletonTreeUE;

class MvHuman_Skeleton;


struct FTransformPoint
{
	FTransform Source;
	FTransform Dest;
};

/**
 *
 */
class MVRETARGET_API MvRetarget_DM_UE
{
public:
	MvRetarget_DM_UE();
	virtual ~MvRetarget_DM_UE();
	void init();

	void updateSrcSkeleton(TArray<FName> boneNames, TArray<FTransform> poses) const;
	void updateDesSkeleton(bool ignoreFinger = false) const;

	TArray<FName> getMetaBoneName() const;
	FTransform getMetaBonePose(FName metaBoneName);

protected:
	TMap<FName, FName> m_boneMapper;

	MvSkeletonTreeDM* mSkelTreeDM=nullptr;
	MvSkeletonTreeUE* mSkelTreeUE=nullptr;

	TArray<FName> mDMBoneNamesOrder;
	TArray<FName> mUEBoneNamesOrder;

private:
	int getIndex(FString name, const TArray<FString> names);

public:
	FTransform getTPose(FName metaBoneName);
};