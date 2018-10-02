#include "settings.h"

#include "raylib.h"
#include "Setup/Game.h"
#include "Screens/gameplay.h"
#include "Setup\Player.h"
#include "Setup\Ball.h"

using namespace Juego;
using namespace Gameplay_Section;

namespace Juego
{
	static const int Menu = 6;

	namespace Settings_Section
	{
		static void SettingsInput()
		{
			if (IsKeyPressed(KEY_ONE))
			{
				#ifdef AUDIO
				PlaySound(pong_select_option1);
				#endif
				screenWidth = 640;
				screenHeight = 480;
				defaultFontSize = 60 / 2;
				defaultFontSizeGameplayText = 25;
				defaultFontSizeGameplayScore = 90;
				SetWindowSize(screenWidth, screenHeight);
				InitGameplayVariables();
				players[0].size = { 10, 60 };
				players[1].size = { 10, 60 };
				players[0].defaultSpeed = 375.0f;
				players[1].defaultSpeed = 375.0f;
				ball.speed = { 300.0f, 0 };
				ball.radio = 5;
				ball.defaultMultiplier = -1.1f;
				ball.defaultMultiplierHorizontalVertical = -0.7f;
				ball.defaultMultiplierDown = 15.0f;
				ball.defaultMultiplierUp = -15.0f;
			}

			if (IsKeyPressed(KEY_TWO))
			{
				#ifdef AUDIO
				PlaySound(pong_select_option1);
				#endif
				screenWidth = 720;
				screenHeight = 576;
				defaultFontSize = 60 / 2;
				defaultFontSizeGameplayText = 25;
				defaultFontSizeGameplayScore = 90;
				SetWindowSize(screenWidth, screenHeight);
				InitGameplayVariables();
				players[0].size = { 10, 60 };
				players[1].size = { 10, 60 };
				players[0].defaultSpeed = 375.0f;
				players[1].defaultSpeed = 375.0f;
				ball.speed = { 300.0f, 0 };
				ball.radio = 5;
				ball.defaultMultiplier = -1.1f;
				ball.defaultMultiplierHorizontalVertical = -0.7f;
				ball.defaultMultiplierDown = 15.0f;
				ball.defaultMultiplierUp = -15.0f;
			}

			if (IsKeyPressed(KEY_THREE))
			{
				#ifdef AUDIO
				PlaySound(pong_select_option1);
				#endif
				screenWidth = 1600;
				screenHeight = 900;
				defaultFontSize = 60 / 1;
				defaultFontSizeGameplayText = 30 / 1;
				defaultFontSizeGameplayScore = 120;
				SetWindowSize(screenWidth, screenHeight);
				InitGameplayVariables();
				players[0].size = { 20, 120 };
				players[1].size = { 20, 120 };
				players[0].defaultSpeed = 750.0f;
				players[1].defaultSpeed = 750.0f;
				ball.speed = { 500.0f, 0 };
				ball.radio = 10;
				ball.defaultMultiplier = -1.1f;
				ball.defaultMultiplierHorizontalVertical = -1.2f;
				ball.defaultMultiplierDown = 20.0f;
				ball.defaultMultiplierUp = -20.0f;
			}

			if (IsKeyPressed(KEY_FOUR))
			{
				#ifdef AUDIO
				PlaySound(pong_select_option1);
				#endif
				screenWidth = 1300;
				screenHeight = 800;
				defaultFontSize = 60 / 1;
				defaultFontSizeGameplayText = 30 / 1;
				defaultFontSizeGameplayScore = 120;
				SetWindowSize(screenWidth, screenHeight);
				InitGameplayVariables();
				players[0].size = { 20, 120 };
				players[1].size = { 20, 120 };
				players[0].defaultSpeed = 750.0f;
				players[1].defaultSpeed = 750.0f;
				ball.speed = { 500.0f, 0 };
				ball.radio = 10;
				ball.defaultMultiplier = -1.1f;
				ball.defaultMultiplierHorizontalVertical = -1.2f;
				ball.defaultMultiplierDown = 20.0f;
				ball.defaultMultiplierUp = -20.0f;
			}

			if (IsKeyPressed(KEY_SIX))
			{
				#ifdef AUDIO
				PlaySound(pong_select_option2);
				#endif
				cpuDifficulty = cpu_easy;
			}

			if (IsKeyPressed(KEY_SEVEN))
			{
				#ifdef AUDIO
				PlaySound(pong_select_option2);
				#endif
				cpuDifficulty = cpu_normal;
			}

			if (IsKeyPressed(KEY_EIGHT))
			{
				#ifdef AUDIO
				PlaySound(pong_select_option2);
				#endif
				cpuDifficulty = cpu_hard;
			}

			if (IsKeyPressed(KEY_NINE))
			{
				#ifdef AUDIO
				PlaySound(pong_select_menu);
				#endif
				selectOption = Menu;
				isScreenFinished = true;
			}
		}

		void UpdateSettingsScreen()
		{
			#ifdef AUDIO
			UpdateMusicStream(pong_menu_song);
			#endif
			SettingsInput();
		}
		void InitSettingsScreen()
		{
			isScreenFinished = false;
		}
		bool FinishSettingsScreen()
		{
			return isScreenFinished;
		}

		void DrawSettings()
		{
			DrawText(FormatText("Resolution"), MeasureText("Bienvenido al pong", 60) / 6, 20, defaultFontSize, WHITE);
			DrawText(FormatText("1. 640x480"), 10, 120, defaultFontSize, WHITE);
			DrawText(FormatText("2. 720x576"), 10, 200, defaultFontSize, WHITE);
			DrawText(FormatText("3. 1600x900"), 10, 280, defaultFontSize, WHITE);
			DrawText(FormatText("4. 1300x800"), 10, 360, defaultFontSize, WHITE);
			DrawText(FormatText("CPU Difficulty"), screenWidth / 1.8, 20, defaultFontSize, WHITE);
			DrawText(FormatText("6. Easy"), screenWidth / 1.5, 120, defaultFontSize, WHITE);
			DrawText(FormatText("7. Normal"), screenWidth / 1.5, 200, defaultFontSize, WHITE);
			DrawText(FormatText("8. Hard"), screenWidth / 1.5, 280, defaultFontSize, WHITE);
			DrawText(FormatText("9. Go back to Menu"), 10, 440, defaultFontSize, WHITE);
		}
	}
}