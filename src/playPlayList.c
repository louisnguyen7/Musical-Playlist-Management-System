#include "../include/givenA3.h"

void playPlayList(A3Song *headLL)
{
    int i = 0;
    A3Song *temp;

    // checking if linked list is empty
    if (headLL == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    // create a temp pointer that points at the beginning of the LL
    temp = headLL;

    // this loop prints all of the songs in the playlist/LL
    while (temp != NULL)
    {
        printf("Song ID: %d\n", temp->songId);
        printf("Song Name: %s\n", temp->songName);
        
        printf("Song Notes:\n");
        for (i = 0; i < 21; i++)
        {
            if (i == 20)
            {
                printf("%s", temp->songNotes[i]);
            }

            else
            {
                printf("%s.", temp->songNotes[i]);
            }
        }

        temp = temp->nextSong;
        
        printf("\n");
    }
}