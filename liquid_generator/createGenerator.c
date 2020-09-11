#include <stdio.h>
#include <stdlib.h>
#include "secp256k1.h"
#include "secp256k1_generator.h"
#include "secp256k1_rangeproof.h"

static const secp256k1_generator secp256k1_generator_h_internal = {{
    0x50, 0x92, 0x9b, 0x74, 0xc1, 0xa0, 0x49, 0x54, 0xb7, 0x8b, 0x4b, 0x60, 0x35, 0xe9, 0x7a, 0x5e,
    0x07, 0x8a, 0x5a, 0x0f, 0x28, 0xec, 0x96, 0xd5, 0x47, 0xbf, 0xee, 0x9a, 0xce, 0x80, 0x3a, 0xc0,
    0x31, 0xd3, 0xc6, 0x86, 0x39, 0x73, 0x92, 0x6e, 0x04, 0x9e, 0x63, 0x7c, 0xb1, 0xb5, 0xf4, 0x0a,
    0x36, 0xda, 0xc2, 0x8a, 0xf1, 0x76, 0x69, 0x68, 0xc3, 0x0c, 0x23, 0x13, 0xf3, 0xa3, 0x89, 0x04
}};

unsigned char KEY[] = { 0x8c,0xb3,0x0e,0x51,0x31,0x4b,0x5d,0x6e,0x57,0xbb,0xab,0x09,0x05,0x48,0x56,0x7d,0x02,0xa0,0xbe,0xad,0x63,0xd5,0x11,0xc5,0x9d,0x96,0x94,0x69,0x82,0x77,0x54,0x8f };

unsigned char BLIND[] = { 0x1d,0x68,0xe8,0x3e,0xa6,0xd6,0x15,0xd1,0x78,0x0a,0x82,0x00,0xee,0x02,0x0e,0xbf,0xb4,0xa8,0x54,0x89,0xba,0x6b,0x34,0x30,0xbe,0x9e,0xae,0xf8,0x09,0x59,0xc1, 0x0c };

// unsigned char BLIND[] = { 0xa3,0x97,0xa2,0x55,0x53,0xbe,0xf1,0xfc,0xf9,0x79,0x6b,0x52,0x14,0x13,0xe9,0xe2,0x2d,0x51,0x8e,0x1f,0x56,0x08,0x57,0x27,0xa7,0x05,0xd4,0xd0,0x52,0x82,0x77,0x75,0x0a };

// from https://assets.blockstream.info/

