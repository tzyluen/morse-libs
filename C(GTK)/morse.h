/**
 * Morse Code Translator
 * C (GTK+)
 * Copyright (C) 2014 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under GNU C gcc 4.7.2, GTK+3.4.2-7
 */
#ifndef MORSE_H
#define MORSE_H

#define MORSE_MAP_SIZE 56
#define MORSE_CODE_MAX_CHAR 10

typedef struct Morse {
    char c;
    char *m;
} Morse_map;


Morse_map *Morse_map_create();
char *line_to_morse(const char *s, Morse_map *morse_map);
char *get_morse(char c, Morse_map *morse_map);
char *morse_to_string(char *morse, Morse_map *morse_map);
char to_letter(char *morse, Morse_map *morse_map);
int binsearch(char k, Morse_map *morse_map, int n);
char *concat(char *s1, char *s2);
char *append(const char *s, char c);

#endif
