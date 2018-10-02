#ifndef GAME_H
#define GAME_H

#include "raylib.h"

namespace Juego
{
	extern int screenWidth;
	extern int screenHeight;

	extern bool isScreenFinished;

	extern int selectOption;

	extern int defaultFontSize;
	extern int defaultFontSizeGameplayText;
	extern int defaultFontSizeGameplayScore;

	extern Sound pong_hit_wall;
	extern Sound pong_hit_player;
	extern Sound pong_player_scored;
	extern Sound pong_match_end;
	extern Sound pong_select_menu;
	extern Sound pong_select_option1;
	extern Sound pong_select_option2;

	extern Music pong_menu_song;

	void Execute();
}
#endif // GAME_H