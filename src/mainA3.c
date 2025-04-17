#include "../include/givenA3.h"

int main(int argc, char *argv[])
{
    int choice = 0;
    bool isDigit;
    char *input = NULL, *givenSongName = NULL, *whichNote = NULL, *fileName = NULL;
    int numSongs = 0, numNotes = 0;
    int beginOrEnd = 0;
    A3Song *headLL;
    int givenSongId = 0, songFound = 0, deletedResult = 0;
    int i = 0, notDigit = 0, LL = 0;

    // used to seed the random number generator rand()
    srand(time(NULL));

    // allocating memory for user input
    input = malloc(sizeof(char) * 100);
    givenSongName = malloc(sizeof(char) * MAX_LENGTH);
    whichNote = malloc(sizeof(char) * NOTE_LENGTH);
    fileName = malloc(sizeof(char) * MAX_LENGTH);

    do
    {
        printf("======================================================\n");
        printf("1. Create a new playlist\n");
        printf("2. Add a new song to an existing playlist\n");
        printf("3. Play all songs in the given playlist\n");
        printf("4. Play a song from the playlist, given its id\n");
        printf("5. Play a song from the playlist, given its name\n");
        printf("6. Count the number of occurrences of a note in a given song\n");
        printf("7. Delete a song from the playlist, given its id\n");
        printf("8. Delete the entire playlist\n");
        printf("9. Exit\n");
        printf("======================================================\n");
        printf("Enter your choice: ");
        fgets(input, 100, stdin);
        input[strlen(input) - 1] = '\0';

        notDigit = 0;
        choice = 0;
        for (i = 0; i < strlen(input); i++)
        {
            // using isdigit() function to test if the input is an integer or a string/char
            isDigit = isdigit(input[i]);

            // isdigit() returns false (or 0) if the input is a string/char, returns 1 otherwise
            if (isDigit == 0)
            {
                notDigit++;
            }

            // this makes sure the loop goes through the entire string without breaking out of the loop too early
            if (isDigit == 1 && i == strlen(input) - 1 && notDigit == 0)
            {
                // using sscanf to get the integer from input
                sscanf(input, "%d", &choice);

                if (!(choice >= 1 && choice <= 8) && choice != 9)
                {
                    printf("Invalid Choice!!\n");
                }

                else
                {
                    break;  // breaking out of the loop if the choice is correct
                }
            }

            else if (notDigit > 0 && i == strlen(input) - 1)
            {
                printf("Invalid Type!!\n");
            }
        }

        // menu choices
        switch(choice)
        {
            case 1:
                strcpy(fileName, "MusicalTunes.csv");

                // call function (task 1)
                numSongs = createPlayList(&headLL, fileName);
                printf("Number of songs in the playlist: %d\n", numSongs);
                printf("\n");
                break;
            case 2:
                printf("Enter the value for beginOrEnd: ");
                scanf("%d", &beginOrEnd);
                getchar();  // removing new line character from scanf

                // call function (task 2)
                LL = addNewSong(&headLL, beginOrEnd);

                if (beginOrEnd == 1 && LL != false)
                {
                    printf("\n");
                    printf("Song added at the beginning!\n");
                }

                else if (beginOrEnd == 2 && LL != false)
                {
                    printf("\n");
                    printf("Song added at the end!\n");
                }

                printf("\n");
                break;
            case 3:
                // call function (task 3)
                playPlayList(headLL);
                printf("\n");
                break;
            case 4:
                printf("Enter the id of the song you want to play: ");
                scanf("%d", &givenSongId);
                getchar();

                // call function (task 4)
                printf("\n");
                songFound = playSongGivenId(headLL, givenSongId);

                if (songFound == -1)
                {
                    printf("No song found!!");
                }

                printf("\n\n");
                break;
            case 5:
                printf("Enter the name of the song you want to play: ");
                fgets(givenSongName, MAX_LENGTH, stdin);
                givenSongName[strlen(givenSongName) - 1] = '\0';    // removing new line character

                // call function (task 5)
                printf("\n");
                songFound = playSongGivenName(headLL, givenSongName);

                if (songFound == -1)
                {
                    printf("No song found!!");
                }

                printf("\n\n");
                break;
            case 6:
                printf("Enter the id of the song you want to count the notes in: ");
                scanf("%d", &givenSongId);
                getchar();
                
                printf("Enter the note you want to count: ");
                scanf("%s", whichNote);
                getchar();

                // call function (task 6)
                numNotes = countNotesInASong(headLL, givenSongId, whichNote);
                printf("\n");

                if (numNotes == -1)
                {
                    printf("Song not found!!\n");
                }
                
                else
                {
                    printf("Number of times the note appears: %d\n", numNotes);
                }

                printf("\n");
                break;
            case 7:
                printf("Enter the id of the song you want to delete: ");
                scanf("%d", &givenSongId);
                getchar();

                // call function (task 7)
                deletedResult = deleteASongGivenId(&headLL, givenSongId);
                printf("\n");

                if (deletedResult == -1)
                {
                    printf("Song not found!!\n");
                }

                else
                {
                    printf("Song Deleted!!\n");
                }

                printf("\n");
                break;
            case 8:
                // call function (task 8)
                deletePlayList(&headLL);
                printf("\n");
                printf("Deleting Playlist ♫♫♫\n");
                printf("\n");
                break;
            case 9:
                printf("\n");
                printf("♫ Exiting the program ♫\n");
                printf("\n");
                break;
        }

    } while (choice != 9);

    free(givenSongName);
    free(input);
    free(whichNote);
    free(fileName);
    return 0;
}