#include "../include/givenA3.h"

int countNotesInASong(A3Song *headLL, int givenSongId, char whichNote[4])
{
    A3Song *temp;
    int i = 0;
    int numNotes = 0;
    char **notes = NULL;

    // checking if linked list is empty
    if (headLL == NULL)
    {
        printf("Linked list is empty.\n");
        return -1;
    }

    // allocating memory for 7 pointers
    notes = malloc(sizeof(char *) * 7);

    // allocate enough memory for each note
    for (i = 0; i < 7; i++)
    {
        notes[i] = malloc(sizeof(char) * NOTE_LENGTH);
    }

    strcpy(notes[0], "do");
    strcpy(notes[1], "re");
    strcpy(notes[2], "mi");
    strcpy(notes[3], "fa");
    strcpy(notes[4], "sol");
    strcpy(notes[5], "la");
    strcpy(notes[6], "ti");

    // validating the song note
    for (i = 0 ; i < 7; i ++)
    {
        // if the note is correct, then break out of the loop
        if (strcmp(whichNote, notes[i]) == 0)
        {
            break;
        }

        else
        {
            if (i == 6) // this ensures that the loop runs for all 7 notes before breaking too early
            {
                // freeing all allocated memory
                for (i = 0; i < 7; i++) 
                {
                    free(notes[i]);
                }

                free(notes);
                return -1;  // returning -1 if the given note is invalid
            }
        }
    }

    temp = headLL;  // setting the temp pointer to point at the head of the LL

    // temp pointer is looping through the LL to search for the given song id
    while (temp != NULL)
    {
        if (temp->songId == givenSongId)
        {
            for (i = 0; i < 21; i++)
            {
                temp->songNotes[i][NOTE_LENGTH - 1] = '\0'; // null terminating the notes so strcmp doesn't read out of bounds

                if (strcmp(temp->songNotes[i], whichNote) == 0)
                {
                    numNotes++; // incrementing the number of occurrences of a note in the given song id
                }
            }

            // freeing all allocated memory
            for (i = 0; i < 7; i++) 
            {
                free(notes[i]);
            }

            free(notes);
            return numNotes;   // returning number of notes
        }

        temp = temp->nextSong;  // if not found then go to the next song
    }

    // freeing all allocated memory
    for (i = 0; i < 7; i++) 
    {
        free(notes[i]);
    }

    free(notes);
    return -1;  // if song not found, return -1
}