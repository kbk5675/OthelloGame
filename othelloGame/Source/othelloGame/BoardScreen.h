// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BoardScreen.generated.h"

struct Pos
{
	int32 Y;
	int32 X;
};

UCLASS()
class OTHELLOGAME_API UBoardScreen : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;


	UPROPERTY(EditAnywhere, Category = "UserWidget Class")
		TSubclassOf<UUserWidget> RestartWidgetClass;

	UPROPERTY(EditAnywhere, Category = "UserWidget Class")
		TSubclassOf<UUserWidget> QuitWidgetClass;

	UPROPERTY(meta = (BindWidget))
		class UUniformGridPanel* boardPanel;

#pragma region UPROPERTY UObjects

	UPROPERTY(EditAnywhere)
		class UObject* Image_Black;
	UPROPERTY(EditAnywhere)
		class UObject* Image_White;
	UPROPERTY(EditAnywhere)
		class UObject* Image_DotCircle;
	UPROPERTY()
		class UObject* AI_Face;
	UPROPERTY()
		class UObject* BlackShapeImage;

#pragma endregion

#pragma region UPROPERTY UImages

	UPROPERTY(meta = (BindWidget))
		class UImage* Image_BShape;

	UPROPERTY(meta = (BindWidget))
		class UImage* Image_NumTens;

	UPROPERTY(meta = (BindWidget))
		class UImage* Image_NumUnits;

	UPROPERTY(meta = (BindWidget))
		class UImage* Image_WhiteCntTens;

	UPROPERTY(meta = (BindWidget))
		class UImage* Image_WhiteCntUnits;

	UPROPERTY(meta = (BindWidget))
		class UImage* Image_BlackCntTens;

	UPROPERTY(meta = (BindWidget))
		class UImage* Image_BlackCntUnits;

#pragma endregion

#pragma region UPROPERTY UTextBlock, UButton

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* Title_GameOver;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* Title_TimeOver;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextBlock_Winner;

	UPROPERTY(meta = (BindWidget))
		class UButton* Btn_Restart;

	UPROPERTY(meta = (BindWidget))
		class UButton* Btn_Quit;

	UPROPERTY(meta = (BindWidget))
		class UButton* Btn_Exit;

#pragma endregion

#pragma region UPROPERTY Animations

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* StartAnimation;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* GameOverAnimation;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* TimeOverAnimation;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* ScoreUnitsNumberAnimation;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* TimerUnitsNumberAnimation;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* TimerTensNumberAnimation;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* WhiteScoreTensNumberAnimation;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* BlackScoreTensNumberAnimation;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* WhiteTurnAnimation;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* BlackTurnAnimation;

#pragma endregion

private:
	//Timer Functions
	UFUNCTION()
		void UpdateTimerDisplay();
	UFUNCTION()
		void StartGameTimer();
	UFUNCTION()
		void AI_Timer();
	UFUNCTION()
		void Pass_Timer();

	// Button Functions
	UFUNCTION()
		void BtnOnClicked();
	UFUNCTION()
		void Btn_Restart_OnClicked();
	UFUNCTION()
		void Btn_Quit_OnClicked();
	UFUNCTION()
		void Btn_Exit_OnClicked();

	void BoardInit();
	
	// Player Logic
	void ButtonReverseSetting(int32 y, int32 x);
	void ReverseBoard();
	void ChangeBoardImage();
	void ButtonEnableSetting();
	void ChangeBlockToDotCircle();
	void CountingAllStones();
	void ChangeCountingImage();
	void GameOver();

	// AI Logic
	void AI_Turn();
	Pos GetAISelectedPos();
	void AI_Behavior();

	bool IsGameOver();
	
	void SearchReversePos_UpperLeft(int32 y, int32 x);
	void SearchReversePos_UpperRight(int32 y, int32 x);
	void SearchReversePos_LowerLeft(int32 y, int32 x);
	void SearchReversePos_LowerRight(int32 y, int32 x);
	void SearchReversePos_Left(int32 y, int32 x);
	void SearchReversePos_Right(int32 y, int32 x);
	void SearchReversePos_Up(int32 y, int32 x);
	void SearchReversePos_Down(int32 y, int32 x);
	
	void SearchIsEnable_LowerLeft(int32 y, int32 x);
	void SearchIsEnable_LowerRight(int32 y, int32 x);
	void SearchIsEnable_UpperLeft(int32 y, int32 x);
	void SearchIsEnable_UpperRight(int32 y, int32 x);
	void SearchIsEnable_Up(int32 y, int32 x);
	void SearchIsEnable_Down(int32 y, int32 x);
	void SearchIsEnable_Left(int32 y, int32 x);
	void SearchIsEnable_Right(int32 y, int32 x);

private:
	class AOthelloGameMode* MyGameMode;

	int32 _board[100][100];
	int32 boardSize;
	int32 boardMid;
	int32 turn = 1;
	int32 cnt_Black = 0;
	int32 cnt_White = 0;

	bool bIsBlackPassToWhite;
	bool bIsWhitePassToBlack;
	bool bIsAlreadyPlay;
	bool bIsAlreadyGameOver;

	float countdownTime = 0.f;
	float AITurnTime= 1.f;
	float startGameTime = 2.f;
	float passTime = 2.f;

	Pos playerClickedPos;

	TArray<TArray<class UButton*>> Board_Buttons;
	TArray<TArray<class UImage*>> Button_Images;

	TArray<Pos> pos_needToChangeWhite;
	TArray<Pos> pos_needToChangeBlack;
	TArray<Pos> pos_needToChangeDotCircle;
	TArray<Pos> pos_DotCircle;

	TArray<UObject*> Textures_Timer;
	TArray<UObject*> Textures_BloackCnts;

	FTimerHandle countdownTimerHandle;
	FTimerHandle AITurnTimerHandle;
	FTimerHandle StartGameTimerHandle;
	FTimerHandle PassTimerHandle;
};