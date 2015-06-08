#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char input[] = "\314";
    gchar* reversed = g_utf8_strreverse(input, sizeof(input) - 1);
    printf("%p\n", reversed);
    g_free(reversed);
    return EXIT_SUCCESS;
}
