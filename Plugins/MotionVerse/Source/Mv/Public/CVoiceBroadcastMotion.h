// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MvDM_BpFuncLib.h"
#include "Components/ActorComponent.h"
#include "CVoiceBroadcastMotion.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnVoiceBroadcastMotionRet, bool, succeed, const FMvFaceData&, faceData, const FMvBodyData&, bodyData, const TArray<uint8>&, audioBytes, float, totalTime);

UCLASS()
class MV_API UCVoiceBroadcastMotion : public UObject
{
	GENERATED_BODY()

public:
	static UCVoiceBroadcastMotion* CreateVoiceBroadcastMotion(const FString& token, const FString& url);
	
	//UFUNCTION(BlueprintCallable, Category="MotionVerse", meta=(AdvancedDisplay = "1"))
	void VoiceToMotion(
		const FString& audio_url,
		const FString& audio_format="wav",
		int is_cache=0,
		const FString& face_gender="female",
		int face_tag=2,
		int face_type=2,
		int body_motion=2,
		int body_filter_window=15,
		int body_filter_order=3,
		bool body_fixed=false,
		int body_head_x_rot=0,
		bool body_compress=false);

	UPROPERTY(BlueprintAssignable, Category="MotionVerse")
	FOnVoiceBroadcastMotionRet OnVoiceBroadcastMotionRet;

private:
	//
	FString token="";
	FString mApi="";

	//
	bool autoRetry=false;
	int retryCount=0;

	
	FString m_audio_url="";
	FString mJsonStr;
	int mFaceType=2;
	
	void DoRequestMotion();
	UFUNCTION()
	void OnRequestMotionRet(bool succeed, const FString& responseStr);
	UFUNCTION()
	void OnTtsDownloadRet(bool audioRet, const TArray<uint8>& audioBytes, bool faceRet, const FString& faceJson, bool bodyRet, const FString& bodyJson);
};
