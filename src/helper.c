#include "../include/givenA3.h"
#include "../include/helper.h"

int checkUniqueId(A3Song *headLL, int generatedId)
{
    A3Song *temp;

    temp = headLL;

    while (temp != NULL)
    {
        if (temp->songId == generatedId)
        {
            return -1;  // if id is not unique, return -1
        }

        temp = temp->nextSong;
    }

    return 1;   // if id is unique, return 1
}