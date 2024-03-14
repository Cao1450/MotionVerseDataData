// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "UObject/NoExportTypes.h"
#include "MvDM_TTSHttpDownload.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnTtsDownloadCompleted, bool, audioRet, const TArray<uint8>&, audioBytes, bool, faceRet, const FString&, faceJson, bool, bodyRet, const FString&, bodyJson);

struct MvDownloadEntity
{
	FHttpRequestPtr ptr;
	bool needBytes=false;
	bool completed=false;
	bool responseValid=false;
	TArray<uint8> responseBytes;
	FString responseStr;
};

/**
 * 
 */
UCLASS(BlueprintType, Category = "MvDM_Functions|MVTools")
class MVUTILSTOOLS_API UMvDM_TTSHttpDownload : public UObject
{

	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable, Category = "MvDM_Functions|MVTools")
	FOnTtsDownloadCompleted OnCompleted;
	
	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|MVTools")
	static UMvDM_TTSHttpDownload* CreateTTSHttpDownload();

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|MVTools")
	void DoDownload(FString audioUrl, FString faceUrl, FString bodyUrl, bool printLog = true);

private:
	void OnRequestCompleted(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);

private:
	bool mPrintLog = false;

	FString mAudioUrl;
	FString mFaceUrl;
	FString mBodyUrl;
	
	TArray<MvDownloadEntity> requestEntitys;
};
