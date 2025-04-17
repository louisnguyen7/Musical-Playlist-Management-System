#include "../include/givenA3.h"

int playSongGivenId(A3Song *headLL, int givenSongId)
{
    A3Song *temp;
    int i = 0;

    // checking if linked list is empty
    if (headLL == NULL)
    {
        printf("Linked list is empty.\n");
        return -1;
    }

    temp = headLL;  // setting the temp pointer to point at the head of the LL

    // temp pointer is looping through the LL to search for the given song id
    while (temp != NULL)
    {
        if (temp->songId == givenSongId)
        {
            // printing out the song
            printf("Song ID: %d\n", temp->songId);
            printf("Song Name: %s\n", temp->songName);

            printf("Song Notes:\n");
            for (i = 0; i < 21; i++)
            {
                printf("%s ", temp->songNotes[i]);
            }

            return 1;   // returning 1 if found
        }

        temp = temp->nextSong;  // if not found then go to the next song
    }

    return -1;  // if song not found, return -1
}