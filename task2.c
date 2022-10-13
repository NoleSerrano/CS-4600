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
	// initializations
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *n = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *M = BN_new();
	BIGNUM *d = BN_new();
	BIGNUM *C = BN_new();

	BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5"); // n
	BN_hex2bn(&e, "010001"); // e
	BN_hex2bn(&M, "4120746f702073656372657421"); // M
	BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D"); // d

	// calculation
	BN_mod_exp(C, M, e, n, ctx); // M^e mod(n)
	printBN("C =", C);
	
	// verification
	BN_mod_exp(M, C, d, n, ctx); // C^d mod(n)
	printBN("M =", M);

	return 0;
}