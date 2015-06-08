#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

static char buffer[1048576];

int main()
{
    size_t read_bytes = fread(buffer, 1, sizeof(buffer) - 1, stdin);
    printf("%zu\n", read_bytes);
    if (read_bytes < 1) {
        return EXIT_FAILURE;
    }
    GRegex* regex = g_regex_new(buffer, G_REGEX_RAW, 0, NULL);
    if (regex == NULL) {
        return EXIT_FAILURE;
    }
    g_regex_unref(regex);
    return EXIT_SUCCESS;
}
