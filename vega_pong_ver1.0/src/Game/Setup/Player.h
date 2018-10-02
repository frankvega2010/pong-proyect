#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace Juego
{
	struct Player {
		Vector2 position;
		Vector2 size;
		int score;
		int scorePositionX;
		bool scored;
		float defaultSpeed;
	};

	extern const float cpu_easy;
	extern const float cpu_normal;
	extern const float cpu_hard;
	extern float cpuDifficulty;

	extern bool isPlayer2CPU;

	const int maxplayers = 2;

	extern Player players[maxplayers];

	namespace Gameplay_Section
	{
		void createPlayer();
		void createMiddleLine();
		void playerInput();
		void playerUpdate();
		void playerDraw();
		void player1AddScore();
		void player2AddScore();
	}
}
#endif // PLAYER_H
