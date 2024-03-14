// Fill out your copyright notice in the Description page of Project Settings.


#include "MotionVerseToolsWithMF.h"
#include <Kismet/KismetSystemLibrary.h>

// Sets default values for this component's properties
UMotionVerseToolsWithMF::UMotionVerseToolsWithMF()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMotionVerseToolsWithMF::BeginPlay()
{
	Super::BeginPlay();
	Gtextlabel = TEXT("");
	GSpeakerStyle = TEXT("");
	GFace_tag = 2;
	GBody_motion = 0;
	GBody_filter_window = 15;
	// ...
	Eomtion.Add(TEXT("shasha-neutral-plus"));
	Eomtion.Add(TEXT("shasha-happy-plus"));
	Eomtion.Add(TEXT("shasha-angry-plus"));
	Eomtion.Add(TEXT("shasha-disgust-plus"));
	Eomtion.Add(TEXT("shasha-fear-plus"));
	Eomtion.Add(TEXT("shasha-sad-plus"));
	Eomtion.Add(TEXT("shasha-surprise-plus"));
}


// Called every frame
void UMotionVerseToolsWithMF::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UMotionVerseToolsWithMF::TimeSpace(float DeltaTime)
{

	GDeltaTime += DeltaTime;
	//GTotalTime += DeltaTime;

	if (GDeltaTime >= TargetFrame)
	{
		MotionIndex++;
		GDeltaTime -= TargetFrame;
		GDeltaTime = 0;
		return true;
	}
	return false;
}

void UMotionVerseToolsWithMF::SetRotation(FString BoneName, FRotator Rotation)
{
	if (MotionData.Contains(BoneName))
	{
		/*Rotation.Pitch;
		Rotation.Roll;
		Rotation.Yaw;*/
		MotionData[BoneName].Add(Rotation);
	}
	else
	{
		TArray<FRotator> NewRotatorArray;
		NewRotatorArray.Add(Rotation);
		MotionData.Add(BoneName, NewRotatorArray);
	}
}
FRotator UMotionVerseToolsWithMF::GetRotation(FString BoneName, int Index)
{
	if (MotionData.Contains(BoneName))
	{
		if (Index < MotionData[BoneName].Num() - 1)
		{
			return	MotionData[BoneName][Index];
		}
		else
		{
			return	MotionData[BoneName][MotionData[BoneName].Num() - 1];
		}
	}
	return FRotator();
}

void UMotionVerseToolsWithMF::SetPosition(FVector pos)
{
	Hips.Add(pos);
}

FVector UMotionVerseToolsWithMF::GetPosition(int Index)
{
	if (Hips.Num() > 0)
	{
		if (Index < Hips.Num() - 1)
		{
			return Hips[Index];
		}
		else
		{

			return Hips[Hips.Num() - 1];

		}
	}
	return FVector();
}

void UMotionVerseToolsWithMF::SaveJson(FString FileName)
{
	FString OutJsonData;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutJsonData);
	//pelvis
	//{
	float tempTotalTime = MotionData[TEXT("pelvis")].Num() / 30.0f;
	Writer->WriteObjectStart();
	//Writer->WriteValue(L"xxxxx", TEXT("白月魁"));
	Writer->WriteValue(L"Text", Gtextlabel);
	Writer->WriteValue(L"TotalTime", tempTotalTime);
	Writer->WriteValue(L"SpeakerStyle", GSpeakerStyle);
	Writer->WriteValue(L"AudioUrl", TEXT(""));
	Writer->WriteValue(L"Face_tag", GFace_tag);
	Writer->WriteValue(L"Body_motion", GBody_motion);
	Writer->WriteValue(L"Body_filter_window", GBody_filter_window);
	//Rotators:[]
	Writer->WriteArrayStart(L"Rotators");
	for (const auto& Elem : MotionData)
	{
		//Rotators:{}
		Writer->WriteObjectStart();
		Writer->WriteValue(L"BoneName", Elem.Key);
		Writer->WriteArrayStart("Rots");
		for (int i = 0; i < Elem.Value.Num(); i++)
		{
			Writer->WriteObjectStart();
			Writer->WriteValue(L"P", Elem.Value[i].Pitch);
			Writer->WriteValue(L"R", Elem.Value[i].Roll);
			Writer->WriteValue(L"Y", Elem.Value[i].Yaw);
			Writer->WriteObjectEnd();
		}
		Writer->WriteArrayEnd();
		Writer->WriteObjectEnd();
	}
	Writer->WriteArrayEnd();
	Writer->WriteArrayStart(L"Hips");

	for (const auto& pos : Hips)
	{
		Writer->WriteObjectStart();
		Writer->WriteValue(L"X", pos.X);
		Writer->WriteValue(L"Y", pos.Y);
		Writer->WriteValue(L"Z", pos.Z);
		Writer->WriteObjectEnd();
	}

	Writer->WriteArrayEnd();

	Writer->WriteObjectEnd();

	Writer->Close();
	/*UE_LOG(LogTemp, Warning, TEXT("Cout001:%d"), MotionData.Num());
	UE_LOG(LogTemp, Warning, TEXT("Cout001:%d"), MotionData[TEXT("hand_r")].Num());*/
	//UE_LOG(LogTemp, Warning, TEXT("JsonData:%s"), *OutJsonData);
	FString motionIndex = FString::FromInt(GBody_motion);
	FString SavePath = FPaths::ProjectConfigDir() + FString::FromInt(GContent_Index) + TEXT("_") + motionIndex + TEXT("_") + Gtextlabel + TEXT(".txt");
	//UE_LOG(LogTemp, Warning, TEXT("Path:%s"), *SavePath);
	FFileHelper::SaveStringToFile(OutJsonData, *SavePath, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);
	MotionData.Empty();
	Hips.Empty();
	GTotal_Index++;
}

