#include "Player.h"

#include "Setup\Game.h"
#include "Setup\Ball.h"

namespace Juego
{
	Player players[maxplayers];
	static Player middleLine;
	bool isPlayer2CPU = false;
	float cpuDifficulty = cpu_normal;

	const float cpu_easy = 1.3f;
	const float cpu_normal = 1.25f;
	const float cpu_hard = 1.24f;

	namespace Gameplay_Section
	{
		void createPlayer()
		{
			for (int i = 0; i < maxplayers; i++)
			{
				players[i].position.x = 0; // default value
				players[i].position.y = screenHeight / 2; // default value = screenHeight / 2 - 40
				players[i].size = { 20, 120 }; // mitad = 60
				players[i].score = 0;
				players[i].scorePositionX = screenWidth / 2 - 250;
				players[i].scored = false;
				players[i].defaultSpeed = 750.0f;
			}

			// Setting player 1 X Position
			players[0].position.x = screenWidth / 34; // default value = screenWidth / 2 - 550 - 20
			players[0].scorePositionX = screenWidth / 2 - 250;

			 // Setting player 2 X Position
			players[1].position.x = screenWidth / 2 * 1.9; // default value = screenWidth / 2 + 550
			players[1].scorePositionX = screenWidth / 2 + 250;
		}

		void createMiddleLine()
		{
			middleLine.position.x = screenWidth / 2;
			middleLine.position.y = 0;
			middleLine.size = { 5, (float)screenHeight };
		}
		
		void playerInput()
		{
			if (IsKeyDown(KEY_W)) players[0].position.y -= players[0].defaultSpeed * GetFrameTime();
			if (IsKeyDown(KEY_S)) players[0].position.y += players[0].defaultSpeed * GetFrameTime();

			if (!(isPlayer2CPU))
			{
				if (IsKeyDown(KEY_UP)) players[1].position.y -= players[1].defaultSpeed * GetFrameTime();
				if (IsKeyDown(KEY_DOWN)) players[1].position.y += players[1].defaultSpeed * GetFrameTime();
			}			
		}

		void playerUpdate()
		{
			if (isPlayer2CPU)
			{
				players[1].position.y = (ball.position.y / cpuDifficulty);
			}

			for (int i = 0; i < maxplayers; i++)
			{
				if (players[i].position.y < 0) players[i].position.y = 0;
				if (players[i].position.y + players[i].size.y > screenHeight) players[i].position.y = screenHeight - players[i].size.y;
			}
		}

		void playerDraw()
		{
			// Draw middle line
			DrawRectangle(middleLine.position.x, middleLine.position.y, middleLine.size.x, middleLine.size.y, WHITE);

			DrawRectangle(players[0].position.x, players[0].position.y, players[0].size.x, players[0].size.y, RED);

			DrawRectangle(players[1].position.x, players[1].position.y, players[1].size.x, players[1].size.y, SKYBLUE);

			if (isPlayer2CPU)
			{
				DrawRectangle(players[1].position.x, players[1].position.y, players[1].size.x, players[1].size.y, YELLOW);
			}
		}

		void player1AddScore()
		{
			players[0].scored = true;
			players[1].scored = false;

			players[0].score++;
		}

		void player2AddScore()
		{
			players[1].scored = true;
			players[0].scored = false;

			players[1].score++;
		}
	}
}