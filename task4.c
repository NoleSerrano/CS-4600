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
	BIGNUM *d = BN_new();
	BIGNUM *M1 = BN_new();
	BIGNUM *M2 = BN_new();
	BIGNUM *C = BN_new();

	BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5"); // n
	BN_hex2bn(&e, "010001"); // e
	BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D"); // d
	BN_hex2bn(&M1, "49206f776520796f752024323030302e"); // M1
	BN_hex2bn(&M2, "49206f776520796f752024333030302e"); // M2

	// digital signatures & verification
	BN_mod_exp(C, M1, d, n, ctx); // M1^d mod(n)
	printBN("C1 =", C);
	BN_mod_exp(M1, C, e, n, ctx); // C1^e mod(n)
	printBN("M1 =", M1);

	BN_mod_exp(C, M2, d, n, ctx); // M2^d mod(n)
	printBN("C2 =", C);
	BN_mod_exp(M2, C, e, n, ctx); // C2^e mod(n)
	printBN("M2 =", M2);

	return 0;
}