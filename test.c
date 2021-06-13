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
    
    return EXIT_SUCCESS;
}