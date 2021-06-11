/*Invite a player to roll the dices
 *@pre : player is Player type
 *@post : A text is displayed inviting the player to roll the dices
 *@result_ 
 */
void inviteToPlay(Player player)
{
    char r[2];
    printf("Player %d, it's your turn. Press enter twice to roll the dices.\n", player.number);
    read(r,2);
    read(r,2);
}

/*Invite a player to roll the dices
 *@pre : n is int type
 *@post : A text is displayed inviting the player to roll the dices
 *@result_ 
 */
void inviteToPlayB(int n)
{
    char r[2];
    printf("Player %d, it's your turn. Press enter twice to roll the dices.\n",n);
    read(r,2);
    read(r,2);
}

/*Shows the dice roll
 *@pre : dices != NULL && size is int type
 *@post : The dice roll is shown using at most size elements in dices  
 *@result_ 
 */
void showDiceRoll(int dices[], int size)
{
    int i = 0;
    printf("Here's your draw : ");
    while (i < size)
    {
        printf("%d ", dices[i]);
        i++;
    }   
}

/*Asks a player, if he/she wants to keep or not a dice
 *@pre : n is int type && answer != NULL
 *@post : A text is displayed asking question to the player
 *@result_ 
 */
void askToChange(int n, char* answer)
{
    printf("Do you want to roll again dice %d ?\nType :\n y for yes\nn for no\n",n);
    read(answer,2);
}

/*Welcomes the player and ask how many they are
 *@pre : n != NULL
 *@post : A text is displayed asking question. In case of mistakes, players will be invite to enter the number again.
 *@result_ 
 */
void welcome (int* n)
{
    printf ("Welcome to 421 !!!\nHow many are you ? ");
    scanf("%d",n);
    while (*n < 2 || *n > 4)
    {
        printf("You should be at least 2 and at most 4 players.\nPlease enter your number again.\n");
        scanf("%d",n);
    }
}

/*Announces the first player
 *@pre : max != NULL
 *@post : A text is displayed announcing the first player
 *@result_ 
 */
void announceFirstPlayer (int max[])
{
    printf("The best score is %d, made by player %d.\nDuring the game, player %d will be the player 1.\n", max[0], max[1], max[1]);
}

/*Announces the charging
 *@pre :_
 *@post : A text is displayed announcing the charging
 *@result_ 
 */
void announceCharge()
{
    printf("\n\n\nLet's Charge !!!!!\n\n\n");
}

/*Announces the discharging
 *@pre :_
 *@post : A text is displayed announcing the discharging
 *@result_ 
 */
void announceDischarge()
{
    printf("\n\n\nCharging is over...\n\nWho will be the first with no more tokens ???\n\n\n");
}

/*Shows the remaining tokens of each player
 *@pre : players != NULL && n is int type
 *@post : A text is displayed showing the tokens
 *@result_ 
 */
void showRemainingTokens (Player players[], int n)
{
    int i = 0;
    while (i < n)
    {
        printf("Player %d, you now have %d tokens.",players[i].number, players[i].tokensOwned);
        i++;
    }
}

/*Announces the winner
 *@pre : best != NULL
 *@post : A text is displayed announcing the winner
 *@result_ 
 */
void announceWinner (int best[])
{
 printf ("We have a Wiiiiiiiiiinnnnnnnnnnnnnnnnnneeeeeeeeeeeeeeeerrrrr !!!!!!!\n\nAnd the winner is \n\nPlayer %d", best[0]);
}
