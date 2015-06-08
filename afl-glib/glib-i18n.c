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
    gchar** variants = g_get_locale_variants(buffer);
    if (variants != NULL) {
        g_strfreev(variants);
    }
    return EXIT_SUCCESS;
}
