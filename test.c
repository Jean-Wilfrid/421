#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "players.h"
#include "ownRead.h"
#include "display.h"
int main ()
{
    srand(time(NULL));
    int n, turns,best[2], worst [2];
    welcome(&n);
    Player players[n];
    selectFirstPlayer(n);
    announceCharge();
    charging (players,&turns,n,best,worst);
    announceDischarge();
    discharging(players,&turns,n,best,worst);
    announceWinner(best);
    return EXIT_SUCCESS;
}