unsigned char ASSET_LBTC[] = {0x6f,0x02,0x79,0xe9,0xed,0x04,0x1c,0x3d,0x71,0x0a,0x9f,0x57,0xd0,0xc0,0x29,0x28,0x41,0x64,0x60,0xc4,0xb7,0x22,0xae,0x34,0x57,0xa1,0x1e,0xec,0x38,0x1c,0x52,0x6d};
unsigned char ASSET_USDT[] = {0xce,0x09,0x1c,0x99,0x8b,0x83,0xc7,0x8b,0xb7,0x1a,0x63,0x23,0x13,0xba,0x37,0x60,0xf1,0x76,0x3d,0x9c,0xfc,0xff,0xae,0x02,0x25,0x8f,0xfa,0x98,0x65,0xa3,0x7b,0xd2};
unsigned char ASSET_T_LBTC[] = {0x5a,0xc9,0xf6,0x5c,0x0e,0xfc,0xc4,0x77,0x5e,0x0b,0xae,0xc4,0xec,0x03,0xab,0xdd,0xe2,0x24,0x73,0xcd,0x3c,0xf3,0x3c,0x04,0x19,0xca,0x29,0x0e,0x07,0x51,0xb2,0x25};
unsigned char ASSET_R_LBTC[] = {0xb2,0xe1,0x5d,0x0d,0x7a,0x0c,0x94,0xe4,0xe2,0xce,0x0f,0xe6,0xe8,0x69,0x1b,0x9e,0x45,0x13,0x77,0xf6,0xe4,0x6e,0x80,0x45,0xa8,0x6f,0x7c,0x4b,0x5d,0x4f,0x0f,0x23};
unsigned char ASSET_JPYS[] = { 0x34,0x38,0xec,0xb4,0x9f,0xc4,0x5c,0x08,0xe6,0x87,0xde,0x47,0x49,0xed,0x62,0x8c,0x51,0x1e,0x32,0x64,0x60,0xea,0x43,0x36,0x79,0x4e,0x1c,0xf0,0x27,0x41,0x32,0x9e};
unsigned char ASSET_LCAD[] = { 0x0e,0x99,0xc1,0xa6,0xda,0x37,0x9d,0x1f,0x41,0x51,0xfb,0x9d,0xf9,0x04,0x49,0xd4,0x0d,0x06,0x08,0xf6,0xcb,0x33,0xa5,0xbc,0xbf,0xc8,0xc2,0x65,0xf4,0x2b,0xab,0x0a };
unsigned char ASSET_BTSE[] = { 0xb0,0x0b,0x0f,0xf0,0xb1,0x1e,0xbd,0x47,0xf7,0xc6,0xf5,0x76,0x14,0xc0,0x46,0xdb,0xbd,0x20,0x4e,0x84,0xbf,0x01,0x17,0x8b,0xaf,0x2b,0xe3,0x71,0x3a,0x20,0x6e,0xb7 };
unsigned char ASSET_SAI[] = { 0xd9,0xf6,0xbb,0x51,0x6c,0x9f,0x3a,0xb1,0x6b,0xed,0x3f,0x36,0x62,0xae,0x01,0x85,0x73,0xee,0x6b,0x00,0x13,0x0f,0x23,0x47,0xa4,0xb7,0x35,0xd8,0xe7,0xc4,0xc3,0x96 };
unsigned char ASSET_BEERTC[] = { 0xff,0xff,0x7e,0x44,0x8a,0x09,0x97,0x7d,0xbb,0x2d,0x32,0x20,0x91,0x54,0xfc,0x4f,0xb4,0x4f,0x1e,0x10,0x98,0xd8,0x05,0x74,0xf6,0x6c,0x3a,0x8e,0x0a,0xb5,0x55,0x9f };
unsigned char ASSET_LAUD[] = { 0xf5,0x9c,0x5f,0x3e,0x81,0x41,0xf3,0x22,0x27,0x6d,0xaa,0x63,0xed,0x5f,0x30,0x70,0x85,0x80,0x8a,0xea,0x6d,0x4e,0xf9,0xba,0x61,0xe2,0x81,0x54,0x53,0x3f,0xde,0xc7 };

unsigned char *ASSETS[] = {
	ASSET_LBTC,
	ASSET_USDT,
	ASSET_T_LBTC,
	ASSET_R_LBTC,
	ASSET_JPYS,
	ASSET_LCAD,
	ASSET_BTSE,
	ASSET_SAI,
	ASSET_BEERTC,
	ASSET_LAUD,
	NULL
};

void swap32(unsigned char *target, unsigned char *src) {
	int i;
	for (i=0; i<32; i++) {
		target[i] = src[31-i];
	}
}

int illegal;

void illegal_callback(const char *message, void *data) {
	//printf("ILLEGAL %s\n", message);
	//illegal = 1;
}

