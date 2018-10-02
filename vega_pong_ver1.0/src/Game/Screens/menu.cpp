#include "menu.h"

#include "raylib.h"
#include "Setup/Game.h"
#include "Setup\Player.h"

using namespace Juego;

namespace Juego
{
	enum gameActions
	{
		Settings = 7,
		PlayGame,
		QuitGame,
		Credits,
		Howtoplay
	};

	namespace Menu_Section
	{
		static void MenuInput()
		{

			if (IsKeyPressed(KEY_ONE))
			{
				#ifdef AUDIO
								PlaySound(pong_select_menu);
				#endif
				selectOption = PlayGame;
				isPlayer2CPU = true;
				isScreenFinished = true;
			}

			if (IsKeyPressed(KEY_TWO))
			{
				#ifdef AUDIO
								PlaySound(pong_select_menu);
				#endif
				selectOption = PlayGame;
				isPlayer2CPU = false;
				isScreenFinished = true;
			}

			if (IsKeyPressed(KEY_THREE))
			{
				#ifdef AUDIO
								PlaySound(pong_select_menu);
				#endif
				selectOption = Settings;
				isScreenFinished = true;
			}

			if (IsKeyPressed(KEY_FOUR))
			{
				#ifdef AUDIO
								PlaySound(pong_select_menu);
				#endif
				selectOption = Howtoplay;
				isScreenFinished = true;
			}

			if (IsKeyPressed(KEY_FIVE))
			{
				#ifdef AUDIO
				PlaySound(pong_select_menu);
				#endif
				selectOption = Credits;
				isScreenFinished = true;
			}

			if (IsKeyPressed(KEY_SIX))
			{
				selectOption = QuitGame;
				isScreenFinished = true;
			}
		}

		void UpdateMenuScreen()
		{
			#ifdef AUDIO
			UpdateMusicStream(pong_menu_song);
			#endif
			
			MenuInput();
		}

		void InitMenuScreen()
		{
			isScreenFinished = false;
		}

		bool FinishMenuScreen()
		{
			return isScreenFinished;
		}

		void DrawMenu()
		{
			DrawText(FormatText("Simple Pong!"), MeasureText("Simple Pong!", 60) / 6, 20, defaultFontSize, WHITE);
			DrawText(FormatText("1. Player vs CPU"), 10, screenHeight / 6.3, defaultFontSize, WHITE);
			DrawText(FormatText("2. 2 Players Local"), 10, screenHeight / 4.2, defaultFontSize, WHITE);
			DrawText(FormatText("3. Options"), 10, screenHeight / 3.2, defaultFontSize, WHITE);
			DrawText(FormatText("4. How to play"), 10, screenHeight / 2.6, defaultFontSize, WHITE);
			DrawText(FormatText("5. Credits"), 10, screenHeight / 2.2, defaultFontSize, WHITE);
			DrawText(FormatText("6. Quit"), 10, screenHeight / 1.9, defaultFontSize, WHITE);
			DrawText(FormatText("Ver. 1.0 by Franco Vega"), screenWidth / 2.8, screenHeight / 1.1, defaultFontSize, WHITE);
		}
	}
}