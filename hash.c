#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "hash.h"

/*
 *
 * hash
 *
 * Args:
 *  str     string to be hashed
 *
 * Operation: calculates a hash value for the string
 *        returns the hash value
 */
uint32_t
hash(char *str)
{
    uint32_t hash = 0;
    uint32_t c;

    if (str == NULL) {
        fprintf(stderr, "hash() passed NULL\n");
        return 0UL;
    }

    while ((c = (unsigned char)*str++) != '\0')
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash;
}
