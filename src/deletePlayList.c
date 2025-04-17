#include "../include/givenA3.h"

void deletePlayList(A3Song **headLL)
{
    A3Song *temp;

    // checking if linked list is empty
    if (*headLL == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    while (*headLL != NULL)
    {
        temp = *headLL;
        *headLL = (*headLL)->nextSong;  // move the head to the next song
        free(temp);     // free the previous song
    }

    free(*headLL);
}