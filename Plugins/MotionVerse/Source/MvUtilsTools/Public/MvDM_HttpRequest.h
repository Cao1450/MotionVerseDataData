// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "UObject/NoExportTypes.h"
#include "MvDM_HttpRequest.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequestCompleted, FString, responseStr);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRequestCompleted, bool, requestRet, const FString&, responseStr);

// DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequestComplete, class UVaRestRequestJSON*, Request);
// DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequestFail, class UVaRestRequestJSON*, Request);
//
// DECLARE_MULTICAST_DELEGATE_OneParam(FOnStaticRequestComplete, class UVaRestRequestJSON*);
// DECLARE_MULTICAST_DELEGATE_OneParam(FOnStaticRequestFail, class UVaRestRequestJSON*);

UENUM(BlueprintType)
enum class MvDM_HttpVerb :uint8
{
	GET, POST
};

// UENUM(BlueprintType)
// enum class DM_RequestContentType : uint8
// {
// 	x_www_form_urlencoded_url	UMETA(DisplayName = "x-www-form-urlencoded (URL)"),
// 	x_www_form_urlencoded_body	UMETA(DisplayName = "x-www-form-urlencoded (Request Body)"),
// 	json,
// 	binary
// };

/**
 *
 */
UCLASS(BlueprintType, Category = "MvDM_Functions|UtilsTools")
class MVUTILSTOOLS_API UMvDM_HttpRequest : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "MvDM_Functions|UtilsTools")
		FOnRequestCompleted OnCompleted;

	UPROPERTY(BlueprintAssignable, Category = "MvDM_Functions|UtilsTools")
		FOnRequestCompleted OnGetAppTokenCompleted;

	// UPROPERTY(BlueprintReadOnly, Category = "MvDM_Functions|UtilsTools")
	// FString URL;
	//
	// UPROPERTY(BlueprintReadOnly, Category = "MvDM_Functions|UtilsTools")
	// TArray<uint8> RequestBody;

	UPROPERTY(BlueprintReadOnly, Category = "MvDM_Functions|UtilsTools")
		bool mPrintLog=false;

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static UMvDM_HttpRequest* CreateHttpRequest();

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		void DoRequest(const FString& inURL, const TArray<uint8>& inRequestBody, bool inShowDebug);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		void DoRequestEasy(const FString& token, const FString& inURL, const FString& content, MvDM_HttpVerb verb, bool printLog = true, int timeout = 5);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		void DoRequestForm(const FString& Application, const FString& token, const FString& inURL, const FString& content, MvDM_HttpVerb verb, bool printLog = true, int timeout = 5);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		void DoRequestTest(const FString& inURL, MvDM_HttpVerb verb, const TArray<uint8>& contentBytes, const FString& contentUtf8, const float& timeoutInSecond, bool inShowDebug);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		void GetAppToken(const FString& inURL, const FString& appid, const FString& secret, MvDM_HttpVerb verb, bool printLog = true, int timeout = 5);

private:
	FString mUrl;
	FString mContent;

private:
	void OnRequestCompleted(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);

	void OnRequestAppTokenCompleted(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);
};
