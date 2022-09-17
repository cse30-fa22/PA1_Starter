#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "hash.h"
/*
 * CSE Fall 2022 PA1 (Part B)
 *
 * Prints the hash value for the login name of the user running the code
 *
 * See man 3 getlogin for information on how to use getlogin() safely
 */
int
main(void)
{ 
    char *namept;   // is a pointer to the login name string

    /*
     * make sure getlogin returns a non-null value. If so exit with a warning
     */
    if ((namept = getlogin()) == NULL) {
        fprintf(stderr,"Unable to get login name\n");
        return EXIT_FAILURE;
    }

    /*
     * we have a login name, hash it and print the hash value
     */
    printf("%s hash value is: %u\n", namept, hash(namept));
    return EXIT_SUCCESS;
}
    
