// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TextContentProvider.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOTIONVERSEDATADATA_API UTextContentProvider : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTextContentProvider();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TArray<FString> TextConents;

public:
	UFUNCTION(BlueprintCallable)
	FString GetContent(int32 index);
	UFUNCTION(BlueprintCallable)
	void LoadContent(FString FilePath);
	UFUNCTION(BlueprintCallable)
	int32 GetContentLength();
	UFUNCTION(BlueprintCallable)
	void LoadContentNew(FString FilePath);

};
