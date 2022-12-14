// Fill out your copyright notice in the Description page of Project Settings.


#include "OthelloGameMode.h"
#include "Blueprint/UserWidget.h"

AOthelloGameMode::AOthelloGameMode()
{

}

void AOthelloGameMode::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(WidgetClass);
}

void AOthelloGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}
	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}