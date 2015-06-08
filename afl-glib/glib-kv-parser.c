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
    GKeyFile* keyfile = g_key_file_new();
    g_key_file_load_from_data(keyfile, buffer, read_bytes, G_KEY_FILE_NONE, NULL);
    g_key_file_free(keyfile);
    return EXIT_SUCCESS;
}
