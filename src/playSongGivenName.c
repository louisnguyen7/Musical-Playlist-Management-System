#include "../include/givenA3.h"

int playSongGivenName(A3Song *headLL, char givenSongName[MAX_LENGTH])
{
    A3Song *temp;
    int i = 0;
    char *tempName = NULL;

    // checking if linked list is empty
    if (headLL == NULL)
    {
        printf("Linked list is empty.\n");
        return -1;
    }

    tempName = malloc(sizeof(char) * MAX_LENGTH);

    temp = headLL;  // setting the temp pointer to point at the head of the LL

    // converting all the characters in the string into lowercase
    for (i = 0; i < strlen(givenSongName); i++)
    {
        givenSongName[i] = tolower(givenSongName[i]);
    }

    // temp pointer is looping through the LL to search for the given song id
    while (temp != NULL)
    {
        // storing the song name into a temporary variable so we don't alter the song name in the linked list
        strcpy(tempName, temp->songName);

        // converting all the characters in the temp string into lowercase
        for (i = 0; i < strlen(temp->songName); i++)
        {
            tempName[i] = tolower(tempName[i]);
        }

        if (strcmp(tempName, givenSongName) == 0)
        {
            // printing out the song
            printf("Song ID: %d\n", temp->songId);
            printf("Song Name: %s\n", temp->songName);

            printf("Song Notes:\n");
            for (i = 0; i < 21; i++)
            {
                printf("%s ", temp->songNotes[i]);
            }

            free(tempName);
            return 1;   // returning 1 if found
        }

        temp = temp->nextSong;  // if not found then go to the next song
    }

    free(tempName);
    return -1;  // if song not found, return -1
}