/*By Jean-Wilfrid TOGNIBO
 *On June 2021
 *This program is an implementation of the french game 421. 
 *The rules followed to write code this are available here : https://www.regles-de-jeux.com/regle-du-421/ 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "players.h"
#include "display.h"

int main ()
{
    srand(time(NULL));
    int n, turns,best[2], worst [2];
    welcome(&n);
    Player players[n];
    selectFirstPlayer(n);
    initialisePlayers(players,n);
    announceCharge();
    charging (players,&turns,n,best,worst);
    announceDischarge();
    discharging(players,&turns,n,best,worst);
    announceWinner(best); 
    return EXIT_SUCCESS;
}