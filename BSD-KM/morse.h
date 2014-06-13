/**
 * Morse Code Translator
 * BSD kernel module
 * Copyright (C) 2014 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under FreeBSD clang version 3.3 (tags/RELEASE_33/final 183502) 20130610
 * Target: x86_64-unknown-freebsd10.0
 */
#ifndef MORSE_H
#define MORSE_H

#define MORSE_MAP_SIZE 56
#define MORSE_CODE_AVG_CHAR 5

typedef struct Morse {
    char c;
    char *m;
} Morse_map;


Morse_map *Morse_map_create(void);
size_t line_to_morse(char *dest, const char *, Morse_map *);
char *get_morse(char, Morse_map *);
char *morse_to_string(char *, Morse_map *);
char to_letter(char *, Morse_map *);
int binsearch(char, Morse_map *, int);
char *char_to_str(char, char *);
void str_to_int(char *, Morse_map *);
void cleanup(void);

#endif
