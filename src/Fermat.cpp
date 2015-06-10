#include <gmp.h>

void Fermat(mpz_t n, mpz_t p, mpz_t q)
{
	mpz_t x, x2, y, y2;
	mpz_inits(x, x2, y, y2, NULL);

	mpz_sqrt(x, n);
	if(mpz_perfect_square_p(n) != 0)
	{
		mpz_set(p, x);
		mpz_set(q, x);
	}

	do
	{
		mpz_add_ui(x, x, 1);
		mpz_pow_ui(x2, x, 2);
		mpz_sub(y2, x2, n);
		if(mpz_perfect_square_p(y2) == 0)
		{
			mpz_sqrt(y, y2);
			mpz_sub(p, x, y);
			mpz_add(q, x, y);
		}
	} while(mpz_cmp(x, n) < 0);
}
