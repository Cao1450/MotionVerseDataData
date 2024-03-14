// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "UObject/NoExportTypes.h"
#include "MvDM_HttpDownload.generated.h"


//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDownloadCompleted,bool,ok);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDownloadCompleted, bool, requestRet, FString, responseStr);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDownloadCompleted, bool, requestRet, FString, responseStr, const TArray<uint8>&, responseBytes);
/**
 * 
 */
UCLASS(BlueprintType, Category = "MvDM_Functions|UtilsTools")
class MVUTILSTOOLS_API UMvDM_HttpDownload : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "MvDM_Functions|UtilsTools")
	FOnDownloadCompleted OnCompleted;

	UPROPERTY(BlueprintReadOnly, Category = "MvDM_Functions|UtilsTools")
	bool NeedSave;
	
	UPROPERTY(BlueprintReadOnly, Category = "MvDM_Functions|UtilsTools")
	FString SavePath;
	
	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
	static UMvDM_HttpDownload* CreateHttpDownload();
	
	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
	void DoDownload(const FString inURL, bool inNeedSave, FString inSavePath);

private:
	void OnRequestCompleted(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);
};
