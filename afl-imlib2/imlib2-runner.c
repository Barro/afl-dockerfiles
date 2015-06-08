// AFL_SKIP_CPUFREQ=true afl-fuzz -i /fuzzdata/input-prefixed/ -o /fuzzdata/output/ -M imlib2-0 -- ./imlib2-runner @@
// docker run -v /dev/shm/imlib2-fuzz/:/fuzzdata -i -t barro/afl-imlib2:1.4.7 /bin/bash

#include <Imlib2.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s imagename\n", argv[0]);
        return EXIT_FAILURE;
    }
    Imlib_Image image = imlib_load_image_immediately_without_cache(argv[1]);
    if (image == NULL) {
        fprintf(stderr, "Unable to load image\n");
        return EXIT_FAILURE;
    }
    const char* filename = imlib_image_get_filename();
    printf("filename: %s\n", filename);
    return EXIT_SUCCESS;
}
