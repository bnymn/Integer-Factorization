#include <gmp.h>

void TrialDivision(mpz_t n, mpz_t p, mpz_t q)
{
	mpz_t r, max;
	mpz_inits(r, max, NULL);

	mpz_sqrt(max, n);
	while(mpz_cmp(r, max) < 0)
	{
		mpz_nextprime(r, r);
		if(mpz_divisible_p(n, r))
		{
			mpz_set(p, r);
			mpz_fdiv_q(q, n, r);
			break;
		}
	}
}
