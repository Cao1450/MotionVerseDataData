// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MVUTILSTOOLS_API MvDllLoader
{
public:
	MvDllLoader(TArray<FString> dllPaths, bool showTips);
	~MvDllLoader();

private:
	TArray<void*> m_dllHandles;
};
