/*Fills the field number of the players. Size indicates how many players are there.
 *@pre : players != NULL, size is a int type
 *@post : The field is initialised for all the players
 *@result : _
 */
void initialisePlayers(Player players[], int size)
{
    int i = 0;
    while(i < size)
    {
        players[i].number = i+1;
        players[i].tokensOwned = 0;
        i++;
    }
}

/*Takes note of the dices a player want to change or not
 *@pre : changes != NULL
 *@post : changes contains 1 for dices to change and 0 for dices to keep 
 *@result : _
 */
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

/*Checks if a player want to make any change
 *@pre : changes != NULL
 *@post : _
 *@result : 1 if at least one cell of changes is equal to 1 0 else
 */
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

/*Checks if the current player has a better combination than the last recorded
 *@pre : best != NULL && player is Player type, associatedTokens is int type
 *@post : A new record is eventually done
 *@result : _
 */
void betterCombination (int best[], Player player, int associatedTokens)
{
    if (best[1] <= associatedTokens)
    {
        best[0] = player.number;
        best[1] = associatedTokens;
    }
}

/*Checks if the current player has a worst combination than the last recorded
 *@pre : worst != NULL && player is Player type, associatedTokens is int type
 *@post : A new record is eventually done
 *@result : _
 */
void worseCombination (int worst[], Player player, int associatedTokens)
{
    if (worst[1] >= associatedTokens)
    {
        worst[0] = player.number;
        worst[1] = associatedTokens;
    }
}

/*Associates a dice roll to the matching number of tokens
 *@pre : dices != NULL
 *@post : _
 *@result : The matching number of tokens
 */
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

/*First play that determines how many rolls a player can do in a row.
 *@pre : players != NULL && turn != NULL && best != NULL && worst != NULL 
 *@post : *turn is set
 *@result : _
 */
