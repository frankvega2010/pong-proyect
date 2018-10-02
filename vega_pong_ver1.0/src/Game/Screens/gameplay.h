#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "raylib.h"

namespace Juego
{
	extern int scoreLimit;

	namespace Gameplay_Section
	{
		void UpdateGameplayScreen();
		void InitGameplayScreen();
		void InitGameplayVariables();
		void RestartPhase();
		bool FinishGameplayScreen();
		void DrawGameplay();
	}
}
#endif // GAMEPLAY_H