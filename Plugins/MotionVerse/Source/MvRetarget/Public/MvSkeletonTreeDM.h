// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MvSkeletonTree.h"

/**
 * 
 */
class MVRETARGET_API MvSkeletonTreeDM: public MvSkeletonTree
{
public:
	MvSkeletonTreeDM();
	virtual ~MvSkeletonTreeDM();

protected:
	virtual void buildTree() override;
	virtual void setTPose(TArray<FName>& boneNames, TArray<FTransform>& poses_in_parent) override;
};