/**
 * Morse Code Translator
 * Linux kernel module
 * Copyright (C) 2014 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under GNU C gcc 4.7.2, linux kernel 3.14.3-x86_64
 */
#include <linux/ctype.h>
#include <linux/stddef.h>
#include <linux/slab.h>
#include <linux/string.h>
#include "morse.h"

Morse_map *Morse_map_create()
{
    Morse_map mm[MORSE_MAP_SIZE] = {
         {.c='\n', .m="\n"},     {.c=' ', .m=" "},       {.c='!', .m="-.-.--"},
         {.c='\"',.m= ".-..-."}, {.c='$', .m="...-..-"}, {.c='&', .m=".-..."},
         {.c='\'',.m= ".----."}, {.c='(', .m="-.--."},   {.c=')', .m="-.--.-"},
         {.c='+', .m=".-.-."},   {.c=',', .m="--..--"},  {.c='-', .m="-....-"},
         {.c='.', .m=".-.-.-"},  {.c='/', .m="-..-."},      
         {.c='0', .m="-----"},   {.c='1', .m=".----"},   {.c='2', .m="..---"},
         {.c='3', .m="...--"},   {.c='4', .m="....-"},   {.c='5', .m="....."},
         {.c='6', .m="-...."},   {.c='7', .m="--..."},   {.c='8', .m="---.."},
         {.c='9', .m="----."},   {.c=':', .m="---..."},  {.c=';', .m="-.-.-."},
         {.c='=', .m="-...-"},   {.c='?', .m="..--.."},  {.c='@', .m=".--.-."},
         {.c='A', .m=".-"},      {.c='B', .m="-..."},    {.c='C', .m="-.-."},
         {.c='D', .m="-.."},     {.c='E', .m="."},       {.c='F', .m="..-."},
         {.c='G', .m="--."},     {.c='H', .m="...."},    {.c='I', .m=".."},
         {.c='J', .m=".---"},    {.c='K', .m="-.-"},     {.c='L', .m=".-.."},
         {.c='M', .m="--"},      {.c='N', .m="-."},      {.c='O', .m="---"},
         {.c='P', .m=".--."},    {.c='Q', .m="--.-"},    {.c='R', .m=".-."},
         {.c='S', .m="..."},     {.c='T', .m="-"},       {.c='U', .m="..-"},
         {.c='V', .m="...-"},    {.c='W', .m=".--"},     {.c='X', .m="-..-"},
         {.c='Y', .m="-.--"},    {.c='Z', .m="--.."},    {.c='_', .m="..--.-"}
    };

    Morse_map *morse_map = kmalloc(MORSE_MAP_SIZE * sizeof(Morse_map),
            GFP_KERNEL);
    memcpy(morse_map, &mm, MORSE_MAP_SIZE * sizeof(Morse_map));

    return morse_map;
}


size_t line_to_morse(char *dest, const char *s, Morse_map *morse_map)
{
    size_t i, size = 0;
    char *_buf;
    for (i = 0; i < strlen(s) && s[i] != '\0'; ++i) {
        if (toupper(s[i]) < '\n' || toupper(s[i]) > '_') {
            printk(KERN_INFO "(%d): %d : %d : %d : %d\n",
                    __LINE__,
                    toupper(s[i]),
                    '\n',
                    '_',
                    (toupper(s[i]) < '\n') || (toupper(s[i] > '_')));
            continue;
        }
        _buf = get_morse(toupper(s[i]), morse_map);
        strcat(dest, _buf);
        if (s[i] != ' ' && s[i] != '\n')
            strcat(dest, " ");
        ++size;
    }
    printk(KERN_INFO "%s(%d): dest->%s\n", __FILE__, __LINE__, (char *)dest);
    return size;
}


char *get_morse(char c, Morse_map *morse_map)
{
    int match = binsearch(c, morse_map, MORSE_MAP_SIZE);

    return match ? morse_map[match].m : "";
}


char *morse_to_string(char *morse, Morse_map *morse_map)
{
    char *s = "";
    char *t = strsep(&morse, " ");
    while (t) {
        char _buf[2];
        char_to_str(to_letter(t, morse_map), _buf);
        strcat(s, _buf);
        t = strsep(&morse, " ");
    }

    return s;
}


char to_letter(char *morse, Morse_map *morse_map)
{
    size_t i;
    for (i = 0; i < MORSE_MAP_SIZE; ++i)
        if (0 == strcmp(morse_map[i].m, morse))
            return morse_map[i].c;

    return (strcmp(morse, "") == 0) ? ' ' : -1;
}


char *char_to_str(char c, char *s)
{
    s[0] = c, s[1] = '\0';
    return s;
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


void str_to_int(char *s, Morse_map *morse_map)
{
    do
        printk(KERN_INFO "%c->%d->%s\n", *s, *s,
                get_morse(toupper(*s), morse_map));
    while (*s++ != '\0');
}
