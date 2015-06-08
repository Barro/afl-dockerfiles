#include <pcre.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    static char buffer[1048576];
    size_t read_bytes = fread(buffer, 1, sizeof(buffer) - 1, stdin);
    printf("%zu\n", read_bytes);
    if (read_bytes < 1) {
        return EXIT_FAILURE;
    }

    const char* error;
    int error_offset;

    pcre* compiled = pcre_compile(
        buffer,
        0,
        &error,
        &error_offset,
        NULL);
    if (compiled != NULL) {
        
    }
    return EXIT_SUCCESS;
}
