// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyJsonReadWrite.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MOTIONVERSEDATADATA_API UMyJsonReadWrite : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMyJsonReadWrite();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:
	UFUNCTION(BlueprintCallable)
	void SaveCurves(const TArray<FName> text);
	UFUNCTION(BlueprintCallable)
	void ReadCurves();
public:
	TArray<FMyArray> faceBs;
};

USTRUCT(BlueprintType)
struct FMyArray
{
	GENERATED_USTRUCT_BODY()
public:
	FString FaceCurveName;
	TArray<float> myArray;
};