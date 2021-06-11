/*Fills the field number of the players. Size indicates how many players are there.
 *@pre : players != NULL, size is a int type
 *@post : The field is initialised for all the players
 *@result : _
 */
void initialiseNumbers(Player players[], int size)
{
    int i = 0;
    while(i < size)
    {
        players[i].number = i+1;
        i++;
    }
}

void markChanges(int changes[])
{
    int j=0;
    char answer[2];
    while (j<3)
    {
        askToChange(j+1, answer);
        if(answer[0] == 'y')
        {
            changes[j] = 1;
        }
        j++;
    }
}

int checkChanges (int changes [])
{
    int i = 0;
    while (i<3)
    {
        if (changes[i] == 1)
        {
            return 1;
        }
        i++;
    }
    return 0;

}

void betterCombination (int best[], Player player, int associatedTokens)
{
    if (best[1] <= associatedTokens)
    {
        best[0] = player.number;
        best[1] = associatedTokens;
    }

}

void worseCombination (int worst[], Player player, int associatedTokens)
{
    if (worst[1] >= associatedTokens)
    {
        worst[0] = player.number;
        worst[1] = associatedTokens;
    }

}

int associateTokens (int dices[])
{
    switch (dices[0])
    {
    case 1:
        return 7;
        break;
    case 2:
        if (dices[1] == 2)
        {
            if (dices[2] == 1)
            {
                return 0;
            }
            else
            {
                return 2;
            }
        }
        else if (dices[1] == 1)
        {
            return 2;
        }
        break;
    case 3:
        if (dices[1] == 3 && dices[2] == 3)
        {
            return 3;
        }
        else if (dices[1] == 2 && dices[2] == 1)
        {
            return 2;
        }
        else if (dices[1] == 1 && dices[1] == 1)
        {
            return 3;
        }
        else
        {
            return 1;
        }
        break;
    case 4:
        if (dices[1] == 4 && dices[2] == 4)
        {
            return 4;
        }
        else if (dices[1] == 2 && dices[2] == 1)
        {
            return 10;
        }
        
        else if (dices[1] == 3 && dices[2] == 2)
        {
            return 2;
        }
        else if (dices[1] == 1 && dices[1] == 1)
        {
            return 4;
        }
        else
        {
            return 1;
        }
        break;
    case 5:
        if (dices[1] == 5 && dices[2] == 5)
        {
            return 5;
        }
        else if (dices[1] == 4 && dices[2] == 3)
        {
            return 2;
        }
        else if (dices[1] == 1 && dices[1] == 1)
        {
            return 5;
        }
        else
        {
            return 1;
        }
        break;
    case 6:
        if (dices[1] == 6 && dices[2] == 6)
        {
            return 3;
        }
        else if (dices[1] == 5 && dices[2] == 4)
        {
            return 2;
        }
        else if (dices[1] == 1 && dices[1] == 1)
        {
            return 5;
        }
        else
        {
            return 1;
        }
        break;
    }
}

void firstTurnToPlay(Player players[], int* turns, int best [], int worst[])
{
    int i = 0,j = 0, dices[3], changes[]= {0,0,0};
    while (j < 3)
    {
        inviteToPlay(players[0]);
        rollDices(dices,3);
        bullSortDesc(dices,3);
        showDiceRoll(dices,3);
        markChanges(changes);
        if(checkChanges(changes))
        {
            i++;
        }
        else
        {
            break;
        }
        j++;
    }
    int associatedTokens = associateTokens(dices);
    best[0] = 0;
    best[1] = associatedTokens;
    worst[0] = 0;
    worst[1] = associatedTokens;
    *turns =  i+1;
}

void secondTurnToPlay(Player players[], int* turns, int n, int best [], int worst[])
{
    int i = 1, j = 0, associatedTokens, dices[3], changes[]= {0,0,0};
    while (i < n)
    {
        while (j < *turns)
        {
            inviteToPlay(players[i]);
            rollDices(dices, 3);
            bullSortDesc(dices,3);
            showDiceRoll(dices, 3);
            markChanges(changes);
            if(checkChanges(changes))
            {
                j++;
            }
            else
            {
                break;
            }
        }
        associatedTokens = associateTokens(dices);
        betterCombination(best, players[i],associatedTokens);
        worseCombination(worst, players[i],associatedTokens);
        i++;
    }
}

void anyTurnToPlay(Player players[], int* turns, int n, int best [], int worst[])
{
    int i = 0, j = 0, associatedTokens, dices[3], changes[]= {0,0,0};
    while (i < n)
    {
        while (j < *turns)
        {
            inviteToPlay(players[i]);
            rollDices(dices, 3);
            bullSortDesc(dices,3);
            showDiceRoll(dices, 3);
            markChanges(changes);
            if(checkChanges(changes))
            {
                j++;
            }
            else
            {
                break;
            }
        }
        associatedTokens = associateTokens(dices);
        betterCombination(best, players[i],associatedTokens);
        worseCombination(worst, players[i],associatedTokens);
        i++;
    }
}



void nenetteConversion (int worst[])
{
    if (worst[1] == 0)
    {
        worst[1] = 2;
    }
}

void transferTokensCharge(int best[], int worst[], Player players[], int* pot)
{
    nenetteConversion(worst);
    if (*pot > best[1])
    {
        players[worst[0]].tokensOwned += best[1];
    }
    else
    {
        players[worst[0]].tokensOwned += *pot;
    }
    
}

void transferTokensDischarge(int best[], int worst[], Player players[])
{
    nenetteConversion(worst);
    if (players[best[0]].tokensOwned > best[1])
    {
        players[worst[0]].tokensOwned += best[1];
        players[best[0]].tokensOwned -= best[1];
    }
    else
    {
        players[worst[0]].tokensOwned += players[best[0]].tokensOwned;
        players[best[0]].tokensOwned = 0;
    } 
}

void selectFirstPlayer (int n)
{
    inviteToPlayB(1);
    int i = 1, max[2], dice = rollDice(6,1);
    max[0] = 0;
    max[1] = dice;
    while(i < n)
    {
        inviteToPlayB(i+1);
        dice = rollDice(6,1);
        if (dice == 1)
        {
            max[1] = 1;
            max[0] = i;
        }
        else
        {
            if (dice > max[1])
            {
                max[1] = dice;
                max[0] = i;
            }
        }
        i++;
    }
    announceFirstPlayer(max);
}

void charging(Player players[], int* turns, int n, int best [], int worst[])
{
    int pot = 21;
    firstTurnToPlay(players,turns,best,worst);
    secondTurnToPlay(players,turns,n,best,worst);
    transferTokensCharge(best,worst,players,&pot);
    showRemainingTokens(players,n);
    while (pot > 0)
    {
        anyTurnToPlay(players,turns,n,best,worst);
        transferTokensCharge(best,worst,players,&pot);
        showRemainingTokens(players,n);
    }
}

int noWinner(Player players[], int n)
{
    int i = 0;
    while (i < n)
    {
        if (players[i].tokensOwned == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void discharging(Player players[], int* turns, int n, int best [], int worst[])
{
    while (noWinner(players,n))
    {
        anyTurnToPlay(players,turns,n,best,worst);
        transferTokensDischarge(best,worst,players);
        showRemainingTokens(players,n);
    }
}