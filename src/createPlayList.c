#include "../include/givenA3.h"
#include "../include/helper.h"

int createPlayList(A3Song **headLL, char fileName[MAX_LENGTH])
{
    FILE *fptr;
    int numSongs = 0;
    A3Song *newNode, *temp;
    char *line = NULL;
    char *token;
    int i = 0;
    int generatedId = 0, result = 0;

    line = malloc(sizeof(char) * 1000);

    fptr = fopen(fileName, "r");

    *headLL = NULL;

    // returning null if file fails to open
    if (fptr == NULL)
    {
        return -1;
    }

    else
    {
        // reading the header and discarding it
        fgets(line, 1000, fptr);

        // reading every line that isn't NULL/empty
        while (fgets(line, 1000, fptr) != NULL)
        {
            // allocating memory for new node
            newNode = malloc(sizeof(A3Song));
            newNode->nextSong = NULL;

            // parse the string separated by commas
            token = strtok(line, ",");

            // when the parsed string reaches a NULL (a comma), then it reaches the end of a song name
            if (token != NULL)
            {
                strcpy(newNode->songName, token);
            }

            // loop for all 21 notes
            for (i = 0; i < 21; i++)
            {
                // parse each note
                token = strtok(NULL, ",");

                if (token != NULL)
                {
                    strcpy(newNode->songNotes[i], token);
                }
            }

            do
            {
                // generate unique song id with rand() between the range 1 and 1000
                generatedId = (strlen(newNode->songName) + 1) + rand() % 1000 + 1;

                // call helper function to check if new id is unique
                result = checkUniqueId(*headLL, generatedId);

            } while (result == -1);

            newNode->songId = generatedId;

            // if the linked list is just being created, we make the head equal to the first node of the LL
            if (*headLL == NULL)
            {
                *headLL = newNode;
            }

            else
            {
                temp = *headLL;

                // adding the node to the end of the list
                while (temp->nextSong != NULL)
                {
                    temp = temp->nextSong;
                }
    
                // linking the existing list to the new node
                temp->nextSong = newNode;
            }

            numSongs++;
        }
    }

    free(line);
    fclose(fptr);
    return numSongs;
}