typedef struct Player Player;
struct Player
{
    int number;
    int tokensOwned;
};

void initialiseNumbers(Player players[], int size);
/*Fills the field number of the players. Size indicates how many players are there.*/

#include "players.c"