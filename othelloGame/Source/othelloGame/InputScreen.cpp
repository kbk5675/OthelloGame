// Fill out your copyright notice in the Description page of Project Settings.

#include "InputScreen.h"
#include "OthelloGameMode.h"
#include <Components/Button.h>
#include <Components/EditableTextBox.h>
#include "Kismet/GameplayStatics.h"

void UInputScreen::NativeConstruct()
{
	Super::NativeConstruct();

	if (Btn_start)
	{
		Btn_start->OnClicked.AddDynamic(this, &UInputScreen::Btn_startOnClicked);
		Btn_start->SetIsEnabled(false);
	}

	if (Btn_back)
	{
		Btn_back->OnClicked.AddDynamic(this, &UInputScreen::Btn_backOnClicked);
	}

	PlayAnimation(SettingAnimation, 0.f, 1, EUMGSequencePlayMode::Forward);
}

void UInputScreen::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	
	FString countdownTime = ET_timerTime->GetText().ToString();
	FString boardSize = ET_boardSize->GetText().ToString();
	int32 size = FCString::Atoi(*boardSize);
	int32 time = FCString::Atoi(*countdownTime);

	if (ET_timerTime->GetText().ToString().Len() > 0 && ET_timerTime->GetText().IsNumeric()
		&& ET_boardSize->GetText().ToString().Len() > 0 && ET_boardSize->GetText().IsNumeric()
		&& size >= 4 && size <= 9 && time >= 5 && time <= 60)
	{
		Btn_start->SetIsEnabled(true);
	}
	else
	{
		Btn_start->SetIsEnabled(false);
	}
}

void UInputScreen::Btn_startOnClicked()
{
	//LOG
	UE_LOG(LogTemp, Warning, TEXT("start Game"));

	//FUNCTION

	AOthelloGameMode* MyGameMode =
		Cast<AOthelloGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	FString boardSize = ET_boardSize->GetText().ToString();
	FString countdownTime = ET_timerTime->GetText().ToString();

	MyGameMode->SetBoardSize(FCString::Atoi(*boardSize));
	MyGameMode->SetCountdownTime(FCString::Atof(*countdownTime));

	if (nextWidgetClass != nullptr)
	{
		AOthelloGameMode* MyMode =
			Cast< AOthelloGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

		MyMode->ChangeMenuWidget(nextWidgetClass);
	}
}

void UInputScreen::Btn_backOnClicked()
{
	if (backWidgetClass != nullptr)
	{
		AOthelloGameMode* MyMode =
			Cast< AOthelloGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

		MyMode->ChangeMenuWidget(backWidgetClass);
	}
}