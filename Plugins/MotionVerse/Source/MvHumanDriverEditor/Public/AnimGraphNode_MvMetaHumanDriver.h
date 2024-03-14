// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AnimNode_MvMetaHumanDriver.h"
#include "CoreMinimal.h"
#include "AnimGraphNode_Base.h"

#include "AnimGraphNode_MvMetaHumanDriver.generated.h"

/**
 * 
 */
UCLASS()
class MVHUMANDRIVEREDITOR_API UAnimGraphNode_MvMetaHumanDriver : public UAnimGraphNode_Base
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Settings)
	FAnimNode_MvMetaHumanDriver m_node;

	//UPROPERTY(EditAnywhere, Category = Settings)
	//FLinearColor m_color;



public:
	
	virtual FLinearColor GetNodeTitleColor() const override;	
	
	//https://blog.csdn.net/u012863565/article/details/122109409
	// UEdGraphNode interface
	virtual FText GetTooltipText() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	// End of UEdGraphNode interface

	// UAnimGraphNode_Base interface
	virtual FString GetNodeCategory() const override;

	// virtual void CreateOutputPins() override;
};

