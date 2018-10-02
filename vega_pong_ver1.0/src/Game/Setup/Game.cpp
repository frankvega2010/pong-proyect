#include "Game.h"

#include "Screens/gameplay.h"
#include "Screens/menu.h"
#include "Screens/gameover.h"
#include "Screens/settings.h"
#include "Screens/credits.h"
#include "Screens/howtoplay.h"

using namespace Juego;
using namespace Gameplay_Section;
using namespace GameOver_Section;
using namespace Menu_Section;
using namespace Settings_Section;
using namespace Credits_Section;
using namespace Howtoplay_Section;

namespace Juego
{
	enum gameActions
	{
		Gameplay = 3,
		GameOver,
		Restart_Gameplay,
		Menu,
		Settings,
		PlayGame,
		QuitGame,
		Credits,
		Howtoplay
	};

	int screenWidth;
	int screenHeight;

	bool isScreenFinished;

	int selectOption;
	static int gamePhase;

	int defaultFontSize;
	int defaultFontSizeGameplayText;
	int defaultFontSizeGameplayScore;

	#ifdef AUDIO

	Sound pong_hit_wall;
	Sound pong_hit_player;
	Sound pong_player_scored;
	Sound pong_match_end;
	Sound pong_select_menu;
	Sound pong_select_option1;
	Sound pong_select_option2;

	Music pong_menu_song;

	#endif

	static void Init()
	{
		SetExitKey(0);

		screenWidth = 1300;//testing purposes 1300x800 default min 720x576
		screenHeight = 800;

		selectOption = 0;

		defaultFontSize = 60;
		defaultFontSizeGameplayText = 30;
		defaultFontSizeGameplayScore = 120;

		InitGameplayVariables();

		InitWindow(screenWidth, screenHeight, "Simple Pong!");

	#ifdef AUDIO

		InitAudioDevice();

		pong_hit_wall = LoadSound("res/wall.wav");
		pong_hit_player = LoadSound("res/player.wav");
		pong_player_scored = LoadSound("res/score.wav");
		pong_match_end = LoadSound("res/pong_frank_match_end.wav");
		pong_select_menu = LoadSound("res/pong_frank_select1.wav");
		pong_select_option1 = LoadSound("res/pong_frank_select2.wav");
		pong_select_option2 = LoadSound("res/pong_frank_select3.wav");

		pong_menu_song = LoadMusicStream("res/menu2.ogg");

		PlayMusicStream(pong_menu_song);
		SetMusicVolume(pong_menu_song, 0.40);

	#endif



		//SetTargetFPS(60);// Set target frames-per-second
		//--------------------------------------------------------------------------------------

		gamePhase = Menu;
		InitMenuScreen();
	}

	static void DeInit()
	{
	#ifdef AUDIO
		UnloadSound(pong_hit_player);
		UnloadSound(pong_hit_wall);
		UnloadSound(pong_player_scored);
		UnloadSound(pong_match_end);
		UnloadSound(pong_select_menu);
		UnloadSound(pong_select_option1);
		UnloadSound(pong_select_option2);
		UnloadMusicStream(pong_menu_song);
		CloseAudioDevice();
	#endif
		CloseWindow();
	}

	static void Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		switch (gamePhase)
		{
		case Menu: Menu_Section::DrawMenu(); break;
		case Gameplay: Gameplay_Section::DrawGameplay(); break;
		case GameOver: GameOver_Section::DrawGameOver(); break;
		case Settings: Settings_Section::DrawSettings(); break;
		case Credits: Credits_Section::DrawCredits(); break;
		case Howtoplay: Howtoplay_Section::DrawHowtoplay(); break;
		}

		EndDrawing();
	}

	static void Update()
	{
		switch (gamePhase)
		{
		case Menu:
		{
			UpdateMenuScreen();

			if (FinishMenuScreen())
			{

				switch (selectOption)
				{
				case PlayGame:
				{
				#ifdef AUDIO
					StopMusicStream(pong_menu_song);
				#endif
					RestartPhase();
					gamePhase = Gameplay;
					InitGameplayScreen();
					break;
				}
				case Settings:
				{
					gamePhase = Settings;
					InitSettingsScreen();
					break;
				}
				case Credits:
				{
					gamePhase = Credits;
					InitCreditsScreen();
					break;
				}
				case Howtoplay:
				{
					gamePhase = Howtoplay;
					InitHowtoplayScreen();
					break;
				}
				case QuitGame:
				{
				#ifdef AUDIO
					StopMusicStream(pong_menu_song);
				#endif

					gamePhase = 0;
					return;
					break;
				}
				}
			}
		}
		break;
		case Settings:
		{
			UpdateSettingsScreen();

			if (FinishSettingsScreen())
			{
				gamePhase = Menu;
				InitMenuScreen();
			}
		}
		break;

		case GameOver:
		{
			UpdateGameOverScreen();

			if (FinishGameOverScreen())
			{
				switch (selectOption)
				{
				case Menu:
				{
				#ifdef AUDIO
					PlayMusicStream(pong_menu_song);
				#endif

					gamePhase = Menu;
					InitMenuScreen();
					break;
				}
				case Restart_Gameplay:
				{
					RestartPhase();
					gamePhase = Gameplay;
					InitGameplayScreen();
					break;
				}
				}
			}
		}
		break;

		case Gameplay:
		{
			UpdateGameplayScreen();

			if (FinishGameplayScreen())
			{
				gamePhase = GameOver;
				InitGameOverScreen();
			}
		}
		break;
		case Credits:
		{
			UpdateCreditsScreen();

			if (FinishCreditsScreen())
			{
				gamePhase = Menu;
				InitMenuScreen();
			}
		}
		break;
		case Howtoplay:
		{
			UpdateHowtoplayScreen();

			if (FinishHowtoplayScreen())
			{
				gamePhase = Menu;
				InitMenuScreen();
			}
		}
		break;
		}
	}

	void Execute()
	{
		Init();
		while (!WindowShouldClose())
		{
			Update();
			if (gamePhase == 0) return;
			Draw();
		}
		DeInit();
	}
}