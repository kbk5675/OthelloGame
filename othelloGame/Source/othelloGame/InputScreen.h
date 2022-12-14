// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InputScreen.generated.h"


UCLASS()
class OTHELLOGAME_API UInputScreen : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, Category = "UserWidget Class")
		TSubclassOf<UUserWidget> nextWidgetClass;
	UPROPERTY(EditAnywhere, Category = "UserWidget Class")
		TSubclassOf<UUserWidget> backWidgetClass;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UEditableTextBox* ET_timerTime;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UEditableTextBox* ET_boardSize;

	UPROPERTY(meta = (BindWidget))
		class UButton* Btn_start;

	UPROPERTY(meta = (BindWidget))
		class UButton* Btn_back;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* SettingAnimation;

private:
	UFUNCTION()
		void Btn_startOnClicked();

	UFUNCTION()
		void Btn_backOnClicked();

};
