// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MVUTILSTOOLS_API MvDM_CoordinateTools
{
public:
	MvDM_CoordinateTools();
	~MvDM_CoordinateTools();

	static FVector ConvertUnityPos(float posX, float posY, float posZ);
	static FQuat ConvertUnityRot(float rotX, float rotY, float rotZ, float rotW);
	static FQuat ToUnityRot(float rotX, float rotY, float rotZ, float rotW);
	static FVector ConvertUnityScale(float scaleX, float scaleY, float scaleZ);
};
