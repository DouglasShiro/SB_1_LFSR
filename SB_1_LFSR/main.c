//
//  main.c
//  lfsrTeste
//
//  Created by Adarley Grando on 24/06/18.
//  Copyright © 2018 Adarley Grando. All rights reserved.
//

#include <stdio.h>

#define POLY_MASK16 0xD295
#define POLY_MASK15 0x6699

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
(byte & 0x80 ? '1' : '0'), \
(byte & 0x40 ? '1' : '0'), \
(byte & 0x20 ? '1' : '0'), \
(byte & 0x10 ? '1' : '0'), \
(byte & 0x08 ? '1' : '0'), \
(byte & 0x04 ? '1' : '0'), \
(byte & 0x02 ? '1' : '0'), \
(byte & 0x01 ? '1' : '0')

uint16_t lfsr16N;

uint16_t shift(uint16_t lfsr, uint16_t newBit) {
//    printf("\nAntes: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(lfsr>>8));
//    printf(""BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(lfsr));
    lfsr >>= 1;
    if (newBit == 1) {
        lfsr |= 0x8000;
    }
//    printf("\nDepois: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(lfsr>>8));
//    printf(""BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(lfsr));
//    printf("\n");
    
    return lfsr;
}

uint16_t getRandom() {
    uint16_t result;
    printf("\nRAntes:\t"BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(lfsr16N>>8));
    printf(""BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(lfsr16N));
    //lfsr16N = ((lfsr16N >> 1) & 1);
    uint16_t x1 = (lfsr16N >> 0) & 1;   //bit 16
    uint16_t x2 = (lfsr16N >> 2) & 1;   //bit 14
    uint16_t x3 = (lfsr16N >> 3) & 1;   //bit 13
    uint16_t x4 = (lfsr16N >> 5) & 1;   //bit 11
    uint16_t r = (((x1 ^ x2) ^ x3) ^ x4);
    result = shift(lfsr16N, r);
    printf("\nRDepois:\t"BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(result>>8));
    printf(""BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(result));
    
    return result;
}

void init(void) {
    //seed values
    
    lfsr16N =3;
}

int main(int argc, const char * argv[]) {
    
    init();
    
    //newShift(lfsr16N, 0);
    lfsr16N = getRandom();
    printf("\nRandom: %04x\n", lfsr16N);
    lfsr16N = getRandom();
    printf("\nRandom: %04x\n", lfsr16N);
    lfsr16N = getRandom();
    printf("\nRandom: %04x\n", lfsr16N);
    lfsr16N = getRandom();
    printf("\nRandom: %04x\n", lfsr16N);
    lfsr16N = getRandom();
    printf("\nRandom: %04x\n", lfsr16N);
    lfsr16N = getRandom();
    printf("\nRandom: %04x\n", lfsr16N);
    lfsr16N = getRandom();
    printf("\nRandom: %04x\n", lfsr16N);
    lfsr16N = getRandom();
    printf("\nRandom: %04x\n", lfsr16N);
    lfsr16N = getRandom();
    printf("\nRandom: %04x\n", lfsr16N);
    lfsr16N = getRandom();
    printf("\nRandom: %04x\n", lfsr16N);
    lfsr16N = getRandom();
    printf("\nRandom: %04x\n", lfsr16N);
    lfsr16N = getRandom();
    printf("\nRandom: %04x\n", lfsr16N);
    //printf("\nInit: %04x\n", lfsr16);
    
    return 0;
}
