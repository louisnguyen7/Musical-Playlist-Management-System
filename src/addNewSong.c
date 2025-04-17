#include "../include/givenA3.h"
#include "../include/helper.h"

bool addNewSong(A3Song **headLL, int beginOrEnd)
{
    char *newSongName = NULL;
    A3Song *newSong, *temp;
    char **notes = NULL;
    int i = 0;
    int randNote = 0, generatedId = 0, result = 0;

    // checking if linked list is empty
    if (*headLL == NULL)
    {
        printf("Linked list is empty.\n");
        return false;
    }

    newSongName = malloc(sizeof(char) * 100);
    
    // prompting for song name
    printf("Song Name: ");
    fgets(newSongName, 100, stdin);
    newSongName[strlen(newSongName) - 1] = '\0';
    printf("\n");

    if (!(beginOrEnd >= 1 && beginOrEnd <= 2))
    {
        printf("Invalid beginOrEnd value passed!!.\n"); // validating

        free(newSongName);
        return false;
    }
    
    notes = malloc(sizeof(char *) * 7);     // allocating memory for 7 pointers because there are 7 notes

    // allocate enough memory for each note
    for (i = 0; i < 7; i++)
    {
        notes[i] = malloc(sizeof(char) * NOTE_LENGTH);
    }

    // copy the notes into the allocated string
    strcpy(notes[0], "do");
    strcpy(notes[1], "re");
    strcpy(notes[2], "mi");
    strcpy(notes[3], "fa");
    strcpy(notes[4], "sol");
    strcpy(notes[5], "la");
    strcpy(notes[6], "ti");

    newSong = malloc(sizeof(A3Song));     // allocating memory for new song node

    // adding song to the beginning
    if (beginOrEnd == 1)
    {
        // constructing the new node
        strcpy(newSong->songName, newSongName);

        do
        {
            // generate unique song id with rand() between the range 1 and 1000
            generatedId = (strlen(newSong->songName) + 1) + rand() % 1000 + 1;

            // call helper function to check if new id is unique
            result = checkUniqueId(*headLL, generatedId);
            
        } while (result == -1);

        newSong->songId = generatedId;

        // generating random notes for new song
        for (i = 0; i < 21; i++)
        {
            // randomly generates a number between 0 and 6
            randNote = rand() % 7;
            strcpy(newSong->songNotes[i], notes[randNote]);
        }

        temp = newSong;
        newSong->nextSong = *headLL;    // link the new node to the beginning of the list (where the head is)
        *headLL = temp;     // make head equal to the new node

        printf("Song ID: %d\n", newSong->songId);
        printf("Song Name: %s\n", newSong->songName);

        printf("Notes: ");
        for (i = 0; i < 21; i++)
        {
            printf("%s ", newSong->songNotes[i]);
        }

        printf("\n");

        // freeing all allocated memory
        for (i = 0; i < 7; i++) 
        {
            free(notes[i]);
        }

        free(notes);
        free(newSongName);
        return true;
    }

    // adding song to the end
    else if (beginOrEnd == 2)
    {
        // constructing the new node
        strcpy(newSong->songName, newSongName);

        do
        {
            // generate unique song id with rand() between the range 1 and 1000
            generatedId = (strlen(newSong->songName) + 1) + rand() % 1000 + 1;

            // call helper function to check if new id is unique
            result = checkUniqueId(*headLL, generatedId);
            
        } while (result == -1);

        newSong->songId = generatedId;

        // generating random notes for new song
        for (i = 0; i < 21; i++)
        {
            // randomly generates a number between 0 and 6
            randNote = rand() % 7;
            strcpy(newSong->songNotes[i], notes[randNote]);
        }

        newSong->nextSong = NULL; // set the new node to NULL to indicate end of the LL
        temp = *headLL;
        
        // find the end of the LL using a loop and checking for null
        while (temp->nextSong != NULL)
        {
            temp = temp->nextSong;
        }

        temp->nextSong = newSong; // linking new node to the end of the LL

        printf("Song ID: %d\n", newSong->songId);
        printf("Song Name: %s\n", newSong->songName);

        printf("Notes: ");
        for (i = 0; i < 21; i++)
        {
            printf("%s ", newSong->songNotes[i]);
        }

        printf("\n");

        // freeing all allocated memory
        for (i = 0; i < 7; i++) 
        {
            free(notes[i]);
        }

        free(notes);
        free(newSongName);
        return true;
    }

    // freeing all allocated memory
    for (i = 0; i < 7; i++) 
    {
        free(notes[i]);
    }

    free(notes);
    free(newSongName);
    return false;
}