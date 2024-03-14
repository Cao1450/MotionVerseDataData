// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

struct MvSkeletonTreeNode
{
	FName jointName;
	//int jointIndex;
	
	FName parentJointName;
	TArray<FName> childJointNames;
	
	FTransform pose_in_parent;

	FTransform t_pose_in_parent;
	FTransform t_pose_in_world;
};

/**
 * 
 */
class MVRETARGET_API MvSkeletonTree
{
public:
	MvSkeletonTree();
	virtual ~MvSkeletonTree();

	void init();
	void update(TArray<FName> boneNames, TArray<FTransform> poses_in_local);
	FName getParentName(FName name);

	FTransform get_pose_in_local(FName name);
	FTransform get_t_pose_in_local(FName name);
	
	FTransform get_pose_in_world(FName name);
	FTransform get_t_pose_in_world(FName name);

	void set_pose_in_local(FName name, FTransform pose_in_local);
	
	void printTree();
private:
	void printBoneNameInfo(FName boneName,int level);

	
protected:
	virtual void buildTree();
	virtual void setTPose(TArray<FName>& boneNames, TArray<FTransform>& poses_in_parent);
	
	void buildNode(int index,FString name,FString parentName,TMap<FName,MvSkeletonTreeNode>& tree,TArray<FName>& jointNames);

protected:
	TMap<FName,MvSkeletonTreeNode> m_tree;
	TArray<FName> m_jointNames;
	FName m_rootJointName;
};
