#include "BoardScreen.h"
#include "OthelloGameMode.h"
#include <Components/Button.h>
#include <Components/Image.h>
#include <Engine/Texture2D.h>
#include <Components/TextBlock.h>
#include <Components/UniformGridPanel.h>
#include <Components/UniformGridSlot.h>
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetTree.h"
#include "TimerManager.h"

void UBoardScreen::NativeConstruct()
{
	Super::NativeConstruct();
	#pragma region Load Texture

	UObject* ClickSound = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Effect_Sounds/Cues/Click_06_Cue")));

	UObject* Texture_BlackShpae = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/BlackImage")));
	UObject* Texture_AI_Face = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/face")));

	UObject* Texture_Timer0 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/numbers_Sprite_0")));
	UObject* Texture_Timer1 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/numbers_Sprite_1")));
	UObject* Texture_Timer2 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/numbers_Sprite_2")));
	UObject* Texture_Timer3 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/numbers_Sprite_3")));
	UObject* Texture_Timer4 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/numbers_Sprite_4")));
	UObject* Texture_Timer5 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/numbers_Sprite_5")));
	UObject* Texture_Timer6 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/numbers_Sprite_6")));
	UObject* Texture_Timer7 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/numbers_Sprite_7")));
	UObject* Texture_Timer8 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/numbers_Sprite_8")));
	UObject* Texture_Timer9 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/numbers_Sprite_9")));

	UObject* Texture_BlockCnt0 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/Count_numbers_0")));
	UObject* Texture_BlockCnt1 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/Count_numbers_1")));
	UObject* Texture_BlockCnt2 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/Count_numbers_2")));
	UObject* Texture_BlockCnt3 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/Count_numbers_3")));
	UObject* Texture_BlockCnt4 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/Count_numbers_4")));
	UObject* Texture_BlockCnt5 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/Count_numbers_5")));
	UObject* Texture_BlockCnt6 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/Count_numbers_6")));
	UObject* Texture_BlockCnt7 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/Count_numbers_7")));
	UObject* Texture_BlockCnt8 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/Count_numbers_8")));
	UObject* Texture_BlockCnt9 = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Texture/Count_numbers_9")));

	if (Texture_Timer0 && Texture_Timer1 && Texture_Timer2 && Texture_Timer3 && Texture_Timer4
		&& Texture_Timer5 && Texture_Timer6 && Texture_Timer7 && Texture_Timer8 && Texture_Timer9
		&& Texture_BlockCnt0 && Texture_BlockCnt1 && Texture_BlockCnt2 && Texture_BlockCnt3 && Texture_BlockCnt4
		&& Texture_BlockCnt5 && Texture_BlockCnt6 && Texture_BlockCnt7 && Texture_BlockCnt8 && Texture_BlockCnt9)
	{
		Textures_Timer.Add(Texture_Timer0);
		Textures_Timer.Add(Texture_Timer1);
		Textures_Timer.Add(Texture_Timer2);
		Textures_Timer.Add(Texture_Timer3);
		Textures_Timer.Add(Texture_Timer4);
		Textures_Timer.Add(Texture_Timer5);
		Textures_Timer.Add(Texture_Timer6);
		Textures_Timer.Add(Texture_Timer7);
		Textures_Timer.Add(Texture_Timer8);
		Textures_Timer.Add(Texture_Timer9);

		Textures_BloackCnts.Add(Texture_BlockCnt0);
		Textures_BloackCnts.Add(Texture_BlockCnt1);
		Textures_BloackCnts.Add(Texture_BlockCnt2);
		Textures_BloackCnts.Add(Texture_BlockCnt3);
		Textures_BloackCnts.Add(Texture_BlockCnt4);
		Textures_BloackCnts.Add(Texture_BlockCnt5);
		Textures_BloackCnts.Add(Texture_BlockCnt6);
		Textures_BloackCnts.Add(Texture_BlockCnt7);
		Textures_BloackCnts.Add(Texture_BlockCnt8);
		Textures_BloackCnts.Add(Texture_BlockCnt9);
	}

	if (Texture_BlackShpae && Texture_AI_Face)
	{
		BlackShapeImage = Texture_BlackShpae;
		Image_BShape->Brush.SetResourceObject(BlackShapeImage);
		AI_Face = Texture_AI_Face;
	}

	#pragma endregion

	// Set Timer Image
	Image_NumUnits->Brush.SetResourceObject(Textures_Timer[0]);
	Image_NumTens->Brush.SetResourceObject(Textures_Timer[0]);
	
	// Button Action
	Btn_Restart->OnClicked.AddDynamic(this, &UBoardScreen::Btn_Restart_OnClicked);
	Btn_Quit->OnClicked.AddDynamic(this, &UBoardScreen::Btn_Quit_OnClicked);
	Btn_Exit->OnClicked.AddDynamic(this, &UBoardScreen::Btn_Exit_OnClicked);
	
	// Bring Input Data
	MyGameMode = Cast<AOthelloGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	boardSize = MyGameMode->GetBoardSize();
	boardMid = boardSize / 2 - 1;
	countdownTime = MyGameMode->GetCountdownTime();

	// Timer setting.
	GetWorld()->GetTimerManager().SetTimer(countdownTimerHandle, this, &UBoardScreen::UpdateTimerDisplay, 1.f, true);
	// AI Start Time.
	GetWorld()->GetTimerManager().SetTimer(StartGameTimerHandle, this, &UBoardScreen::StartGameTimer, 1.f, true);
	// AI Turn Timer setting.
	GetWorld()->GetTimerManager().SetTimer(AITurnTimerHandle, this, &UBoardScreen::AI_Timer, 1.f, true);
	GetWorld()->GetTimerManager().PauseTimer(AITurnTimerHandle);

	GetWorld()->GetTimerManager().SetTimer(PassTimerHandle, this, &UBoardScreen::Pass_Timer, 1.f, true);
	GetWorld()->GetTimerManager().PauseTimer(PassTimerHandle);
	// Create Board.
	for (int32 i = 0; i < boardSize; i++)
	{
		TArray<class UButton*> XAixsArrayButton;
		TArray<class UImage*> XAixsArrayImage;
		for (int32 j = 0; j < boardSize; j++)
		{
			// Create Button.
			auto BoardButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
			// Create Button Image.
			auto Image = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
			Image->Brush.SetImageSize({ 100,100 });
			Image->SetVisibility(ESlateVisibility::Hidden);

			BoardButton->AddChild(Image);
			BoardButton->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
			BoardButton->OnPressed.AddDynamic(this, &UBoardScreen::BtnOnClicked);
			BoardButton->SetBackgroundColor(FColor::Green);

			// Create ButtonSlot And Bind With Button.
			UUniformGridSlot* boardBtnSlot = Cast<UUniformGridSlot>(boardPanel->AddChildToUniformGrid(BoardButton, i, j));
			boardBtnSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
			boardBtnSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);

			// Add XAixsArray.
			XAixsArrayButton.Add(BoardButton);
			XAixsArrayImage.Add(Image);
		}
		
		// Add TArray.
		Board_Buttons.Add(XAixsArrayButton);
		Button_Images.Add(XAixsArrayImage);
	}

	BoardInit();

	// AI Turn Start.
	ButtonEnableSetting();

	// Log
	UE_LOG(LogTemp, Warning, TEXT("Board Size : %d  Time : %d   Turn : %d"), boardSize, countdownTime, turn);
	
	#pragma region Animation Start

	PlayAnimation(StartAnimation, 0.f, 1, EUMGSequencePlayMode::Forward);

	if (turn == 1)	// Black
	{
		PlayAnimation(BlackTurnAnimation, 0.f, 1);
	}
	else	// White
	{
		PlayAnimation(WhiteTurnAnimation, 0.f, 1);
	}

	#pragma endregion
}

