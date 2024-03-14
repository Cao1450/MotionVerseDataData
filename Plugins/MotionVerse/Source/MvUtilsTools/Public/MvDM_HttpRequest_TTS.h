// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "UObject/NoExportTypes.h"
#include "MvDM_HttpRequest_TTS.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnRequestTTSCompleted, bool, result,const FString, audioUrl, const FString, faceUrl, const FString, bodyUrl);

/**
 * 
 */
UCLASS(BlueprintType, Category = "MvDM_Functions|UtilsTools")
class MVUTILSTOOLS_API UMvDM_HttpRequest_TTS : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "MvDM_Functions|UtilsTools")
	FOnRequestTTSCompleted OnCompleted;

	// UPROPERTY(BlueprintReadOnly, Category = "MvDM_Functions|UtilsTools")
	// FString URL;
	//
	// UPROPERTY(BlueprintReadOnly, Category = "MvDM_Functions|UtilsTools")
	// TArray<uint8> RequestBody;

	UPROPERTY(BlueprintReadOnly, Category = "MvDM_Functions|UtilsTools")
	bool ShowDebug;
	
	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
	static UMvDM_HttpRequest_TTS* CreateHttpRequest_TTS();

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
	void DoRequest(FString url, FString text, FString voiceName, FString speed, FString volume, FString pitch, FString gender, int tag, bool inShowDebug);

private:
	void OnRequestCompleted(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);
};
