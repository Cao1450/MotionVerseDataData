// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_Base.h"
#include "AnimNode_MvPrintJoint.h"
#include "AnimGraphNode_MvPrintJoint.generated.h"

/**
 * 
 */
UCLASS()
class MVHUMANDRIVEREDITOR_API UAnimGraphNode_MvPrintJoint : public UAnimGraphNode_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category=Settings)
	FAnimNode_MvPrintJoint Node;

	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual FLinearColor GetNodeTitleColor() const override;
	//virtual FString GetDocumentationLink() const override;
	virtual FString GetNodeCategory() const override;
};