void UBoardScreen::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
}

// Board Initial Setting Function
void UBoardScreen::BoardInit()
{
	for (int32 i = 0; i < boardSize; i++)
	{
		for (int32 j = 0; j < boardSize; j++)
		{
			_board[i][j] = 0;
		}
	}

	// Board Middle Setting
	_board[boardMid][boardMid] = 1;
	_board[boardMid + 1][boardMid + 1] = 1;
	_board[boardMid][boardMid + 1] = 2;
	_board[boardMid + 1][boardMid] = 2;

	for (int32 i = 0; i < boardSize; i++)
	{
		for (int32 j = 0; j < boardSize; j++)
		{
			if (_board[i][j] == 2)
			{
				Button_Images[i][j]->Brush.SetResourceObject(Image_White);
			}
			if (_board[i][j] == 1)
			{
				Button_Images[i][j]->Brush.SetResourceObject(Image_Black);
			}
		}
	}

	cnt_Black = 0;
	cnt_White = 0;
	turn = 1;

	pos_needToChangeWhite.Empty();
	pos_needToChangeBlack.Empty();
	pos_needToChangeDotCircle.Empty();

	CountingAllStones();
}

// Player action of click to board Function
void UBoardScreen::BtnOnClicked()
{
	for (int32 i = 0; i < boardSize; i++)
	{
		for (int32 j = 0; j < boardSize; j++)
		{
			if (Board_Buttons[i][j]->IsPressed())
			{
				if (_board[i][j] == 1 || _board[i][j] == 2)
				{
					return;
				}

				playerClickedPos.Y = i;	
				playerClickedPos.X = j;

				// White
				if (turn == 2)
				{
					pos_needToChangeWhite.Add(playerClickedPos);
					ButtonReverseSetting(playerClickedPos.Y, playerClickedPos.X);
					ReverseBoard();
					ChangeBoardImage();
				
					if (!IsGameOver())
					{
						turn = 1;
						ButtonEnableSetting();
						AI_Turn();
					}
					else
					{
						GameOver();
					}
				}
			}
		}
	}
	pos_needToChangeDotCircle.Empty();
	countdownTime = MyGameMode->GetCountdownTime();
}

