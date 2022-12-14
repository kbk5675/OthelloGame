// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FirstScreen.generated.h"


UCLASS()
class OTHELLOGAME_API UFirstScreen : public UUserWidget
{
	GENERATED_BODY()

protected:
	void NativeConstruct() override;

	UPROPERTY(EditAnywhere, Category = "UserWidget Class")
		TSubclassOf<UUserWidget> WidgetClass;
		
	UPROPERTY(meta = (BindWidget))
		class UButton* BtnStart;

	UPROPERTY(meta = (BindWidget))
		class UButton* BtnQuit;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* IntroAnimation;

private:
	UFUNCTION()
		void BtnStartOnClicked();

	UFUNCTION()
		void BtnQuitOnClicked();

	
};
