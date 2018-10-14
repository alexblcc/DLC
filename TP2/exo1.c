// gcc -o main exo1.c -lgmp && ./main 8 10

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

    mpz_t k;
    mpz_t e;
    mpz_t n;
    mpz_t rand;
    mpz_t pow;
    mpz_t res;
    mpz_init(k);
    mpz_init(e);
    mpz_init(n);
    mpz_init(rand);
    mpz_init(pow);
    mpz_init(res);
    mpz_set_str(k, argv[1], 10);
    mpz_set_str(e, argv[2], 10);

    gmp_randinit_default (state);
    gmp_randseed_ui(state, seed);

    while (booleen != TRUE) {
        mpz_urandomb(rand, state, (mpz_get_ui(k)-1));
        mpz_ui_pow_ui(pow, 2, (mpz_get_ui(k)-1));
        mpz_add(res, rand, pow);
        gmp_printf("%Zd\n", res);

        if ()
    }




    return 0;
}