// Search for can Change _board[y][x] data to 1 or 2
void UBoardScreen::ButtonReverseSetting(int32 y, int32 x)
{
	SearchReversePos_UpperLeft(y, x);
	SearchReversePos_UpperRight(y, x);
	SearchReversePos_LowerLeft(y, x);
	SearchReversePos_LowerRight(y, x);
	SearchReversePos_Left(y, x);
	SearchReversePos_Right(y, x);
	SearchReversePos_Up(y, x);
	SearchReversePos_Down(y, x);
}
#pragma region Search Can Reverse Button Position

void UBoardScreen::SearchReversePos_LowerLeft(int32 y, int32 x)
{
	if (y < boardSize - 1 && x > 0 && _board[y + 1][x - 1] == 0)
	{
		return;
	}

	Pos tempPos;
	tempPos.Y = y;
	tempPos.X = x;

	TArray<Pos> tempTArray;

	while (tempPos.Y < boardSize - 1 && tempPos.X > 0 && _board[tempPos.Y + 1][tempPos.X - 1] != turn)
	{
		tempPos.Y++;
		tempPos.X--;

		if (_board[tempPos.Y][tempPos.X] == 0)
		{
			return;
		}

		// Black
		if (turn == 1)
		{
			tempTArray.Add(tempPos);
		}
		// White
		else
		{
			tempTArray.Add(tempPos);
		}
	}

	if (tempPos.Y < boardSize - 1 && tempPos.X > 0)
	{
		if (_board[tempPos.Y + 1][tempPos.X - 1] == turn)
		{
			// Black
			if (turn == 1)
			{
				pos_needToChangeBlack.Append(tempTArray);
			}
			// White
			else
			{
				pos_needToChangeWhite.Append(tempTArray);
			}
		}
	}
}
void UBoardScreen::SearchReversePos_LowerRight(int32 y, int32 x)
{
	if (y < boardSize - 1 && x < boardSize - 1 && _board[y + 1][x + 1] == 0)
	{
		return;
	}

	Pos tempPos;
	tempPos.Y = y;
	tempPos.X = x;

	TArray<Pos> tempTArray;

	while (tempPos.Y < boardSize - 1 && tempPos.X < boardSize - 1 && _board[tempPos.Y + 1][tempPos.X + 1] != turn)
	{
		tempPos.Y++;
		tempPos.X++;

		if (_board[tempPos.Y][tempPos.X] == 0)
		{
			return;
		}

		// Black
		if (turn == 1)
		{
			tempTArray.Add(tempPos);
		}
		// White
		else
		{
			tempTArray.Add(tempPos);
		}
	}
	if (tempPos.Y < boardSize - 1 && tempPos.X < boardSize - 1)
	{
		if (_board[tempPos.Y + 1][tempPos.X + 1] == turn)
		{
			// Black
			if (turn == 1)
			{
				pos_needToChangeBlack.Append(tempTArray);
			}
			// White
			else
			{
				pos_needToChangeWhite.Append(tempTArray);
			}
		}
	}
	
}
void UBoardScreen::SearchReversePos_UpperLeft(int32 y, int32 x)
{
	if (y > 0 && x > 0 && _board[y - 1][x - 1] == 0)
	{
		return;
	}

	Pos tempPos;
	tempPos.Y = y;
	tempPos.X = x;

	TArray<Pos> tempTArray;

	while (tempPos.Y > 0 && tempPos.X > 0 && _board[tempPos.Y - 1][tempPos.X - 1] != turn)
	{
		tempPos.Y--;
		tempPos.X--;

		if (_board[tempPos.Y][tempPos.X] == 0)
		{
			return;
		}

		// Black
		if (turn == 1)
		{
			tempTArray.Add(tempPos);
		}
		// White
		else
		{
			tempTArray.Add(tempPos);
		}
	}

	if (tempPos.Y > 0 && tempPos.X > 0)
	{
		if (_board[tempPos.Y - 1][tempPos.X - 1] == turn)
		{
			// Black
			if (turn == 1)
			{
				pos_needToChangeBlack.Append(tempTArray);
			}
			// White
			else
			{
				pos_needToChangeWhite.Append(tempTArray);
			}
		}
	}
	
}
void UBoardScreen::SearchReversePos_UpperRight(int32 y, int32 x)
{
	if (y > 0 && x < boardSize - 1 && _board[y - 1][x + 1] == 0)
	{
		return;
	}

	Pos tempPos;
	tempPos.Y = y;
	tempPos.X = x;

	TArray<Pos> tempTArray;

	while (tempPos.Y > 0 && tempPos.X < boardSize - 1 && _board[tempPos.Y - 1][tempPos.X + 1] != turn)
	{
		tempPos.Y--;
		tempPos.X++;

		if (_board[tempPos.Y][tempPos.X] == 0)
		{
			return;
		}

		// Black
		if (turn == 1)
		{
			tempTArray.Add(tempPos);
		}
		// White
		else
		{
			tempTArray.Add(tempPos);
		}
	}

	if (tempPos.Y > 0 && tempPos.X < boardSize - 1)
	{
		if (_board[tempPos.Y - 1][tempPos.X + 1] == turn)
		{
			// Black
			if (turn == 1)
			{
				pos_needToChangeBlack.Append(tempTArray);
			}
			// White
			else
			{
				pos_needToChangeWhite.Append(tempTArray);
			}
		}
	}
	
}
void UBoardScreen::SearchReversePos_Up(int32 y, int32 x)
{
	if (y > 0 && _board[y - 1][x] == 0)
	{
		return;
	}

	Pos tempPos;
	tempPos.Y = y;
	tempPos.X = x;

	TArray<Pos> tempTArray;

	
	while (tempPos.Y > 0 && _board[tempPos.Y - 1][tempPos.X] != turn)
	{
		tempPos.Y--;

		if (_board[tempPos.Y][tempPos.X] == 0)
		{
			return;
		}

		// Black
		if (turn == 1)
		{
			tempTArray.Add(tempPos);
		}
		// White
		else
		{
			tempTArray.Add(tempPos);
		}
	}

	if (tempPos.Y > 0)
	{
		if (_board[tempPos.Y - 1][tempPos.X] == turn)
		{
			// Black
			if (turn == 1)
			{
				pos_needToChangeBlack.Append(tempTArray);
			}
			// White
			else
			{
				pos_needToChangeWhite.Append(tempTArray);
			}
		}
	}
}
void UBoardScreen::SearchReversePos_Down(int32 y, int32 x)
{
	if (y < boardSize - 1 && _board[y + 1][x] == 0)
	{
		return;
	}

	Pos tempPos;
	tempPos.Y = y;
	tempPos.X = x;

	TArray<Pos> tempTArray;

	while (tempPos.Y < boardSize - 1 && _board[tempPos.Y + 1][tempPos.X] != turn)
	{
		tempPos.Y++;

		if (_board[tempPos.Y][tempPos.X] == 0)
		{
			return;
		}

		// Black
		if (turn == 1)
		{
			tempTArray.Add(tempPos);
		}
		// White
		else
		{
			tempTArray.Add(tempPos);
		}
	}

	if (tempPos.Y < boardSize - 1)
	{
		if (_board[tempPos.Y + 1][tempPos.X] == turn)
		{
			// Black
			if (turn == 1)
			{
				pos_needToChangeBlack.Append(tempTArray);
			}
			// White
			else
			{
				pos_needToChangeWhite.Append(tempTArray);
			}
		}
	}
	
}
void UBoardScreen::SearchReversePos_Left(int32 y, int32 x)
{
	if (x > 0 && _board[y][x - 1] == 0)
	{
		return;
	}

	Pos tempPos;
	tempPos.Y = y;
	tempPos.X = x;

	TArray<Pos> tempTArray;

	while (tempPos.X > 0 && _board[tempPos.Y][tempPos.X - 1] != turn)
	{
		tempPos.X--;

		if (_board[tempPos.Y][tempPos.X] == 0)
		{
			return;
		}

		// Black
		if (turn == 1)
		{
			tempTArray.Add(tempPos);
		}
		// White
		else
		{
			tempTArray.Add(tempPos);
		}
	}

	if (x > 0)
	{
		if (_board[tempPos.Y][tempPos.X - 1] == turn)
		{
			// Black
			if (turn == 1)
			{
				pos_needToChangeBlack.Append(tempTArray);
			}
			// White
			else
			{
				pos_needToChangeWhite.Append(tempTArray);
			}
		}
	}
	
}
void UBoardScreen::SearchReversePos_Right(int32 y, int32 x)
{
	if (x < boardSize - 1 && _board[y][x + 1] == 0)
	{
		return;
	}

	Pos tempPos;
	tempPos.Y = y;
	tempPos.X = x;

	TArray<Pos> tempTArray;

	while (tempPos.X < boardSize - 1 && _board[tempPos.Y][tempPos.X + 1] != turn)
	{
		tempPos.X++;

		if (_board[tempPos.Y][tempPos.X] == 0)
		{
			return;
		}

		// Black
		if (turn == 1)
		{
			tempTArray.Add(tempPos);
		}
		// White
		else
		{
			tempTArray.Add(tempPos);
		}
	}

	if (tempPos.X < boardSize - 1)
	{
		if (_board[tempPos.Y][tempPos.X + 1] == turn)
		{
			// Black
			if (turn == 1)
			{
				pos_needToChangeBlack.Append(tempTArray);
			}
			// White
			else
			{
				pos_needToChangeWhite.Append(tempTArray);
			}
		}
	}
}

