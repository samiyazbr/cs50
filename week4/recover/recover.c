#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check the argument count is 2
    if (argc != 2)
    {
        printf("no of arguments should be 1\n");
        return 1;
    }

    // open file for reading
    FILE *input_file = fopen(argv[1], "r");

    // check if file can be opened
    if (input_file == NULL)
    {
        printf("couldn't open the  input file\n");
        return 2;
    }

    // store blocks of 512 bytes in an array
    unsigned char buffer[512];

    // track number of images generated
    int count_image = 0;

    // file pointer for recovered image
    FILE *output_file = NULL;

    // char filename[8]
    char *filename = malloc(8 * sizeof(char));

    // read the block of 512 bytes
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        // check if the starting indicated JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (output_file != NULL)
            {
                fclose(output_file); // Close the previous output file
            }

            // write the JPEG filenames
            sprintf(filename, "%03i.jpg", count_image);

            // open output_file for writing
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                fclose(input_file);
                free(filename);
                return 3;
            }

            // count the number of images found
            count_image++;
        }
        // check if output file has been used for valid input
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    // closing opened file
    if (output_file != NULL)
        fclose(output_file);
    free(filename);
    fclose(input_file);

    return 0;
}