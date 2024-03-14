// Fill out your copyright notice in the Description page of Project Settings.


#include "TextContentProvider.h"

// Sets default values for this component's properties
UTextContentProvider::UTextContentProvider()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTextContentProvider::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTextContentProvider::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}




FString UTextContentProvider::GetContent(int32 index)
{
	if (index>= TextConents.Num())
	{
		return TEXT("");
	}
	FString temp = TextConents[index];
	return temp;
}

void UTextContentProvider::LoadContent(FString FilePath)
{
	FString ContentPath = FPaths::ProjectConfigDir() + FilePath;
//	UE_LOG(LogTemp, Display, TEXT("Text Path is :%s"), *ContentPath);
    if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*ContentPath))
	{
		FString tempContent;

		FFileHelper::LoadFileToString(tempContent, *ContentPath);

		UE_LOG(LogTemp, Display, TEXT("Text Content is :%s"),*tempContent)
		tempContent.ParseIntoArray(TextConents, TEXT("|"), false); // ������������ʾ�Ƿ�������ַ���

		//tempContent.Split()

	//	UE_LOG(LogTemp, Display, TEXT("Text Content Length is :%d"), TextConents.Num())

		// ����StringArray�а����˰��ա������ָ����ַ���
		for (const FString& Substring : TextConents)
		{
			// �����ﴦ��ÿ���ָ����������ַ���
			// Substring ��Ϊ�ָ�������ÿ�����ַ���
			//UE_LOG(LogTemp, Display, TEXT("Text Content Item is :%s"), *Substring)
		}
	}
	else
	{
	  UE_LOG(LogTemp,Display,TEXT("Text Content is not exists"))
	}

}

int32 UTextContentProvider::GetContentLength()
{
	return TextConents.Num();
}

void UTextContentProvider::LoadContentNew(FString FilePath)
{
	FString TextPath = FPaths::ProjectConfigDir() + FilePath;
	TextPath = FPaths::ConvertRelativePathToFull(TextPath);
	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*TextPath))
	{
		//TArray<FString> TextData;
		FFileHelper::LoadFileToStringArray(TextConents, *TextPath);
		int32 line = 0;
		for (FString lineContent : TextConents)
		{
			//UE_LOG(LogTemp, Warning, TEXT("[line %d] %s"), ++line, *lineContent);
		}
	}
}

