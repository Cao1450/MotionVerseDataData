// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MvDM_BpFuncLib.h"
#include "CMVDataSource.h"
#include "Components/ActorComponent.h"
#include "CTextBroadcastMotion.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnTextBroadcastMotionRet, bool, succeed, const FMvFaceData&, faceData, const FMvBodyData&, bodyData, const TArray<uint8>&, audioBytes, float, totalTime);

UCLASS()
class MV_API UCTextBroadcastMotion : public UObject
{
	GENERATED_BODY()

public:
	static UCTextBroadcastMotion* CreateTextBroadcastMotion(const FString& token, const FString& url);
	
	//UFUNCTION(BlueprintCallable, Category="MotionVerse", meta=(AdvancedDisplay = "1", par))
	void TextToMotion(
		const FString& text,
		const FString& audio_format="wav",
		const FString& tts_voice_name="aixia",
		int tts_speed=50,
		int tts_volume=50,
		int tts_fm=50,
		int face_type=2,
		const FString& face_gender="female",
		int face_tag=2,
		int body_motion=3,
		int body_filter_window=15,
		int body_filter_order=3,
		bool body_fixed_hips=false,
		int body_head_x_rot=0,
		bool body_compress=false
		);

	UPROPERTY(BlueprintAssignable, Category="MotionVerse")
	FOnTextBroadcastMotionRet OnTextBroadcastMotionRet;
	
private:
	//
	FString token="";
	FString mApi="";
	
	//TextToMotion
	bool autoRetry=false;
	int retryCount=0;


	FString mText="";
	FString mJsonStr;
	int mFaceType=2;

	void DoRequestMotion();
	UFUNCTION()
	void OnRequestMotionRet(bool succeed, const FString& responseStr);
	UFUNCTION()
	void OnTtsDownloadRet(bool audioRet, const TArray<uint8>& audioBytes, bool faceRet, const FString& faceJson, bool bodyRet, const FString& bodyJson);
};
