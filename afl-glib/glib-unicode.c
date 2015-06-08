#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

static char buffer[1048576];

int main()
{
    size_t read_bytes = fread(buffer, 1, sizeof(buffer), stdin);
    printf("%zu\n", read_bytes);
    if (read_bytes < 1) {
        return EXIT_FAILURE;
    }
    size_t data_bytes = read_bytes - 1;
    gchar* buffer_pointer = buffer + 1;
    char type_byte = buffer[0];
    switch (type_byte) {
    case 'a': {
        printf("g_utf8_strlen\n");
        g_utf8_strlen(buffer_pointer, data_bytes);
        break;
    } case 'b': {
        printf("g_utf8_strreverse\n");
        gchar* var = g_utf8_strreverse(buffer_pointer, data_bytes);
        g_free(var);
        break;
    } case 'c': {
        printf("g_utf8_validate\n");
        g_utf8_validate(buffer_pointer, data_bytes, NULL);
        break;
    } case 'd': {
        printf("g_utf8_strup\n");
        gchar* var = g_utf8_strup(buffer_pointer, data_bytes);
        g_free(var);
        break;
    } case 'e': {
        printf("g_utf8_strdown\n");
        gchar* var = g_utf8_strdown(buffer_pointer, data_bytes);
        g_free(var);
        break;
    } case 'f': {
        printf("g_utf8_normalize\n");
        gchar* var = g_utf8_normalize(buffer_pointer, data_bytes, G_NORMALIZE_DEFAULT);
        g_free(var);
        break;
    } case 'g': {
        printf("g_utf8_collate_key\n");
        gchar* var = g_utf8_collate_key(buffer_pointer, data_bytes);
        g_free(var);
        break;
    } case 'h': {
        printf("g_utf8_collate_key_for_filename\n");
        gchar* var = g_utf8_collate_key_for_filename(buffer_pointer, data_bytes);
        g_free(var);
        break;
    } case 'i': {
        printf("g_utf8_to_utf16\n");
        gunichar2* var = g_utf8_to_utf16(buffer_pointer, data_bytes, NULL, NULL, NULL);
        g_free(var);
        break;
    } case 'j': {
        printf("g_utf8_to_ucs4\n");
        gunichar* var = g_utf8_to_ucs4(buffer_pointer, data_bytes, NULL, NULL, NULL);
        g_free(var);
        break;
    } case 'k': {
        printf("g_utf8_to_ucs4_fast\n");
        gunichar* var = g_utf8_to_ucs4_fast(buffer_pointer, data_bytes, NULL);
        g_free(var);
        break;
    } case 'l': {
        printf("g_utf16_to_ucs4\n");
        gunichar* var = g_utf16_to_ucs4((gunichar2*)buffer_pointer, data_bytes / sizeof(gunichar2), NULL, NULL, NULL);
        g_free(var);
        break;
    } case 'm': {
        printf("g_utf16_to_utf8\n");
        gchar* var =g_utf16_to_utf8((gunichar2*)buffer_pointer, data_bytes / sizeof(gunichar2), NULL, NULL, NULL);
        g_free(var);
        break;
    } case 'n': {
        printf("g_ucs4_to_utf8\n");
        gchar* var = g_ucs4_to_utf8((gunichar*)buffer_pointer, data_bytes / sizeof(gunichar), NULL, NULL, NULL);
        g_free(var);
        break;
    } default:
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
