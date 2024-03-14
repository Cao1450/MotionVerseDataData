// Fill out your copyright notice in the Description page of Project Settings.


#include "MyJsonReadWrite.h"

// Sets default values for this component's properties
UMyJsonReadWrite::UMyJsonReadWrite()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyJsonReadWrite::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyJsonReadWrite::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyJsonReadWrite::SaveCurves(const TArray<FName> text)
{
	FString SavePath = FPaths::ProjectConfigDir() + TEXT("CURVES.txt");
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	if (PlatformFile.FileExists(*SavePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("Curve Json File is Exists"));
	}
	else
	{
		FString OutJsonData;
		TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutJsonData);
		Writer->WriteObjectStart();
		Writer->WriteArrayStart(L"Curves");
		for (int i = 0; i < text.Num(); i++)
		{
			Writer->WriteValue((text[i]).ToString());
			UE_LOG(LogTemp, Warning, TEXT("Curve:"), text[i]);
		}
		Writer->WriteArrayEnd();
		Writer->WriteObjectEnd();
		Writer->Close();
		UE_LOG(LogTemp, Warning, TEXT("JsonData:%s"), *OutJsonData);
		FFileHelper::SaveStringToFile(OutJsonData, *SavePath);
	}

	
}

void UMyJsonReadWrite::ReadCurves()
{
	FString SavePath = FPaths::ProjectConfigDir() + TEXT("CURVES.txt");
	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SavePath))
	{

	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("CURVES is not exists"));
	}
}

