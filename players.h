typedef struct Player Player;
struct Player
{
    int number;
    int tokensOwned;
};

void initialiseNumbers(Player players[], int size);
/*Fills the field number of the players. Size indicates how many players are there.*/

void markChanges(int changes[]);
/*Takes note of the dices a player want to change or not*/

int checkChanges (int changes []);
/*Checks if a player want to make any change*/

void betterCombination (int best[], Player player, int associatedTokens);
/*Checks if the current player has a better combination than the last recorded*/

void worseCombination (int worst[], Player player, int associatedTokens);
/*Checks if the current player has a worst combination than the last recorded*/

int associateTokens (int dices[]);
/*Associates a dice roll to the matching number of tokens*/

void firstTurnToPlay(Player players[], int* turns, int best [], int worst[]);
/*First play that determines how many rolls a player can do in a row.*/

void secondTurnToPlay(Player players[], int* turns, int n, int best [], int worst[]);
/*Second turn. It ends the first row of playing*/

void anyTurnToPlay(Player players[], int* turns, int n, int best [], int worst[]);
/*Makes players play a row for the rest of the game*/

void nenetteConversion (int worst[]);
/*Set to 2 the asssociated tokens if the combination is "Nénette"*/

void transferTokensCharge(int best[], int worst[], Player players[], int* pot);
/*Transfers tokens from the pot to the matching player*/

void transferTokensDischarge(int best[], int worst[], Player players[]);
/*Transfers tokens between two players. One with the best combination, the other with the worst.*/

void selectFirstPlayer (int n);
/*Selects the first player*/

void charging(Player players[], int* turns, int n, int best [], int worst[]);
/*Runs the charging part of the game*/

int noWinner(Player players[], int n);
/*Check if there is a Winner*/

void resetReferences(int best[], int worst[]);
/*Sets best and worst to 0*/

void discharging(Player players[], int* turns, int n, int best [], int worst[]);
/*Runs the discharging part of the game*/

#include "players.c"