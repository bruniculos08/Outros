#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#define BUFFER_SIZE 512
typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    if (argc!=2)
    {
        printf("Usage: recover imagename.jpg\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {

        printf("Could not Load\n");
        return 1;

    }

    BYTE buffer[BUFFER_SIZE];

    int file_count=0;

    FILE *image = NULL;

    int found = 0;

    while (fread(buffer, BUFFER_SIZE, 1, card) == 1) //while true is not the end of the file
    {
        //new image
        if (buffer[0]==0xff & buffer[1]==0xd8 & buffer[2]==0xff & (buffer[3] & 0xf0)==0xe0)
        {
            if (found == 1)
            {
                // found the start of a new pic so close out current image
                fclose(image);
            }
            else
            {
                // jpg founded and now we have the permit to write
                found = 1;
            }

            char filename[8];

            sprintf(filename, "%03i.jpg", file_count);

            image = fopen(filename, "w");

            file_count++;
        }

        if (found == 1)
        {
            fwrite(&buffer, 1, 512, image);
        }
    }

    fclose(card);
    fclose(image);

    return 0;
}
