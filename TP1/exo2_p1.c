// gcc -o main exo2_p1.c -lgmp && ./main 8

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
    mpz_t pow;
    mpz_init(pow);
    mpz_t res;
    mpz_init(res);
    mpz_set_str(k, argv[1], 10);


    gmp_randinit_default (state);
    gmp_randseed_ui(state, seed);


    while (booleen != TRUE) {
        mpz_urandomb(rand, state, (mpz_get_ui(k)-1));
        mpz_ui_pow_ui(pow, 2, (mpz_get_ui(k)-1));
        mpz_add(res, rand, pow);
        gmp_printf("%Zd\n", res);
        if (mpz_fdiv_r_ui(test, res, 20) == 0) {
            booleen = TRUE;
            printf("\n%s %lu\n", "Seed utilisée :", seed);
            printf("%s", "Modulo 20 trouvé -> ");
            gmp_printf("%Zd\n", res);
        }
    }

    return 0;
}



// exactement égale a k bits -> générer entre 0 et 2^k-1 et y ajouter un 2^k-1
//au plus égale a k chiffres décimaux -> mpz_urandomm
// exactement égale a k chiffres décimaux -> on génère un aléa entre 0 et 9^k-1 et on ajoute 10^k-1