#pragma endregion

// Change _board[y][x] data to 1(black) or 2(white)
void UBoardScreen::ReverseBoard()
{
	// Reverse To black

	for (int i = 0; i < pos_needToChangeBlack.Num(); i++)
	{
		_board[pos_needToChangeBlack[i].Y][pos_needToChangeBlack[i].X] = 1;
	}

	pos_needToChangeBlack.Empty();


	// Reverse To White

	for (int i = 0; i < pos_needToChangeWhite.Num(); i++)
	{
		_board[pos_needToChangeWhite[i].Y][pos_needToChangeWhite[i].X] = 2;
	}

	pos_needToChangeWhite.Empty();

}

// Change Board block Image(White,Black) Function
void UBoardScreen::ChangeBoardImage()
{
	for (int32 i = 0; i < boardSize; i++)
	{
		for (int32 j = 0; j < boardSize; j++)
		{
			if (_board[i][j] == 2)
			{
				Button_Images[i][j]->Brush.SetResourceObject(Image_White);
				Button_Images[i][j]->SetVisibility(ESlateVisibility::Visible);
			}
			if (_board[i][j] == 1)
			{
				Button_Images[i][j]->Brush.SetResourceObject(Image_Black);
				Button_Images[i][j]->SetVisibility(ESlateVisibility::Visible);
			}
		}
	}
}

