// GAME MECHANICS !!!
#include "game.h"

using namespace std;

int main ()
{
	srand(time(NULL));
	menu();
	while(!player_death)
	{
		game();
	}
	return 0;
}
