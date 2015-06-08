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
    gchar* str_hostname_to_ascii = g_hostname_to_ascii(buffer);
    if (str_hostname_to_ascii != NULL) {
        g_free(str_hostname_to_ascii);
    }
    gchar* str_hostname_to_unicode = g_hostname_to_unicode(buffer);
    if (str_hostname_to_unicode != NULL) {
        g_free(str_hostname_to_unicode);
    }
    g_hostname_is_non_ascii(buffer);
    g_hostname_is_ascii_encoded(buffer);
    g_hostname_is_ip_address(buffer);
    return EXIT_SUCCESS;
}
