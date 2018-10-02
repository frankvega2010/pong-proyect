#include "gameplay.h"

#include "Setup\Game.h"
#include "Setup\Player.h"
#include "Setup\Ball.h"

namespace Juego
{
	int scoreLimit;
	static bool gameON;
	static int maxAngle = -600;
	static float ballMaxSpeed = 2200.0f;

	namespace Gameplay_Section
	{
		static void GameplayInput()
		{
			// Ball launching logic
			if (!ball.active)
			{
				if (IsKeyPressed(KEY_SPACE))
				{
						ball.active = true;
				}
			}

			// Player Movement
			playerInput();
		}

		void InitGameplayVariables()
		{
			// Round Variables
			scoreLimit = 5;
			gameON = true;

			createBall();

			createPlayer();

			createMiddleLine();
		}

		void UpdateGameplayScreen()
		{
			//---------- Input
			GameplayInput();

			// Score Limit
			for (int i = 0; i < maxplayers; i++)
			{
				if (players[i].score >= scoreLimit)
				{
					#ifdef AUDIO
					PlaySound(pong_match_end);
					#endif
					isScreenFinished = true;
					return;
				}
			}

			playerUpdate();

			ballUpdate();


			// Collision logic: ball vs vertical walls FOR BOTH PLAYERS
			if ((ball.position.x + ball.radio) >= screenWidth && ball.active)
			{
			#ifdef AUDIO
				PlaySound(pong_player_scored);
			#endif

				ball.active = false;

				player1AddScore();

				ballResetSpeed();
			}
			else if ((ball.position.x + ball.radio) <= 0 && ball.active)
			{
			#ifdef AUDIO
				PlaySound(pong_player_scored);
			#endif

				ball.active = false;

				player2AddScore();

				ballResetSpeed();
			}

			// Collision logic: ball vs horizontal walls
			if ((ball.position.y - ball.radio) <= 0)
			{
				#ifdef AUDIO
								PlaySound(pong_hit_wall);
				#endif

				ball.position.y = 0 + ball.radio;
				ball.speed.y *= ball.defaultMultiplierHorizontalVertical;
			}
			if ((ball.position.y + ball.radio) >= screenHeight)
			{
				#ifdef AUDIO
								PlaySound(pong_hit_wall);
				#endif
				ball.position.y = screenHeight - ball.radio;
				ball.speed.y *= ball.defaultMultiplierHorizontalVertical;
			}

			// PLAYER VS BALL COLLISION ----------------------------------------------------------------------------------------------
			//////////////////////////////////////////////////////--------------------------------------------------------------------
			for (int i = 0; i < maxplayers; i++)
			{
				if (CheckCollisionCircleRec(ball.position, ball.radio, { players[i].position.x, players[i].position.y, players[i].size.x, players[i].size.y }))
				{
					if (ball.speed.x < 0 || ball.speed.x > 0)
					{
						#ifdef AUDIO
						PlaySound(pong_hit_player);
						#endif
						if (ball.position.x - ball.radio < players[0].position.x + players[0].size.x)
						{
							ball.position.x = players[0].position.x + players[0].size.x + ball.radio;
						}
						if (ball.position.x + ball.radio > players[1].position.x)
						{
							ball.position.x = players[1].position.x - ball.radio;
						}

						if (ball.speed.x >= ballMaxSpeed)
						{
							ball.speed.x = ballMaxSpeed * (-1);
						}
						else if (ball.speed.x <= -(ballMaxSpeed))
						{
							ball.speed.x = -(ballMaxSpeed) * (-1);
						}
						else
						{
							ball.speed.x *= -1.1;
						}				
						ball.speed.y = ((players[i].position.y + players[i].size.y / 2) - ball.position.y) / (players[i].size.y / 2) * (maxAngle);
						
					}
				}

			}
		}

		void InitGameplayScreen()
		{
			isScreenFinished = false;
		}

		bool FinishGameplayScreen()
		{
			return isScreenFinished;
		}

		void RestartPhase()
		{
			ball.active = false;
			gameON = true;

			for (int i = 0; i < maxplayers; i++)
			{
				players[i].score = 0;
			}

			ball.position = { (float)screenWidth / 2, (float)screenHeight / 2 };
			players[0].position.y = screenHeight / 2;
			players[1].position.y = screenHeight / 2;
		}

		void DrawGameplay()
		{
			playerDraw();
			ballDraw();

			if (!ball.active)
			{
				if (gameON)
				{
					DrawText("Press", screenWidth / 2 - 280, screenHeight / 4, defaultFontSizeGameplayText, RED); // default 380 300
					DrawText("'SPACEBAR' to begin!", screenWidth / 2 + 20, screenHeight / 4, defaultFontSizeGameplayText, RED);
				}
			}

			//Draw Score
			for (int i = 0; i < maxplayers; i++)
			{
				DrawText(FormatText("%i", players[i].score), players[i].scorePositionX, screenHeight / 80, defaultFontSizeGameplayScore, WHITE);			
			}
		}
	}
}