// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MvFaceData.h"
#include "MvBodyData.h"
#include "MvDM_BpFuncLib.h"
#include "Components/ActorComponent.h"
#include "CMVDataSource.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayFaceData, const FMvFaceData&, faceData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayBodyData, const FMvBodyData&, bodyData);



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MV_API UCMVDataSource : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MotionVerse")
	FString AppId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MotionVerse")
	FString Secret;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MotionVerse")
	MvRegion Region = MvRegion::ZH_CN;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MotionVerse")
	FMvAPIConfig APIConfig;
	
	FString GetTokenAPI();
	
	FString GetTextBroadcastMotionAPI();
	
	UFUNCTION(BlueprintCallable, Category="MotionVerse", meta=(AdvancedDisplay = "1"))
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
	
	FString GetVoiceBroadcastMotionAPI();

	UFUNCTION(BlueprintCallable, Category="MotionVerse", meta=(AdvancedDisplay = "1"))
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
			bool body_compress=false
		);
	
	FString GetAnswerCollectUrl();

	UFUNCTION(BlueprintCallable, Category="MotionVerse", meta=(AdvancedDisplay = "1"))
	void AnswerToMotion(
			const FString& text,
			const FString& audio_format="wav",
			const FString& tts_voice_name="aixia",
			int tts_speed=50,
			int tts_volume=50,
			int tts_fm=50,
			int face_type=2,
			const FString& face_gender="male",
			int face_tag=0,
			int body_motion=3,
			int body_filter_window=15,
			int body_filter_order=3,
			bool body_fixed_hips=false,
			int body_head_x_rot=0,
			bool body_compress=false
		);
	
	
	UPROPERTY(BlueprintAssignable, Category="MotionVerse")
	FOnPlayFaceData OnPlayFaceData;
	UPROPERTY(BlueprintAssignable, Category="MotionVerse")
	FOnPlayBodyData OnPlayBodyData;

	
	// Sets default values for this component's properties
	UCMVDataSource();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool IsTokenValid() const;
	FString GetToken() const;

private:

	void Init();

	bool isPlaying=false;
	//token
    FString mToken="";
    UFUNCTION()
    void OnRequestTokenRet(bool succeed, const FString& responseStr);

	UFUNCTION()
	void PlayRawData(bool succeed, const FMvFaceData& faceData, const FMvBodyData& bodyData, const TArray<uint8>& audioBytes, float totalTime);

	UFUNCTION()
	void OnPlayOverRet();
public:
	UCAudio* mAudio = nullptr;

};
