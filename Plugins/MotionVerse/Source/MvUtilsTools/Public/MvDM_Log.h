// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Logging/LogMacros.h"
#include <iostream>
#include <fstream>
#include "Components/SkeletalMeshComponent.h"

DECLARE_LOG_CATEGORY_EXTERN(MvDM, Log, All);

#define MvDM_WRITE_LOG(msg) \
	MvDM_Log::GetInstance().Log(msg)

#define MvDM_WRITE_LOG_VARS(Fmt, ...)								\
	{																\
		FString msg = FString::Printf(TEXT(Fmt), ##__VA_ARGS__ );	\
		MvDM_WRITE_LOG(msg);											\
	}

#define MvDM_PrintLn(Fmt, ...) UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::Printf(TEXT(Fmt), ##__VA_ARGS__ ))
//#define MvDM_PrintLn(Fmt, ...) UE_LOG( ##DM_LOG_TYPE, Warning, TEXT("%s"), *FString::Printf(TEXT(Fmt), ##__VA_ARGS__ ))

/**
 * 增加DM_LIVELINK_API标识，方便其他模块引用
 */
class MVUTILSTOOLS_API MvDM_Log
{

private:
	MvDM_Log();
	~MvDM_Log();
public:

	void Log(const FString& msg);

	//static void print(FString fmt, ...);
	static void printTransform(FString msg, FTransform tf);
	static void printTransform(FString msg, FString msg0, FTransform tf0, FString msg1, FTransform tf1);
	static void printInt(FString msg, int val);
	static void printFloat(FString msg, float val);
	static void printString(FString msg);
	static void printQuat(FString msg, FQuat quat);
	static void printVector(FString msg, FVector vec);
	static void printSkeleton(USkeletalMeshComponent* skel);

	//
	static void printString_ScreenLog(FString msg);

public:
	static MvDM_Log& GetInstance();
	void Release();
	
private:
	static MvDM_Log* mInstancePtr;
	std::ofstream mFout;
	
};