void firstTurnToPlay(Player players[], int* turns, int best [], int worst[])
{
    int i = 0,j = 0, dices[3], changes[]= {0,0,0};
    while (j < 3)
    {
        inviteToPlay(players[0].number);
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
    best[0] = 1;
    best[1] = associatedTokens;
    worst[0] = 1;
    worst[1] = associatedTokens;
    *turns =  i+1;
}

/*Second turn. It ends the first row of playing
 *@pre : players != NULL && turn != NULL && best != NULL && worst != NULL && n is a int type
 *@post : The first row is played
 *@result : _
 */
void secondTurnToPlay(Player players[], int* turns, int n, int best [], int worst[])
{
    int i = 1, j = 0, associatedTokens, dices[3], changes[]= {0,0,0};
    while (i < n)
    {
        while (j < *turns)
        {
            inviteToPlay(players[i].number);
            rollDices(dices, 3);
            bullSortDesc(dices,3);
            showDiceRoll(dices, 3);
            if (*turns != 1)
            {
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
            else
            {
                j++;
            }
            
        }
        associatedTokens = associateTokens(dices);
        betterCombination(best, players[i],associatedTokens);
        worseCombination(worst, players[i],associatedTokens);
        i++;
    }
}

/*Makes players play a row for the rest of the game
 *@pre : players != NULL && turn != NULL && best != NULL && worst != NULL && n is a int type
 *@post : A row is played
 *@result : _
 */
void anyTurnToPlay(Player players[], int* turns, int n, int best [], int worst[])
{
    int i = 0, j = 0, associatedTokens, dices[3], changes[]= {0,0,0};
    while (i < n)
    {
        j = 0;
        while (j < *turns)
        {
            inviteToPlay(players[i].number);
            rollDices(dices, 3);
            bullSortDesc(dices,3);
            showDiceRoll(dices, 3);
            if (*turns != 1)
            {
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
            else
            {
                j++;
            }
        }
        associatedTokens = associateTokens(dices);
        betterCombination(best, players[i],associatedTokens);
        worseCombination(worst, players[i],associatedTokens);
        i++;
    }
}

/*Set to 2 the asssociated tokens if the combination is "Nénette"
 *@pre : worst != NULL
 *@post : The value is set
 *@result : _
 */
void nenetteConversion (int worst[])
{
    if (worst[1] == 0)
    {
        worst[1] = 2;
    }
}

/*Transfers tokens from the pot to the matching player
 *@pre : players != NULL, best != NULL, worst != NULL, pot != NULL
 *@post : The tokens are transfered
 *@result : _
 */
void transferTokensCharge(int best[], int worst[], Player players[], int* pot)
{
    nenetteConversion(worst);
    if (*pot > best[1])
    {
        players[worst[0] - 1].tokensOwned += best[1];
        *pot -= best[1];
    }
    else
    {
        players[worst[0] - 1].tokensOwned += *pot;
        *pot = 0;
    }
    
}

/*Transfers tokens between two players. One with the best combination, the other with the worst.
 *@pre : players != NULL, best != NULL, worst != NULL
 *@post : The field is initialised for all the players
 *@result : _
 */
void transferTokensDischarge(int best[], int worst[], Player players[])
{
    nenetteConversion(worst);
    if (players[best[0] - 1].tokensOwned > best[1])
    {
        players[worst[0] - 1].tokensOwned += best[1];
        players[best[0] - 1].tokensOwned -= best[1];
    }
    else
    {
        players[worst[0] - 1].tokensOwned += players[best[0]- 1].tokensOwned;
        players[best[0] - 1].tokensOwned = 0;
    } 
}

/*Selects the first player
 *@pre : n is a int type
 *@post : The player is selected and announced
 *@result : _
 */
void selectFirstPlayer (int n)
{
    inviteToPlay(1);
    int i = 1, max[2], dice = rollDice(6,1);
    showDiceRollS(dice);
    max[0] = 1;
    max[1] = dice;
    while(i < n)
    {
        inviteToPlay(i+1);
        dice = rollDice(6,1);
        showDiceRollS(dice);
        if (dice == 1)
        {
            max[1] = 1;
            max[0] = i+1;
        }
        else
        {
            if (dice > max[1] && max [1] != 1)
            {
                max[1] = dice;
                max[0] = i+1;
            }
        }
        i++;
    }
    announceFirstPlayer(max);
}

/*Runs the charging part of the game
 *@pre : players != NULL && turn != NULL && best != NULL && worst != NULL && n is a int type
 *@post : The whole charging part is ran
 *@result : _
 */
void charging(Player players[], int* turns, int n, int best [], int worst[])
{
    int pot = 21;
    firstTurnToPlay(players,turns,best,worst);
    secondTurnToPlay(players,turns,n,best,worst);
    transferTokensCharge(best,worst,players,&pot);
    announceTokensTransferCharge(best,worst,pot);
    showRemainingTokens(players,n);
    resetReferences(best,worst);
    while (pot > 0)
    {
        anyTurnToPlay(players,turns,n,best,worst);
        transferTokensCharge(best,worst,players,&pot);
        announceTokensTransferCharge(best,worst,pot);
        showRemainingTokens(players,n);
        resetReferences(best,worst);
    }
}

/*Check if there is a Winner
 *@pre : players != NULL, n is a int type
 *@post : _
 *@result : 1 if there is no winner, 0 else
 */
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

/*Sets best and worst to 0
 *@pre : best != NULL, worst != NULL
 *@post : All cells of best and worst are set to 0
 *@result :_
 */
void resetReferences(int best[], int worst[])
{
    for (int i = 0; i < 2; i++)
    {
        best[i] = 0;
        worst[i] = 1;
    }
}

/*Runs the discharging part of the game
 *@pre : players != NULL && turn != NULL && best != NULL && worst != NULL && n is a int type
 *@post : The whole discharging part is ran
 *@result : _
 */
void discharging(Player players[], int* turns, int n, int best [], int worst[])
{
    resetReferences(best,worst);
    while (noWinner(players,n))
    {
        anyTurnToPlay(players,turns,n,best,worst);
        transferTokensDischarge(best,worst,players);
        announceTokensTransferDischarge(best,worst);
        showRemainingTokens(players,n);
    }
}