#include <gd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int main(int argc, char* argv[])
{
    char buffer[1];
    size_t read_size = fread(buffer, 1, 1, stdin);
    if (read_size != 1) {
        fprintf(stderr, "Unable to read even 1 byte from standard input!\n");
        return EXIT_FAILURE;
    }
    char image_type = buffer[0];
    gdImagePtr image = NULL;
    switch (image_type) {
    case 'g':
        image = gdImageCreateFromGif(stdin);
        break;
    case 'd':
        image = gdImageCreateFromGd(stdin);
        break;
    case 'w':
        image = gdImageCreateFromWBMP(stdin);
        break;
    case 'b':
        image = gdImageCreateFromBmp(stdin);
        break;
    case 'x':
        image = gdImageCreateFromXbm(stdin);
        break;
    case 't':
        image = gdImageCreateFromTga(stdin);
        break;
    default:
        fprintf(stderr, "Unknown type: 0x%02x\n", image_type);
        return EXIT_FAILURE;
    }
    gdFree(image);

    return EXIT_SUCCESS;
}
