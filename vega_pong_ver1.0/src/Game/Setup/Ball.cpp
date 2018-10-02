#include "Setup\Ball.h"

#include "Setup\Game.h"
#include "Setup\Player.h"

namespace Juego
{
	Ball ball;

	namespace Gameplay_Section
	{
		void createBall()
		{
			ball.position = { (float)screenWidth / 2, (float)screenHeight / 2 };
			ball.radio = 10;
			ball.speed = { 500.0f, 0 };
			ball.active = false;
			ball.defaultMultiplier = -1.1f;
			ball.defaultMultiplierHorizontalVertical = -1.0f;
			ball.defaultMultiplierDown = 20.0f;
			ball.defaultMultiplierUp = -20.0f;
		}

		void ballUpdate()
		{
			// Ball movement logic
			if (ball.active)
			{
				ball.position.x += ball.speed.x * GetFrameTime();
				ball.position.y += ball.speed.y * GetFrameTime();
			}
			else
			{
				if (players[0].scored)
				{
					ball.position = { (float)screenWidth / 2 + 20, (float)screenHeight / 2 };
				}
				else if (players[1].scored)
				{
					ball.position = { (float)screenWidth / 2 - 20, (float)screenHeight / 2 };
				}
			}
		}
		void ballDraw()
		{
			DrawCircleV(ball.position, ball.radio, WHITE);
		}

		void ballResetSpeed()
		{
			if (ball.radio == 10)
			{
				if (players[0].scored)
				{
					ball.speed = { 500.0f, 0.0f };
				}
				else
				{
					ball.speed = { -500.0f, 0.0f };
				}				
			}
			else
			{
				if (players[0].scored)
				{
					ball.speed = { 300.0f, 0.0f };
				}
				else
				{
					ball.speed = { -300.0f, 0.0f };
				}
				
			}
		}
	}
}