int main(int argc, char **argv) {
	unsigned char out[65];
	unsigned char blind[32];
	secp256k1_context *ctx;
	secp256k1_generator gen;
	secp256k1_generator genBlind;
	secp256k1_pubkey pub;
	secp256k1_pedersen_commitment commitment;
	size_t outSize = sizeof(out);
	int i, index;
	ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
	secp256k1_context_set_illegal_callback(ctx, illegal_callback, NULL);

#if 0
	//secp256k1_generator_generate_blinded(ctx, &gen, KEY, BLIND);
retry:
	for (i=0; i<32; i++) {
		blind[i] = rand() % 255;
	}
	secp256k1_generator_generate_blinded(ctx, &genBlind, KEY, blind);
	secp256k1_generator_serialize(ctx, out, &genBlind);
	if (out[0] == 0x0a) {
		goto retry;
	}
	printf("Blinding factor ");
	for (i=0; i<33; i++) {
		printf("%.2x", blind[i]);
	}
	printf("\n");
	printf("Blinded generator ");
	for (i=0; i<33; i++) {
		printf("%.2x", out[i]);
	}
	printf("\n");
	secp256k1_generator_generate(ctx, &gen, KEY);
	secp256k1_generator_serialize(ctx, out, &gen);
	printf("Non blinded generator ");
	for (i=0; i<33; i++) {
		printf("%.2x", out[i]);
	}
	printf("\n");
	out[0] = 0x03;
	secp256k1_ec_pubkey_parse(ctx, &pub, out, 33);
	//secp256k1_ec_pubkey_tweak_add(ctx, &pub, BLIND);
	secp256k1_ec_pubkey_tweak_add(ctx, &pub, blind);
	secp256k1_ec_pubkey_serialize(ctx, out, &outSize, &pub, SECP256K1_EC_UNCOMPRESSED);
	printf("Tweaked generator ");
	for (i=0; i<65; i++) {
		printf("%.2x", out[i]);
	}
	printf("\n");

	secp256k1_pedersen_commit(ctx, &commitment, BLIND, 0x42, &genBlind);
	secp256k1_pedersen_commitment_serialize(ctx, out, &commitment);
	printf("Pedersen commitment ");
	for (i=0; i<33; i++) {
		printf("%.2x", out[i]);
	}
	printf("\n");

	secp256k1_generator_serialize(ctx, out, &secp256k1_generator_h_internal);
#endif

	index = 0;
	while(ASSETS[index]) {
		unsigned char *asset = ASSETS[index];
		unsigned char tmp[32];
		unsigned char outBlind[33];
		unsigned char outTest[33];
		int parity = 0;
		memset(tmp, 0x11, sizeof(tmp));
		printf("Generator for ");
		for (i=0; i<32; i++) {
			printf("%.2x", asset[i]);
		}
		printf("\n");
		swap32(blind, asset);
		secp256k1_generator_generate_blinded(ctx, &genBlind, blind, tmp);
		secp256k1_generator_serialize(ctx, outBlind, &genBlind);
		secp256k1_generator_generate(ctx, &gen, blind);
		secp256k1_generator_serialize(ctx, out, &gen);
                printf("Blind generator ");
                for (i=0; i<33; i++) {
                        printf("%.2x", outBlind[i]);
                }
		printf("Non blinded generator ");
		for (i=0; i<33; i++) {
			printf("%.2x", out[i]);
		}
		printf("\n");
		illegal = 0;
		out[0] = 0x02;
		outSize = 33;
		secp256k1_ec_pubkey_parse(ctx, &pub, out, 33);
		secp256k1_ec_pubkey_tweak_add(ctx, &pub, tmp);
		if (!illegal) {
			secp256k1_ec_pubkey_serialize(ctx, outTest, &outSize, &pub, SECP256K1_EC_COMPRESSED);
			printf("Test 0x02\n");
			for (i=0; i<33; i++) {
				printf("%.2x", outTest[i]);
			}
			printf("\n\n");
			if (memcmp(outTest + 1, outBlind + 1, 32) == 0) {
				parity = 0x02;
			}	
		}
		illegal = 0;
                out[0] = 0x03;
		outSize = 33;
                secp256k1_ec_pubkey_parse(ctx, &pub, out, 33);
                secp256k1_ec_pubkey_tweak_add(ctx, &pub, tmp);
		if (!illegal) {
                	secp256k1_ec_pubkey_serialize(ctx, outTest, &outSize, &pub, SECP256K1_EC_COMPRESSED);
                	printf("Test 0x03\n");
                	for (i=0; i<33; i++) {
                        	printf("%.2x", outTest[i]);
                	}
                	printf("\n\n");
			if (memcmp(outTest + 1, outBlind + 1, 32) == 0) {
				parity = 0x03;
			}
		}
		printf("Parity %d\n", parity);
		outSize = 65;
		out[0] = parity;
                secp256k1_ec_pubkey_parse(ctx, &pub, out, 33);
		secp256k1_ec_pubkey_serialize(ctx, out, &outSize, &pub, SECP256K1_EC_UNCOMPRESSED);
                for (i=0; i<32; i++) {
                        printf("%.2x", asset[i]);
		}
		printf("Full non blinded generator ");
		for (i=0; i<65; i++) {
			printf("%.2x", out[i]);
		}		
		printf("\n\n");
		index++;
	}

	secp256k1_context_destroy(ctx);
}