// Set board button that the player can Click
void UBoardScreen::ButtonEnableSetting()
{

	// Play Animation
	if (turn == 1)	// Black
	{
		PlayAnimation(BlackTurnAnimation, 0.f, 1);
	}
	else	// White
	{
		PlayAnimation(WhiteTurnAnimation, 0.f, 1);
	}

	for (int32 i = 0; i < boardSize; i++)
	{
		for (int32 j = 0; j < boardSize; j++)
		{
			if (_board[i][j] == 1 || _board[i][j] == 2)
			{
				Button_Images[i][j]->SetVisibility(ESlateVisibility::Visible);
				continue;
			}

			Button_Images[i][j]->SetVisibility(ESlateVisibility::Hidden);
			Board_Buttons[i][j]->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		}
	}
	// Find Block that Can DotCircle
	for (int32 i = 0; i < boardSize; i++)
	{
		for (int32 j = 0; j < boardSize; j++)
		{
			if (_board[i][j] == turn)
			{
				SearchIsEnable_LowerLeft(i, j);
				SearchIsEnable_LowerRight(i, j);
				SearchIsEnable_UpperLeft(i, j);
				SearchIsEnable_UpperRight(i, j);
				SearchIsEnable_Left(i, j);
				SearchIsEnable_Up(i, j);
				SearchIsEnable_Right(i, j);
				SearchIsEnable_Down(i, j);
			}
		}
	}

	// Is Pass 
	if (pos_needToChangeDotCircle.Num() == NULL)
	{
		PlayAnimation(TimeOverAnimation, 0.f, 1);
		if (turn == 2)
		{
			UE_LOG(LogTemp, Warning, TEXT("Player Pass To AI."));
			bIsWhitePassToBlack = true;
			ReverseBoard();
			ChangeBoardImage();

			turn = 1;
			ButtonEnableSetting();
			GetWorld()->GetTimerManager().UnPauseTimer(PassTimerHandle);
			
		}

		if (turn == 1 && bIsWhitePassToBlack)
		{
			GameOver();
		}
	}
	else
	{
		ChangeBlockToDotCircle();

		bIsBlackPassToWhite = false;
		bIsWhitePassToBlack = false;
	}

	CountingAllStones();
	ChangeCountingImage();
}
// Change block on the board to Dot Circle
void UBoardScreen::ChangeBlockToDotCircle()
{
	for (int32 cnt = 0; cnt < pos_needToChangeDotCircle.Num(); cnt++)
	{
		Button_Images[pos_needToChangeDotCircle[cnt].Y][pos_needToChangeDotCircle[cnt].X]->SetVisibility(ESlateVisibility::Visible);
		Button_Images[pos_needToChangeDotCircle[cnt].Y][pos_needToChangeDotCircle[cnt].X]->Brush.SetResourceObject(Image_DotCircle);
		Board_Buttons[pos_needToChangeDotCircle[cnt].Y][pos_needToChangeDotCircle[cnt].X]->SetIsEnabled(true);
	}

	pos_DotCircle.Empty();

	if (turn == 1)
	{
		// 검은돌이 자동으로 놓기 위해 점돌이 있던 위치를 따로 담아두었다가 검은돌 턴일때 이용.
		pos_DotCircle = pos_needToChangeDotCircle;

		for (int i = 0; i < pos_DotCircle.Num(); i++)
		{
			// AI가 놓을 수 있는 위치
			//UE_LOG(LogTemp, Warning, TEXT("%d %d"), pos_DotCircle[i].Y, pos_DotCircle[i].X);
		}
		
	}

	pos_needToChangeDotCircle.Empty();
}
#pragma region Search Can EnabledButton Functions

