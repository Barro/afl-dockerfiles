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

    char* str_uri_parse_scheme = g_uri_parse_scheme(buffer);
    if (str_uri_parse_scheme != NULL) {
        free(str_uri_parse_scheme);
    }
    char* str_uri_escape_string = g_uri_escape_string(buffer, NULL, TRUE);
    if (str_uri_escape_string != NULL) {
        free(str_uri_escape_string);
    }
    char* str_uri_unescape_string = g_uri_unescape_string(buffer, NULL);
    if (str_uri_unescape_string != NULL) {
        free(str_uri_unescape_string);
    }
    char* segment_end = buffer + read_bytes;
    char* str_uri_unescape_segment = g_uri_unescape_segment(buffer, segment_end, NULL);
    if (str_uri_unescape_segment != NULL) {
        free(str_uri_unescape_segment);
    }
    gchar** strh_uri_list_extract_uris = g_uri_list_extract_uris(buffer);
    if (strh_uri_list_extract_uris != NULL) {
        g_strfreev(strh_uri_list_extract_uris);
    }
    gchar* str_filename_from_uri = g_filename_from_uri(buffer, NULL, NULL);
    if (str_filename_from_uri != NULL) {
        g_free(str_filename_from_uri);
    }
    gchar* str_filename_to_uri = g_filename_to_uri(buffer, NULL, NULL);
    if (str_filename_to_uri != NULL) {
        g_free(str_filename_to_uri);
    }
    return EXIT_SUCCESS;
}
