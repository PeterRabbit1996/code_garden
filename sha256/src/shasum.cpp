#include "sha256.h"
#include "shasum.h"

int calculateHash(void *data, const size_t size, std::string &hash)
{
	if (data == NULL ||
	    size == 0)
		return -1;

	unsigned char result[32];
	struct sha256_ctx hashCtx;
	sha256_init_ctx(&hashCtx);
	sha256_process_bytes(data, size, &hashCtx);
	sha256_finish_ctx(&hashCtx, result);

	hash.resize(0);
	for (int i = 0; i < 32; i++)
	{
		hash.push_back(hex2asc(*((unsigned char *)result + i) >> 4));
		hash.push_back(hex2asc(*((unsigned char *)result + i) & 0xf));
	}

	return 0;
}

unsigned hex2asc(unsigned char dig)
{
	dig &= 0x0f;
	if (dig > 9)
		return dig - 10 + 'a';
	return dig += '0';
}
