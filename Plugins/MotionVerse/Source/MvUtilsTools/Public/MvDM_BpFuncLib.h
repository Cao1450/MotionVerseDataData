// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MvBodyData.h"
#include "MvFaceData.h"
#include "Interfaces/IHttpRequest.h"
#include "MvDM_BpFuncLib.generated.h"

UENUM()
enum class MvDM_PathType :uint8
{
	Complete,
	Relative
};

UENUM()
enum class MvDM_PathName :uint8
{
	ProjectDir,
	ProjectContentDir,
	ProjectConfigDir,
	ProjectPluginsDir,
	ExeDir,
};

UENUM(BlueprintType)
enum class MvDM_DateTimePurpose :uint8
{
	LogHeader,
	FileName,
};

UENUM(BlueprintType)
enum class MvDM_StatType :uint8
{
	Fps,
	Unit,
	UnitGraph,
	Engine,
	Game,
	SceneRendering,
	Rhi,
	Gpu,
};

UENUM(BlueprintType)
enum class MvJsonDataType :uint8
{
	VoiceBroadcast=0,
	TextBroadcast,
	AnswerCollect,
};


// UENUM(BlueprintType)
// enum class MvFaceType :uint8
// {
// 	Unknown=0 UMETA(DisplayName="此选项无效", Hidden),
// 	VoiceDrive=1 UMETA(DisplayName="语音驱动"),
// 	PictureDrive UMETA(DisplayName="视素驱动"),
// 	ControlRig UMETA(DisplayName="生成ControlRig数据")
// };
//
// //音频格式
// UENUM(BlueprintType)
// enum class MvAudioFormat : uint8
// {
// 	WAV=0,
// 	MP3,
// 	BASE64,
// };
// const TArray<FString> MvAudioFormatStr={"wav", "mp3", "base64"};
//
// //性别
// UENUM(BlueprintType)
// enum class MvFaceGender:uint8
// {
// 	Male=0,
// 	Female,
// };
// const TArray<FString> MvFaceGenderStr={"male", "female"};
//
// //音色名
// //可以通过枚举对象获取枚举值，不需要再列个string数组
// //https://www.bilibili.com/read/cv21986500/
// UENUM(BlueprintType)
// enum class MvTtsVoiceName:uint8
// {
// 	STELLA=0,
// 	AIFEI,
// 	ANNIE,
// 	RUILIN,
// 	AISHUO,
// 	YAQUN,
// 	SICHENG,
// 	XIAOYUN,
// 	XIAOGANG,
// 	AIDA,
// 	SITONG,
// 	AICHENG,
// 	AIJING,
// 	XIAOBEI,
// 	AILUN,
// 	AITONG,
// 	AIYU,
// 	NINGER,
// 	JIELIDOU,
// 	AIBAO,
// 	AIJIA,
// 	XIAOXIAN,
// 	AIYA,
// 	AIWEI,
// 	RUOXI,
// 	AIMEI,
// 	QIAOWEI,
// 	AIQI,
// 	SIYUE,
// 	GUIJIE,
// 	AIYUE,
// 	XIAOMEI,
// 	AIXIA
// };
// const TArray<FString> MvTtsVoiceNameStr={
// 	"stella",
// 	"aifei",
// 	"annie",
// 	"ruilin",
// 	"aishuo",
// 	"yaqun",
// 	"sicheng",
// 	"xiaoyun",
// 	"xiaogang",
// 	"aida",
// 	"sitong",
// 	"aicheng",
// 	"aijing",
// 	"xiaobei",
// 	"ailun",
// 	"aitong",
// 	"aiyu",
// 	"ninger",
// 	"jielidou",
// 	"aibao",
// 	"aijia",
// 	"xiaoxian",
// 	"aiya",
// 	"aiwei",
// 	"ruoxi",
// 	"aimei",
// 	"qiaowei",
// 	"aiqi",
// 	"siyue",
// 	"guijie",
// 	"aiyue",
// 	"xiaomei",
// 	"aixia",
// };
//
// //body_motion
// //国内、国外用宏定义区分
// UENUM(BlueprintType)
// enum class MvBodyMotion:uint8
// {
// 	//1=自然闲聊 2=通用演讲 3=通用讲解 4=丰富演讲 5=金姐演讲 6=可爱女生 7=站立直播
// 	Unknown=0 UMETA(DisplayName="此选项无效", Hidden),
// 	BodyMotion1 UMETA(DisplayName="自然闲聊"),
// 	BodyMotion2 UMETA(DisplayName="通用演讲"),
// 	BodyMotion3 UMETA(DisplayName="通用讲解"),
// 	BodyMotion4 UMETA(DisplayName="丰富演讲"),
// 	BodyMotion5 UMETA(DisplayName="金姐演讲"),
// 	BodyMotion6 UMETA(DisplayName="可爱女生"),
// 	BodyMotion7 UMETA(DisplayName="站立直播"),
// };
//
// //face_tag
// UENUM(BlueprintType)
// enum class MvFaceTag:uint8
// {
// 	//面部情绪 情绪 0-综合 1-高兴 2-悲伤 3-生气 4-惊讶 5-中立 6-激动 7-沮丧 8-恐惧 9-厌恶
// 	FaceTag0=0 UMETA(DisplayName="综合"),
// 	FaceTag1 UMETA(DisplayName="高兴"),
// 	FaceTag2 UMETA(DisplayName="悲伤"),
// 	FaceTag3 UMETA(DisplayName="生气"),
// 	FaceTag4 UMETA(DisplayName="惊讶"),
// 	FaceTag5 UMETA(DisplayName="中立"),
// 	FaceTag6 UMETA(DisplayName="激动"),
// 	FaceTag7 UMETA(DisplayName="沮丧"),
// 	FaceTag8 UMETA(DisplayName="恐惧"),
// 	FaceTag9 UMETA(DisplayName="厌恶"),
// };


