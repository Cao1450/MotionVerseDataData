// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MotionVerseToolsWithMF.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOTIONVERSEDATADATA_API UMotionVerseToolsWithMF : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMotionVerseToolsWithMF();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:
	UFUNCTION(BlueprintCallable)
	bool TimeSpace(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void SetRotation(FString BoneName,FRotator Rotation);

	UFUNCTION(BlueprintCallable)
	FRotator GetRotation(FString BoneName, int Index);

	UFUNCTION(BlueprintCallable)
	void SetPosition(FVector pos);

	UFUNCTION(BlueprintCallable)
	FVector GetPosition(int Index);

	UFUNCTION(BlueprintCallable)
	void SaveJson(FString FileName);

	UFUNCTION(BlueprintCallable)
	void LoadJson(FString FileName);

	UFUNCTION(BlueprintCallable)
	int32 GetOddNumberInRange();

	UFUNCTION(BlueprintCallable)
	FString GetTone();

	UFUNCTION(BlueprintCallable)
	int32 GetDataLength();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
	int32 MotionIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
	float TargetFrame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
	float GDeltaTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
	FString Gtextlabel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
	FString GSpeakerStyle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
	FString GAudioUrl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
	FString GTextContent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
	FString GFileName;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
	int32  GFace_tag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
	int32  GBody_motion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
	int32 GBody_filter_window;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
	int32 GContent_Index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
	int32 GTotal_Index;

private:
	TMap<FString, TArray<FRotator>> MotionData;
	TArray<FVector> Hips;
	TArray<FString> Eomtion;
	FString FinalName;
};