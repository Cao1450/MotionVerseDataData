// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MvSkeletonTree.h"

/**
 * 
 */
class MVRETARGET_API MvSkeletonTreeUE : public MvSkeletonTree
{
public:
	MvSkeletonTreeUE();
	~MvSkeletonTreeUE();

	void init_exclude_bones();
	TMap<FName, int> retarget_exclude_bones_map;

private:
	const TArray<FName> retarget_exclude_left_fingers = {
		//
		"index_01_l",
		"index_02_l",
		"index_03_l",
		//
		"middle_01_l",
		"middle_02_l",
		"middle_03_l",
		//
		"pinky_01_l",
		"pinky_02_l",
		"pinky_03_l",
		//
		"ring_01_l",
		"ring_02_l",
		"ring_03_l",
	};

	const TArray<FName> retarget_exclude_right_fingers = {
		//
		"index_01_r",
		"index_02_r",
		"index_03_r",
		//
		"middle_01_r",
		"middle_02_r",
		"middle_03_r",
		//
		"pinky_01_r",
		"pinky_02_r",
		"pinky_03_r",
		//
		"ring_01_r",
		"ring_02_r",
		"ring_03_r",
	};

protected:
	virtual void buildTree() override;
	virtual void setTPose(TArray<FName>& boneNames, TArray<FTransform>& poses_in_parent) override;
};