void UMotionVerseToolsWithMF::LoadJson(FString FileName)
{
	if (GFileName != FileName)
	{
		MotionData.Empty();
		Hips.Empty();
		GFileName = FileName;
		FString JsonPath = FPaths::ProjectConfigDir() + FileName;
		JsonPath = FPaths::ConvertRelativePathToFull(JsonPath);
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*JsonPath))
		{
			//UKismetSystemLibrary::PrintString(GetWorld(), *JsonPath);
			FString JsonData;
			FFileHelper::LoadFileToString(JsonData, *JsonPath);

			// FString 转 JsonObj
			TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonData);
			TSharedPtr<FJsonObject> RootJsonObj = MakeShareable(new FJsonObject);
			if (FJsonSerializer::Deserialize(JsonReader, RootJsonObj))
			{
				//UE_LOG(LogTemp, Warning, TEXT("JsonData:%s"), *JsonData);

				GAudioUrl = RootJsonObj->GetStringField(TEXT("AudioUrl"));
				GTextContent = RootJsonObj->GetStringField(TEXT("Text"));
				const TArray< TSharedPtr<FJsonValue> >* rotators;
				if (RootJsonObj->TryGetArrayField(TEXT("Rotators"), rotators))
				{
					for (TSharedPtr<FJsonValue> item : *rotators)
					{
						TSharedPtr<FJsonObject>itemObjet = item->AsObject();
						TArray<FRotator> rotss;
						FString BoneName = itemObjet->GetStringField("BoneName");
						const TArray< TSharedPtr<FJsonValue> >* bonesRot;
						if (itemObjet->TryGetArrayField(TEXT("Rots"), bonesRot))
						{
							for (TSharedPtr<FJsonValue> itemRot : *bonesRot)
							{
								TSharedPtr<FJsonObject>itemRotss = itemRot->AsObject();
								FRotator tempRotsss = FRotator(itemRotss->GetNumberField("P"), itemRotss->GetNumberField("Y"), itemRotss->GetNumberField("R"));
								rotss.Add(tempRotsss);
							}
						}
						MotionData.Add(BoneName, rotss);
					}
				}
				const TArray< TSharedPtr<FJsonValue> >* positionxx;
				if (RootJsonObj->TryGetArrayField(TEXT("Hips"), positionxx))
				{
					for (TSharedPtr<FJsonValue> itemPos : *positionxx)
					{
						TSharedPtr<FJsonObject>itemPoss = itemPos->AsObject();
						Hips.Add(FVector(itemPoss->GetNumberField("X"), itemPoss->GetNumberField("Y"), itemPoss->GetNumberField("Z")));
					}
				}
			}
			else
				UKismetSystemLibrary::PrintString(GetWorld(), TEXT("FJsonSerializer::Deserialize Failed!"));

		}
	}

	//UE_LOG(LogTemp, Display, TEXT("JsonData Hips Count:%d"), Hips.Num());
	//UE_LOG(LogTemp, Display, TEXT("JsonData URL:%s"), *GAudioUrl);
	//UE_LOG(LogTemp, Display, TEXT("JsonData Content:%s"), *GContent);
		/*for (const auto& Elem : MotionData)
	{
		UE_LOG(LogTemp, Display, TEXT("Cout bone:%s"), *Elem.Key);

		for (const auto& Elemtemp : Elem.Value)
		{
			UE_LOG(LogTemp, Display, TEXT("bone bone:%s"), *Elemtemp.ToString());
		}
	}*/
		MotionIndex = 0;
}

int32 UMotionVerseToolsWithMF::GetOddNumberInRange()
{
	// 使用FMath::RandRange生成3到31之间的随机整数
	int32 randomNumber = FMath::RandRange(3, 31);

	// 确保返回值为奇数
	if (randomNumber % 2 == 0)
	{
		// 如果为偶数，加1使其成为奇数
		randomNumber += 1;
	}

	return randomNumber;
}

FString UMotionVerseToolsWithMF::GetTone()
{
	int32 randomNumber = FMath::RandRange(0, 5);
	GSpeakerStyle = TEXT("shasha-neutral-plus");
	return GSpeakerStyle;
}

int32 UMotionVerseToolsWithMF::GetDataLength()
{
	return Hips.Num();
}
