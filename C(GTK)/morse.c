/**
 * Morse Code Translator
 * C (GTK+)
 * Copyright (C) 2014 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under GNU C gcc 4.7.2, GTK+3.4.2-7
 */
#include <assert.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "morse.h"

Morse_map *Morse_map_create()
{
    Morse_map mm[MORSE_MAP_SIZE] = {
         {.c='\n', .m="\n"},      {.c=' ', .m=" "},       {.c='!', .m="-.-.--"},
         {.c='\"',.m= ".-..-."},  {.c='$', .m="...-..-"}, {.c='&', .m=".-..."},
         {.c='\'',.m= ".----."},  {.c='(', .m="-.--."},   {.c=')', .m="-.--.-"},
         {.c='+', .m=".-.-."},    {.c=',', .m="--..--"},  {.c='-', .m="-....-"},
         {.c='.', .m=".-.-.-"},   {.c='/', .m="-..-."},      
         {.c='0', .m="-----"},    {.c='1', .m=".----"},   {.c='2', .m="..---"},
         {.c='3', .m="...--"},    {.c='4', .m="....-"},   {.c='5', .m="....."},
         {.c='6', .m="-...."},    {.c='7', .m="--..."},   {.c='8', .m="---.."},
         {.c='9', .m="----."},    {.c=':', .m="---..."},  {.c=';', .m="-.-.-."},
         {.c='=', .m="-...-"},    {.c='?', .m="..--.."},  {.c='@', .m=".--.-."},
         {.c='A', .m=".-"},       {.c='B', .m="-..."},    {.c='C', .m="-.-."},
         {.c='D', .m="-.."},      {.c='E', .m="."},       {.c='F', .m="..-."},
         {.c='G', .m="--."},      {.c='H', .m="...."},    {.c='I', .m=".."},
         {.c='J', .m=".---"},     {.c='K', .m="-.-"},     {.c='L', .m=".-.."},
         {.c='M', .m="--"},       {.c='N', .m="-."},      {.c='O', .m="---"},
         {.c='P', .m=".--."},     {.c='Q', .m="--.-"},    {.c='R', .m=".-."},
         {.c='S', .m="..."},      {.c='T', .m="-"},       {.c='U', .m="..-"},
         {.c='V', .m="...-"},     {.c='W', .m=".--"},     {.c='X', .m="-..-"},
         {.c='Y', .m="-.--"},     {.c='Z', .m="--.."},    {.c='_', .m="..--.-"}
    };

    Morse_map *morse_map = malloc(MORSE_MAP_SIZE * sizeof(Morse_map));
    memcpy(morse_map, &mm, MORSE_MAP_SIZE * sizeof(Morse_map));

    return morse_map;
}


char *line_to_morse(const char *s, Morse_map *morse_map)
{
    assert(s);
    assert(morse_map);

    size_t i;
    char *morses = "";
    for (i = 0; i < strlen(s); ++i) {
        char *_buf = get_morse(toupper(s[i]), morse_map);
        if (s[i] != ' ' && s[i] != '\n')
            _buf = concat(_buf, " ");
        morses = concat(morses, _buf);
    }

    return morses;
}


char *get_morse(char c, Morse_map *morse_map)
{
    assert(c);
    assert(morse_map);

    int match = binsearch(c, morse_map, MORSE_MAP_SIZE);

    return match ? morse_map[match].m : "";
}


char *morse_to_string(char *morse, Morse_map *morse_map)
{
    assert(morse);
    assert(morse_map);

    char *s = "";
    char *t = strsep(&morse, " ");
    while (t) {
        s = append(s, to_letter(t, morse_map));
        t = strsep(&morse, " ");
    }

    return s;
}


char to_letter(char *morse, Morse_map *morse_map)
{
    assert(morse);
    assert(morse_map);

    size_t i;
    for (i = 0; i < MORSE_MAP_SIZE; ++i)
        if (0 == strcmp(morse_map[i].m, morse))
            return morse_map[i].c;

    return (strcmp(morse, "") == 0) ? ' ' : -1;
}


int binsearch(char k, Morse_map *morse_map, int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (k < morse_map[mid].c)
            high = mid - 1;
        else if (k > morse_map[mid].c)
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}


char *concat(char *s1, char *s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1);

    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);

    return result;
}


char *append(const char *s, char c)
{
    size_t len = strlen(s);
    char *new = malloc(len + 2);
    strcpy(new, s);
    new[len] = c;
    new[len + 1] = '\0';

    return new;
}
