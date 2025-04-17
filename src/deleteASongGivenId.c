#include "../include/givenA3.h"

int deleteASongGivenId(A3Song **headLL, int givenSongId)
{
    A3Song *temp, *deleteSong, *linkPtr;
    int count = 0;

    // checking if linked list is empty
    if (*headLL == NULL)
    {
        printf("Linked list is empty.\n");
        return -1;
    }

    temp = *headLL;
    linkPtr = temp;

    // pointer is looping through the LL to search for the given song id
    while (temp != NULL)
    {
        if (temp->songId == givenSongId)
        {   
            // special case: if the song deleted is the head of the LL
            if (temp == *headLL)
            {
                // moving the head to the next song of the LL
                *headLL = (*headLL)->nextSong;
                deleteSong = temp;
                free(deleteSong);   // deleting the song

                return 1;   // returning 1 if found
            }

            else
            {
                deleteSong = temp;
                temp = temp->nextSong;  // temp now points at the node after the deleted node
                free(deleteSong);   // deleting the song given id
    
                // linking the list together with linkPtr which points at the previous node of the deleted song
                linkPtr->nextSong = temp;

                return 1;   // returning 1 if found
            }
        }

        temp = temp->nextSong;  // if not found then go to the next song

        // this if statement will allow us to track the previous node of whatever node tmep is pointing at
        if (count != 0)
        {
            linkPtr = linkPtr->nextSong;
        }

        count++;
    }

    return -1;  // if song not found, return -1
}