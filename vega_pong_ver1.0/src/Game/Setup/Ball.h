#ifndef BALL_H
#define BALL_H

#include "raylib.h"

namespace Juego
{
	struct Ball {
		Vector2 position;
		Vector2 speed;
		int radio;
		bool active;
		float defaultMultiplier;
		float defaultMultiplierHorizontalVertical;
		float defaultMultiplierDown;
		float defaultMultiplierUp;
	};

	extern Ball ball;

	namespace Gameplay_Section
	{
		void createBall();
		void ballUpdate();
		void ballDraw();
		void ballResetSpeed();
	}
}
#endif // BALL_H
