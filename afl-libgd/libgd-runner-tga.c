#include <gd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    gdImagePtr image = NULL;
    image = gdImageCreateFromTga(stdin);
    gdFree(image);

    return EXIT_SUCCESS;
}
