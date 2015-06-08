#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    static char buffer[1048576];
    size_t read_bytes = fread(buffer, 1, sizeof(buffer) - 1, stdin);
    printf("%zu\n", read_bytes);
    if (read_bytes < 1) {
        return EXIT_FAILURE;
    }
    GPatternSpec* pattern_spec = g_pattern_spec_new(buffer);
    if (pattern_spec != NULL) {
        g_pattern_spec_free(pattern_spec);
    }
    return EXIT_SUCCESS;
}
