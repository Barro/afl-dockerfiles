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
    GBookmarkFile* bookmark_file = g_bookmark_file_new();
    g_bookmark_file_load_from_data(bookmark_file, buffer, read_bytes, NULL);
    g_bookmark_file_free(bookmark_file);
    return EXIT_SUCCESS;
}
