/*This function returns a random number between the two parameters.
 *@pre : max and min are int type
 *@post :_
 *@result : A randomly generated number between max min included
 */
int rollDice(int max, int min)
{
    return (rand() % max - min + 1) + min;
}

/*Fill an array wtih random number between 1 and 6 using another array.
 *@pre : tab != NULL
 *@post : Tab is filled with random numbers between 1 and 6 depending on cells of tab2
 *@result :_ 
 */
void rollDices (int tab [],int tab2[], int limit)
{
    int i = 0;
    while (i < limit)
    {
        if (tab2[i] == 1)
        {
            tab[i] = rollDice(6,1);
        }
        i++;
    }
}