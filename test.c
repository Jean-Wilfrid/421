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
    int changes[3];
    markChanges(changes);
    for (int i = 0; i < 3; i++)
    {
      printf("%d ", changes[i]);
    }
    printf("\n");
    
    return EXIT_SUCCESS;
}