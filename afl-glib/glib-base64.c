#include <glib.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "");
    static char buffer[1048576];
    size_t read_bytes = fread(buffer, 1, sizeof(buffer) - 1, stdin);
    printf("%zu\n", read_bytes);
    if (read_bytes < 1) {
        return EXIT_FAILURE;
    }

    gsize out_len = 0;
    guchar* decoded = g_base64_decode(buffer, &out_len);
    if (decoded != NULL) {
        g_free(decoded);
    }

    return EXIT_SUCCESS;
}
