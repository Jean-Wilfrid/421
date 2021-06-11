/*Ascendant bull sort
 *@pre : tab != NULL, size is int type
 *@post : tab is sorted
 *@result : _
 */
void bullSortAsc (int tab [], int size)
{
    int i = 0;
    while (i < size-1)
    {
        if (tab[i] > tab [i+1])
        {
            tab[i] = tab[i] + tab[i+1];
            tab[i+1] = tab[i] - tab[i+1];
            tab[i] = tab[i] - tab[i+1];
            i = 0;
            continue;
        }
        i++;
    }
}

/*Descendant bull sort
 *@pre : tab != NULL, size is int type
 *@post : tab is sorted
 *@result : _
 */
void bullSortDesc (int tab [], int size)
{
    int i = 0;
    while (i < size -1)
    {
        if (tab[i] < tab [i+1])
        {
            tab[i] = tab[i] + tab[i+1];
            tab[i+1] = tab[i] - tab[i+1];
            tab[i] = tab[i] - tab[i+1];
            i = 0;
            continue;
        }
        i++;
    }
}