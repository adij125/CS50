#include "stdio.h"
#include "stdlib.h"
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc > 2)
    {
        printf("./recover (file name)");

        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {

        printf("Incorrect file type, file cannot be opened");

        return 1;
    }

    // BYTE (*buffer)[512]=calloc(1000,512*sizeof(BYTE));
    BYTE buffer[512];

    BYTE size = 1;

    char jpeg[9];
    int count = 0;
    int start = 0;

    int file_name = 0;

    FILE *outptr = fopen("000.jpg", "w");
    while (fread(&buffer, size, 512, file) == 512)
    {

        count++;
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] / 0x10) == 0xe)
        {

            if (start == 0)
            {
                start = 1;
            }
            else
            {
                file_name++;
                fclose(outptr);
                if (file_name < 10)
                {
                    sprintf(jpeg, "00%i.jpg", file_name);
                }
                else if (file_name < 100)
                {

                    sprintf(jpeg, "0%i.jpg", file_name);
                }
                else
                {
                    sprintf(jpeg, "%i.jpg", file_name);
                }
                outptr = fopen(jpeg, "w");
            }
        }

        if (start == 1)
        {
            fwrite(&buffer, size, 512, outptr);
        }
    }

    fclose(file);

    fclose(outptr);

    // free(buffer);
}