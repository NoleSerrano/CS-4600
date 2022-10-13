#include <stdio.h>
#include <openssl/bn.h>

void printBN(char *msg, BIGNUM * a)
{
	/* Use BN_bn2hex(a) for hex string
	* Use BN_bn2dec(a) for decimal string */
	char * number_str = BN_bn2hex(a);
	printf("%s %s\n", msg, number_str);
	OPENSSL_free(number_str);
}

int main()
{
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *p = BN_new();
	BIGNUM *q = BN_new();
	BIGNUM *phi = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *d = BN_new();
	BIGNUM *one = BN_new();
	BIGNUM *pMinusOne = BN_new();
	BIGNUM *qMinusOne = BN_new();

	BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF"); // p
	BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F"); // q
	BN_hex2bn(&e, "0D88C3");

	BN_one(one); // one = 1	
	BN_sub(pMinusOne, p, one); // (p - 1)
	BN_sub(qMinusOne, q, one); // (q - 1)
	BN_mul(phi, pMinusOne, qMinusOne, ctx); // phi(n)
	BN_mod_inverse(d, e, phi, ctx);
	printBN("d = ", d);
	
	return 0;
}
