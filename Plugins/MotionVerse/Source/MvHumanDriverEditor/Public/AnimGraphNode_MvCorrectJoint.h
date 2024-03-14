// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_Base.h"
#include "AnimNode_MvCorrectJoint.h"
#include "AnimGraphNode_MvCorrectJoint.generated.h"

/**
 * C:\Program Files\Epic Games\UE_5.0\Engine\Source\Editor\AnimGraph\Public\AnimGraphNode_ModifyBone.h
 */
UCLASS()
class MVHUMANDRIVEREDITOR_API UAnimGraphNode_MvCorrectJoint : public UAnimGraphNode_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category=Settings)
	FAnimNode_MvCorrectJoint Node;

	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual FLinearColor GetNodeTitleColor() const override;
	//virtual FString GetDocumentationLink() const override;
	virtual FString GetNodeCategory() const override;
};
