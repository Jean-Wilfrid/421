#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ownRead.h"
#include "sort.h"
#include "dice.h"
#include "players.h"
int main ()
{
    srand(time(NULL));
    int n, turns,best[2], worst [2];
    n = 2;//
    turns = 1;//
    //welcome(&n);
    Player players[n];
    /*selectFirstPlayer(n);*/
    initialisePlayers(players,n);
    /*announceCharge();
    charging (players,&turns,n,best,worst);*/
    players[0].tokensOwned = 14;
    players[1].tokensOwned = 7;
    announceDischarge();
    discharging(players,&turns,n,best,worst);
    announceWinner(best);   
    return EXIT_SUCCESS;
}