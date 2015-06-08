#include <glib.h>
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
    size_t data_bytes = read_bytes;
    char* buffer_pointer = buffer;

    g_free(g_utf8_strup(buffer_pointer, data_bytes));
    g_free(g_utf8_strdown(buffer_pointer, data_bytes));
    g_free(g_utf8_normalize(buffer_pointer, data_bytes, G_NORMALIZE_DEFAULT));
    g_free(g_utf8_collate_key(buffer_pointer, data_bytes));
    g_free(g_utf8_collate_key_for_filename(buffer_pointer, data_bytes));
    return EXIT_SUCCESS;
}
