// gcc -o main exo1.c -lgmp && ./main

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include "gmp.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    int booleen = FALSE;
    gmp_randstate_t state;
    unsigned long seed = time(NULL);

    if (argc == 3) {
        seed = strtol(argv[2], NULL, 10);
    }

    mpz_t k;
    mpz_init(k);
    mpz_t rand;
    mpz_init(rand);
    mpz_t test;
    mpz_init(test);
    mpz_set_str(k, argv[1], 10);


    gmp_randinit_default (state);
    gmp_randseed_ui(state, seed);


    while (booleen != TRUE) {
        mpz_urandomb(rand, state, mpz_get_ui(k));
        gmp_printf("%Zd\n", rand);
        if (mpz_fdiv_r_ui(test, rand, 20) == 0) {
            booleen = TRUE;
            printf("\n%s %lu\n", "Seed utilisée :", seed);
            printf("%s", "Modulo 20 trouvé -> ");
            gmp_printf("%Zd\n", rand);
        }
    }

    return 0;
}