void UBoardScreen::SearchIsEnable_LowerLeft(int32 y, int32 x)
{
	if (y < boardSize - 1 && x > 0 && _board[y + 1][x - 1] == 0)
	{
		return;
	}

	while (y < boardSize - 1 && x > 0 && _board[y + 1][x - 1] != turn)
	{
		y++;
		x--;

		if (_board[y][x] == 0)
		{
			pos_needToChangeDotCircle.Add({ y,x });
			return;
		}
	}
}
void UBoardScreen::SearchIsEnable_LowerRight(int32 y, int32 x)
{
	if (y < boardSize - 1 && x < boardSize -1 && _board[y + 1][x + 1] == 0)
	{
		return;
	}

	while (y < boardSize - 1 && x < boardSize - 1 && _board[y + 1][x + 1] != turn)
	{
		y++;
		x++;

		if (_board[y][x] == 0)
		{
			pos_needToChangeDotCircle.Add({ y,x });
			return;
		}
	}
}
void UBoardScreen::SearchIsEnable_UpperLeft(int32 y, int32 x)
{
	if (y > 0 && x > 0 && _board[y - 1][x - 1] == 0)
	{
		return;
	}

	while (y > 0 && x > 0 && _board[y - 1][x - 1] != turn)
	{
		y--;
		x--;

		if (_board[y][x] == 0)
		{
			pos_needToChangeDotCircle.Add({ y,x });
			return;
		}
	}
}
void UBoardScreen::SearchIsEnable_UpperRight(int32 y, int32 x)
{
	if (y > 0 && x < boardSize - 1 && _board[y - 1][x + 1] == 0)
	{
		return;
	}

	while (y > 0 && x < boardSize -1 && _board[y - 1][x + 1] != turn)
	{
		y--;
		x++;

		if (_board[y][x] == 0)
		{
			pos_needToChangeDotCircle.Add({ y,x });
			return;
		}
	}
}
void UBoardScreen::SearchIsEnable_Left(int32 y, int32 x)
{
	if (x > 0 && _board[y][x - 1] == 0)
	{
		return;
	}

	while (x > 0 && _board[y][x - 1] != turn)
	{

		x--;

		if (_board[y][x] == 0)
		{
			pos_needToChangeDotCircle.Add({ y,x });
			return;
		}
	}
}
void UBoardScreen::SearchIsEnable_Up(int32 y, int32 x)
{
	if (y > 0 && _board[y - 1][x] == 0)
	{
		return;
	}

	while (y > 0 && _board[y - 1][x] != turn)
	{
		y--;

		if (_board[y][x] == 0)
		{
			pos_needToChangeDotCircle.Add({ y,x });
			return;
		}
	}
}
void UBoardScreen::SearchIsEnable_Right(int32 y, int32 x)
{
	if (x < boardSize - 1 && _board[y][x + 1] == 0)
	{
		return;
	}

	while (x < boardSize - 1 && _board[y][x + 1] != turn)
	{
		x++;

		if (_board[y][x] == 0)
		{
			pos_needToChangeDotCircle.Add({ y,x });
			return;
		}
	}
}
void UBoardScreen::SearchIsEnable_Down(int32 y, int32 x)
{
	if (y < boardSize - 1 && _board[y + 1][x] == 0)
	{
		return;
	}

	while (y < boardSize - 1 && _board[y + 1][x] != turn)
	{

		y++;

		if (_board[y][x] == 0)
		{
			pos_needToChangeDotCircle.Add({ y,x });
			return;
		}
	}
}

#pragma endregion

