/*This function returns a random number between the two parameters.
 *@pre : max and min are int type
 *@post :_
 *@result : A randomly generated number between max min included
 */
int rollDice(int max, int min)
{
    return (rand() % max - min + 1) + min;
}

/* Fill an array wtih random number between 1 and 6 accordind to limit
 *@pre : tab != NULL
 *@post : Tab is filled with limit random numbers between 1 and 6
 *@result :_ 
 */
void rollDices (int tab [], int limit)
{
    int i = 0;
    while (i < limit)
    {
        tab[i] = throwDice(6,1);
        i++;
    }
}