//国内、国外
UENUM(BlueprintType)
enum class MvRegion:uint8
{
	EN_US=0,
	ZH_CN,
};

USTRUCT(BlueprintType)
struct FMvAPIConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MotionVerse")
	FString TokenAPI_EN_US="https://api.motionverse.ai/users/getAppToken";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MotionVerse")
	FString TokenAPI_ZH_CN="https://motionverseapi.deepscience.cn/users/getAppToken";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MotionVerse")
	FString TextBroadcastMotionAPI_EN_US="https://api.motionverse.ai/v3.0/api/textBroadcastMotion";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MotionVerse")
	FString TextBroadcastMotionAPI_ZH_CN="https://motionverseapi.deepscience.cn/v3.0/api/textBroadcastMotion";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MotionVerse")
	FString VoiceBroadcastMotionAPI_EN_US="https://api.motionverse.ai/v3.1/api/voiceBroadcastMotion";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MotionVerse")
	FString VoiceBroadcastMotionAPI_ZH_CN="https://motionverseapi.deepscience.cn/v3.1/api/voiceBroadcastMotion";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MotionVerse")
	FString AnswerCollectAPI_EN_US="";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MotionVerse")
	FString AnswerCollectAPI_ZH_CN="https://motionverseapi.deepscience.cn/v3.0/api/AnswerCollectMotion";
};

// const TArray<FString> TokenAPIs={
// 	"https://api.motionverse.ai/users/getAppToken",//国外
// 	"https://motionverseapi.deepscience.cn/users/getAppToken",//国内
// };
// const TArray<FString> TextBroadcastMotionAPIs={
// 	"https://api.motionverse.ai/v3.0/api/textBroadcastMotion",//国外
// 	"https://motionverseapi.deepscience.cn/v3.0/api/textBroadcastMotion",//国内
// };
// const TArray<FString> VoiceBroadcastMotionAPIs={
// 	"https://api.motionverse.ai/v3.1/api/voiceBroadcastMotion",//国外
// 	"https://motionverseapi.deepscience.cn/v3.1/api/voiceBroadcastMotion",//国内
// };
// const TArray<FString> AnswerCollectAPIs={
// 	"",//国外
// 	"https://motionverseapi.deepscience.cn/v3.0/api/AnswerCollectMotion"//国内
// };

