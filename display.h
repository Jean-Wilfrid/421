void inviteToPlay(int n);
/*Invite a player to roll the dices*/

void showDiceRoll(int dices[], int size);
/*Shows the dice roll*/

void askToChange(int n, char* answer);
/*Asks a player, if he/she wants to keep or not a dice*/

void welcome (int* n);
/*Welcomes the player and ask how many they are*/

void announceFirstPlayer (int max[]);
/*Announces the first player*/

void announceCharge();
/*Announces the charging*/

void announceDischarge();
/*Announces the discharging*/

void showRemainingTokens (Player players[], int n);
/*Shows the remaining tokens of each player*/

void announceWinner (int best[]);
/*Announces the winner*/

void announceTokensTransferCharge(int best [], int worst[], int pot);
/*Announce tokens transfer during charging*/

void announceTokensTransferDischarge(int best [], int worst[]);
/*Announce tokens transfer during discharging*/

#include "display.c"