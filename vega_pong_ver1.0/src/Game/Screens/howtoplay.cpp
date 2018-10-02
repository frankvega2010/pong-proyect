#include "howtoplay.h"

#include "raylib.h"
#include "Setup/Game.h"
#include "Screens\gameplay.h"

namespace Juego
{
	static const int Menu = 6;

	namespace Howtoplay_Section
	{
		static void HowtoplayInput()
		{

			if (IsKeyPressed(KEY_ONE))
			{
				#ifdef AUDIO
				PlaySound(pong_select_menu);
				#endif
				selectOption = Menu;
				isScreenFinished = true;
			}
		}

		void UpdateHowtoplayScreen()
		{
			#ifdef AUDIO
			UpdateMusicStream(pong_menu_song);
			#endif

			HowtoplayInput();
		}

		void InitHowtoplayScreen()
		{
			isScreenFinished = false;
		}

		bool FinishHowtoplayScreen()
		{
			return isScreenFinished;
		}

		void DrawHowtoplay()
		{
			DrawText(FormatText("How to Play"), screenWidth / 3, 20, defaultFontSize, WHITE);
			DrawText(FormatText("Player 1:"), screenWidth / 8, screenHeight / 6, defaultFontSize, WHITE);
			DrawText(FormatText("W - Go Up"), screenWidth / 8, screenHeight / 4.0f, defaultFontSize, WHITE);
			DrawText(FormatText("S - Go Down"), screenWidth / 8, screenHeight / 3.0f, defaultFontSize, WHITE);
			DrawText(FormatText("Player 2:"), screenWidth / 8, screenHeight / 2.0f, defaultFontSize, WHITE);
			DrawText(FormatText("KEY_UP - Go Up"), screenWidth / 8, screenHeight / 1.7f, defaultFontSize, WHITE);
			DrawText(FormatText("KEY_DOWN - Go Down"), screenWidth / 8, screenHeight / 1.5f, defaultFontSize, WHITE);
			DrawText(FormatText("Score Limit = %i", scoreLimit), screenWidth / 1.7, screenHeight / 2.5, defaultFontSize, WHITE);
			DrawText(FormatText("1. Go back to Menu"), 10, screenHeight - 80, defaultFontSize, WHITE);
		}
	}
}
