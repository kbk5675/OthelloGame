// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OthelloGameMode.generated.h"

UCLASS()
class OTHELLOGAME_API AOthelloGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AOthelloGameMode();

protected:
	UPROPERTY(EditAnywhere, Category = "UserWidget Class")
		TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY()
		UUserWidget* CurrentWidget;

public:
	virtual void BeginPlay() override;

	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);
	
	int64 GetBoardSize()		{ return _boardSize; }
	float GetCountdownTime()	{ return _countdownTime; }
	
	void SetBoardSize(int64 val)		{ _boardSize = val; }
	void SetCountdownTime(float val)	{ _countdownTime = val; }

private:
	int64 _boardSize = 0;
	float _countdownTime = 60.f;
};
