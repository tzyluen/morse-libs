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

int main (IN int Argc, IN char **Argv)
{
    printf("%d\n", Argc);
    Morse_map *mm = Morse_map_create();
    char line[MAXCHARS];

    while (fgets(line, sizeof line, stdin) != NULL) {
        char *morses = line_to_morse(line, mm);
        printf("%s\n", morses);
    }

    return 0;
}