void UBoardScreen::CountingAllStones()
{
	cnt_Black = 0;
	cnt_White = 0;

	for (int32 i = 0; i < boardSize; i++)
	{
		for (int32 j = 0; j < boardSize; j++)
		{
			if (_board[i][j] == 2)
			{
				cnt_White += 1;
			}
			if (_board[i][j] == 1)
			{
				cnt_Black += 1;
			}
		}
	}

	// LOG
	//UE_LOG(LogTemp, Warning, TEXT("White : %d  vs  Black : %d"), cnt_White, cnt_Black);
}
void UBoardScreen::ChangeCountingImage()
{
	int32 WUnits, WTens, BUnits, BTens;
	int32 WUnitsTemp = 0, WTensTemp = 0, BUnitsTemp = 0, BTensTemp = 0;

	WUnits = cnt_White % 10;
	WTens = cnt_White / 10;
	BUnits = cnt_Black % 10;
	BTens = cnt_Black / 10;

	for (int32 i = 0; i < 10; i++)
	{
		if (i == WUnits)
		{
			Image_WhiteCntUnits->Brush.SetResourceObject(Textures_BloackCnts[i]);

			if (WUnits != WUnitsTemp)
			{
				WUnitsTemp = WUnits;
				PlayAnimation(ScoreUnitsNumberAnimation, 0.f, 1);
			}
		}

		if (i == WTens)
		{
			Image_WhiteCntTens->Brush.SetResourceObject(Textures_BloackCnts[i]);

			if (WTens != WTensTemp)
			{
				WTensTemp = WTens;
				PlayAnimation(WhiteScoreTensNumberAnimation, 0.f, 1);
			}
		}
	}

	for (int32 i = 0; i < 10; i++)
	{
		if (i == BUnits)
		{
			Image_BlackCntUnits->Brush.SetResourceObject(Textures_BloackCnts[i]);

			if (BUnits != BUnitsTemp)
			{
				BUnitsTemp = BUnits;
				PlayAnimation(ScoreUnitsNumberAnimation, 0.f, 1);
			}
		}

		if (i == BTens)
		{
			Image_BlackCntTens->Brush.SetResourceObject(Textures_BloackCnts[i]);

			if (BTens != BTensTemp)
			{
				BTensTemp = BTens;
				PlayAnimation(BlackScoreTensNumberAnimation, 0.f, 1);
			}
		}
	}
}

bool UBoardScreen::IsGameOver()
{
	if (cnt_White == 0 || cnt_Black == 0
		|| (cnt_White + cnt_Black == boardSize * boardSize)
		|| (bIsBlackPassToWhite == true && bIsWhitePassToBlack == true))
	{
		return true;
	}
	else
	{
		return false;
	}
}
// GameOver Function
void UBoardScreen::GameOver()
{
	// Delete
	GetWorld()->GetTimerManager().ClearTimer(countdownTimerHandle);
	pos_needToChangeWhite.Empty();
	pos_needToChangeBlack.Empty();
	pos_needToChangeDotCircle.Empty();
	pos_DotCircle.Empty();

	FString draw = "DRAW";
	FString whiteWin = "White Win!";
	FString blackWin = "Black Win";
	int32 winner;

	CountingAllStones();
	ChangeCountingImage();

	if (cnt_Black == cnt_White)
	{
		winner = 0;
	}
	else if (cnt_Black > cnt_White)
	{
		winner = 1;
	}
	else
	{
		winner = 2;
	}

	switch (winner)
	{
	case 0:
		TextBlock_Winner->SetText(FText::FromString(draw));
		break;
	case 1:
		TextBlock_Winner->SetText(FText::FromString(blackWin));
		break;
	case 2:
		TextBlock_Winner->SetText(FText::FromString(whiteWin));
		break;
	}

	// Animation Start.
	PlayAnimation(GameOverAnimation, 0.0f, 1);

	//UE_LOG(LogTemp, Warning, TEXT("Score : White : %d  :  Black : %d"), cnt_White, cnt_Black);
}

/*--------------------------------------------------------------Timer Function--------------------------------------------------------------------------------------------------------*/

