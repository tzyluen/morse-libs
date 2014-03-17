/**
 * Morse Code Translator
 * UEFI/C
 * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under UEFI v2.40 (EDK II)
 */
#include <stdio.h>
#include <stdlib.h>
#include "morse.h"
#define MAXCHARS 100

int main (int argc, char **argv)
{
    Morse_map *mm = Morse_map_create();
    char line[MAXCHARS];

    while (fgets(line, sizeof line, stdin) != NULL) {
        char *string = morse_to_string(line, mm);
        printf("%s", string);
    }

    free(mm);

    return 0;
}
