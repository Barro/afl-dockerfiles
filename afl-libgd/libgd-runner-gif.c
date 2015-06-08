#include <gd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    gdImagePtr image = NULL;
    image = gdImageCreateFromGif(stdin);
    gdFree(image);

    return EXIT_SUCCESS;
}
