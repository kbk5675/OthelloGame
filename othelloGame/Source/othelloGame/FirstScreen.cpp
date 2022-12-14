// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstScreen.h"
#include "OthelloGameMode.h"
#include <Components/Button.h>
#include <Components/AudioComponent.h>
#include <Sound/SoundCue.h>
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

void UFirstScreen::NativeConstruct()
{
	Super::NativeConstruct();

	BtnStart = Cast<UButton>(GetWidgetFromName(TEXT("BtnStart")));
	BtnQuit	 = Cast<UButton>(GetWidgetFromName(TEXT("BtnQuit")));
	
	if (BtnStart)
	{
		BtnStart->OnClicked.AddDynamic(this, &UFirstScreen::BtnStartOnClicked);
	}

	if (BtnQuit)
	{
		BtnQuit->OnClicked.AddDynamic(this, &UFirstScreen::BtnQuitOnClicked);
	}
	
	PlayAnimation(IntroAnimation, 0.f, 1, EUMGSequencePlayMode::Forward);
}

void UFirstScreen::BtnStartOnClicked()
{
	//LOG
	UE_LOG(LogTemp, Warning, TEXT("Move to Next UI"));

	//FUNCTION
	if (WidgetClass != nullptr)
	{
		AOthelloGameMode* MyMode =
			Cast< AOthelloGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

		MyMode->ChangeMenuWidget(WidgetClass);
	}
}

void UFirstScreen::BtnQuitOnClicked()
{
	//LOG
	UE_LOG(LogTemp, Warning, TEXT("Exit Game"));

	//FUNCTION
	UKismetSystemLibrary::QuitGame(this, 0, EQuitPreference::Quit, false);
}