// Display Timer Function
void UBoardScreen::UpdateTimerDisplay()
{
	int32 units;
	int32 tens, tensTemp = 0;

	units = (int32)countdownTime % 10;
	tens = (int32)countdownTime / 10;
	tensTemp = tens;

	for (int32 i = 0; i < 10; i++)
	{
		if (units == 1)
		{
			Image_NumUnits->Brush.ImageSize.X = 35;
		}
		else
		{
			Image_NumUnits->Brush.ImageSize.X = 63;
		}
		if (tens == 1)
		{
			Image_NumTens->Brush.ImageSize.X = 35;
		}
		else
		{
			Image_NumTens->Brush.ImageSize.X = 63;
		}

		if (i == units)
		{
			PlayAnimation(TimerUnitsNumberAnimation, 0.f, 1);
			Image_NumUnits->Brush.SetResourceObject(Textures_Timer[i]);
		}

		if (i == tens)
		{
			Image_NumTens->Brush.SetResourceObject(Textures_Timer[i]);
			
			if (units == 9)
			{
				PlayAnimation(TimerTensNumberAnimation, 0.f, 1);
			}
		}
	}
	
	// Countdown
	countdownTime--;

	if (countdownTime == -1)
	{
		PlayAnimation(TimeOverAnimation, 0.f, 1);
		countdownTime = MyGameMode->GetCountdownTime();

		// Black
		if (turn == 1)
		{
			turn = 2;
			ButtonEnableSetting();
		}
		// White
		else
		{
			turn = 1;
			ButtonEnableSetting();
			AI_Turn();
		}
	}
}
// Game Start Timer Function
void UBoardScreen::StartGameTimer()
{
	startGameTime--;

	if (startGameTime == 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(StartGameTimerHandle);
		AI_Turn();
	}
}
// AI Timer Function
void UBoardScreen::AI_Timer()
{
	AITurnTime--;

	if (AITurnTime == 0)
	{
		AI_Behavior();

		Image_BShape->Brush.SetResourceObject(BlackShapeImage);
		AITurnTime = 2.f;

		GetWorld()->GetTimerManager().PauseTimer(AITurnTimerHandle);
		GetWorld()->GetTimerManager().UnPauseTimer(countdownTimerHandle);
	}
}

void UBoardScreen::Pass_Timer()
{
	passTime--;
	Image_BShape->Brush.SetResourceObject(AI_Face);

	if (passTime == 0)
	{
		AI_Behavior();
		passTime = 2.f;
		Image_BShape->Brush.SetResourceObject(BlackShapeImage);
		GetWorld()->GetTimerManager().PauseTimer(PassTimerHandle);
	}
}

/*--------------------------------------------------------------AI Function--------------------------------------------------------------------------------------------------------*/

// Timer Setting for AI Turn
void UBoardScreen::AI_Turn()
{
	// Change Image.
	Image_BShape->Brush.SetResourceObject(AI_Face);
	// Pause Game Timer.
	GetWorld()->GetTimerManager().PauseTimer(countdownTimerHandle);
	// Run AI(AI_Behavior).
	GetWorld()->GetTimerManager().UnPauseTimer(AITurnTimerHandle);
}
// Get random pos in dotCirclesTArray
Pos UBoardScreen::GetAISelectedPos()
{
	Pos AISelectedPos;
	AISelectedPos.Y = 0;
	AISelectedPos.X = 0;
	int32 randomPos;

	if (pos_DotCircle.Num() == 1)
	{
		randomPos = 0;
	}
	else
	{
		randomPos = FMath::FRandRange(0, pos_DotCircle.Num() - 1);
	}

	AISelectedPos.Y = pos_DotCircle[randomPos].Y;
	AISelectedPos.X = pos_DotCircle[randomPos].X;

	pos_DotCircle.Empty();

	return AISelectedPos;
}
// Put stone and turn pass to player
void UBoardScreen::AI_Behavior()
{
	if (pos_DotCircle.Num() != NULL)
	{
		//UE_LOG(LogTemp, Warning, TEXT("pos_DotCircle not null."));
		Pos AI_SelectedPos = GetAISelectedPos();
		// Temp Pos Add To TArray.
		pos_needToChangeBlack.Add(AI_SelectedPos);
		// Reverse.
		ButtonReverseSetting(AI_SelectedPos.Y, AI_SelectedPos.X);

		ReverseBoard();
		// Change Image.
		ChangeBoardImage();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Pass To Player."));
		PlayAnimation(TimeOverAnimation, 0.f, 1);
		bIsBlackPassToWhite = true;
	}

	if (!IsGameOver())
	{
		turn = 2;
		ButtonEnableSetting();
	}
	else
	{
		GameOver();
	}
}

/*--------------------------------------------------------------Button Function--------------------------------------------------------------------------------------------------------*/

void UBoardScreen::Btn_Restart_OnClicked()
{
	if (RestartWidgetClass != nullptr)
	{
		AOthelloGameMode* MyMode =
			Cast< AOthelloGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

		MyMode->ChangeMenuWidget(RestartWidgetClass);
	}
}
void UBoardScreen::Btn_Quit_OnClicked()
{
	if (QuitWidgetClass != nullptr)
	{
		AOthelloGameMode* MyMode =
			Cast< AOthelloGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

		MyMode->ChangeMenuWidget(QuitWidgetClass);
	}
}
void UBoardScreen::Btn_Exit_OnClicked()
{
	UKismetSystemLibrary::QuitGame(this, 0, EQuitPreference::Quit, false);
}