/**
 *
 */
UCLASS()
class MVUTILSTOOLS_API UMvDM_BpFuncLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	//UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
	//	static void GetAllSkeletalTransform(USkeletalMeshComponent* SkeletalMeshComponent, TArray<FTransform>& outBoneTransforms, TArray<FName>& outBoneNames)
	//{
	//	TArray<FName> BoneNames;
	//	TArray<FTransform> BoneTransforms;
	//	SkeletalMeshComponent->GetBoneNames(BoneNames);
	//	for (FName BoneName : BoneNames)
	//	{
	//		FTransform BoneTransform = SkeletalMeshComponent->GetBoneTransform(SkeletalMeshComponent->GetBoneIndex(BoneName));
	//		// 处理每个骨骼
	//		BoneTransforms.Add(BoneTransform);
	//	}

	//	outBoneTransforms = BoneTransforms;
	//	outBoneNames = BoneNames;
	//}


	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static FString TTS_ParamsToJson(FString text, FString voiceName, FString speed, FString volume, FString pitch, FString gender, int tag);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static TArray<uint8> StringToByteArray(FString str);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static bool TTS_ParseResponseJson(FString jsonStr, FString& audioUrl, FString& bodyUrl, FString& faceUrl);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static FString GetProjectPluginContentDir(FString pluginName);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static FString GetProjectPluginContentDir_MetaHumanDriver();

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static FString CombinePath(FString dir, FString fileName);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void WriteTxt(FString str, FString completePath);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void ParseJsonToBodydata(const FString& jsonStr, FMvBodyData& bodyData);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void ParseJsonToBodydataV2Response(const FString& jsonStr, TArray<FString> SkeletonNoHand, FMvBodyData& outBodyData, float& outTotalTime);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void BeginParseJsonToBodydataV2();

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void EndParseJsonToBodydataV2(FMvBodyData& outBodyData, float& outTotalTime);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void ParseJsonToBodydataV2(const FString& jsonStr, TArray<FString> SkeletonNoHand);



	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void ParseJsonToFacedataV2Response(const FString& jsonStr, FMvFaceData& outBodyData, float& outTotalTime);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void BeginParseJsonToFacedataV2();

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void EndParseJsonToFacedataV2(FMvFaceData& outBodyData, float& outTotalTime);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void ParseJsonToFacedataV2(const FString& jsonStr);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void ParseJsonToFacedata(const FString& jsonStr, FMvFaceData& faceData);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
	static void ParseJsonToFaceControlRigData(const FString& jsonStr, FMvFaceData& faceData);
	
	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void ParseJsonToBodydataRecommend(const FString& jsonStr, UPARAM(ref) FMvBodyData& bodyData, float& totalTime);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void ParseJsonToFacedataRecommend(const FString& jsonStr, UPARAM(ref) FMvFaceData& faceData, float& totalTime);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static FString LoadFileFromPluginContentDir(FString fileRelativePath);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static bool GreaterOrEqual_Cycling(float deltaTime, float cycleTime, float& offsetTime);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static double getWorldTime();

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static FString GetDir(MvDM_PathName pathName, MvDM_PathType pathType);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static bool DirExists(FString dir);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static bool FileExists(FString filePath);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void SplitFilePath(const FString& inFilePath, FString& outDir, FString& outFileName, FString& outExtensionName);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools", meta = (CallableWithoutWorldContext))
		static void SetFps(int fps = 60);//(const UObject* WorldContextObject, int fps);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools", meta = (CallableWithoutWorldContext))
		static void SetMaxPerGroupForStat(int maxNum = 100);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools", meta = (CallableWithoutWorldContext))
		static void ShowOrHideStat(MvDM_StatType type);//(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static bool IsInEditor();

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static int32 GetThreadId();

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void GetCurThreadInfo(int& curThreadId, FString& curThreadName, FString& curThreadInfo);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static bool CurThreadIsInGameThread();

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static bool CurThreadIsInRenderingThread();

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static bool CurThreadIsInRhiThread();

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static FString GetCurSystemDateTime(MvDM_DateTimePurpose purpose);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static FString GetTodayDateInChinaFormat();

	//UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
	static int64 GetCurTimestampInMicroSecond();

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static bool ParseJsonToGetDigest(FString jsonStr, TArray<FString>& outStrs);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void WriteLog(FString msg);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static void WriteTxtFileWithPrefix(FString content, FString filePrefix);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools", meta = (AdvancedDisplay = "0.0-1.0"))
		static void SetUnfocusVolume(float val);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools|Test")
		static void TestUParamRef(UPARAM(ref) FString& str, FString& otherStr);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools|Tmp")
		static FString MakeJsonTmp(const FString& text);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools|Tmp")
	static FString MakeJsonVoiceBroadcastMotion(
		const FString& audio_url,
		const FString& audio_format = "wav",
		int is_cache = 0,
		const FString& face_gender = "male",
		int face_tag = 0,
		int face_type = 1,
		int body_motion = 0,
		int body_filter_window = 15,
		int body_filter_order = 3,
		bool body_fixed = false,
		int body_head_x_rot = 0,
		bool body_compress = false);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools|Tmp")
	static FString MakeJsonTextBroadcastMotion(
		const FString& draft_content,
		const FString& audio_format = "wav",
		const FString& tts_voice_name = "aixia",
		int tts_speed = 50,
		int tts_volume = 50,
		int tts_fm = 50,
		int face_type = 1,
		const FString& face_gender = "male",
		int face_tag = 0,
		int body_motion = 0,
		int body_filter_window = 15,
		int body_filter_order = 3,
		bool body_fixed_hips = false,
		int body_head_x_rot = 0,
		bool body_compress = false);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools|Tmp")
	static FString MakeJsonAnswerCollectMotion(
		const FString& text,
		const FString& audio_format = "wav",
		const FString& tts_voice_name = "aixia",
		int tts_speed = 50, 
		int tts_volume = 50,
		int tts_fm = 50,
		int face_type = 1,
		const FString& face_gender = "male",
		int face_tag = 0,
		int body_motion = 0 ,
		int body_filter_window = 15,
		int body_filter_order = 3,
		bool body_fixed_hips = false,
		int body_head_x_rot = 0,
		bool body_compress = false);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools|Tmp")
		static FString MakeJsonTmpRefText(const FString& refText, int speedRatio, int voice_speed, int voice_volume, int voice_fm, bool fixedHips, int type, int face_type, const FString& voice_name, int body_motion, const FString& gender, const FString& requestId);


	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools|Tmp")
		static FString SwitchUrl(const FString& audio, const FString& text, const FString& answer, int type = 0);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools|Tmp")
		//static bool ParseJsonTmp(FString jsonStr, FString& audioUrl, FString& faceUrl, FString& bodyUrl, FString& text);
		static bool ParseJsonTmp(FString jsonStr, FString inAudioStr, MvJsonDataType type,
			FString& audioUrl, FString& faceUrl, FString& bodyUrl, FString& text);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools|Tmp")
		static FString ParseJsonForm(FString jsonStr);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static bool TickSubtract(UPARAM(ref) float& val, float deltaTime, float threhold);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
		static bool TickAdd(UPARAM(ref) float& val, float deltaTime, float threhold);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools|Tmp")
		static FString Sha1(FString appid, FString secret);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
	static void PrintTraceStack(int Depth = 5);

	UFUNCTION(BlueprintCallable, Category = "MvDM_Functions|UtilsTools")
	static void TickRemainTime( UPARAM(ref) float& remainTime, float deltaTime);
};
