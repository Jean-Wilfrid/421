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
    n = 4;//
    turns = 1;//
    //welcome(&n);
    Player players[n];
    /*selectFirstPlayer(n);*/
    initialisePlayers(players,n);
    /*announceCharge();
    charging (players,&turns,n,best,worst);*/
    /*players[0].tokensOwned = 5;//
    players[1].tokensOwned = 6;//
    players[2].tokensOwned = 6;//
    players[3].tokensOwned = 4;//
    announceDischarge();
    discharging(players,&turns,n,best,worst);
    announceWinner(best);*/
    int pot = 12;
    best[0] = 1;
    best[1] = 4;
    worst[0] = 2;
    worst[1] = 0;
    players[0].tokensOwned = 14;
    players[1].tokensOwned = 7;
    transferTokensDischarge(best,worst,players);
    announceTokensTransferDischarge(best,worst);
    showRemainingTokens(players,2);
    return EXIT_SUCCESS;
}