/**
 * Morse Code Translator
 * C
 * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under GNU C gcc 4.7.2
 */
#include <stdio.h>
#include <stdlib.h>
#include "morse.h"

int main(int argc, char **argv)
{
    Morse_map *mm = Morse_map_create();

    size_t len = 0;
    char *line = NULL;

    while (getline(&line, &len, stdin) != -1) {
        char *morses = line_to_morse(line, mm);
        printf("%s\n", morses);

        char *s = morse_to_string(morses, mm);
        printf("%s\n", s);
    }

    free(mm);
    free(line);
    exit(EXIT_SUCCESS);
}
