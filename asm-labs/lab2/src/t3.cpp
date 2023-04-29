#include <cstdio>
#include <iostream>
#include <bitset>
#include <limits.h>

void print16(void *p);

int main(void)
{
    unsigned short min_ushrt = 0;
    unsigned short max_ushrt = USHRT_MAX;
    short min_shrt = SHRT_MIN;
    short max_shrt = SHRT_MAX;
    short y = 5;
    short z = -5;
    printf("--ushort min:\n");
    print16(&min_ushrt);
    printf("\n--ushort max:\n");
    print16(&max_ushrt);
    printf("\n--short min:\n");
    print16(&min_shrt);
    printf("\n--short max:\n");
    print16(&max_shrt);
    printf("\n--y = 5:\n");
    print16(&y);
    printf("\n--z = -5:\n");
    print16(&z);

    return 0;
}

void print16(void *p)
{
    unsigned short *ushrt = reinterpret_cast<unsigned short *>(p);
    short *shrt = reinterpret_cast<short *>(p);
    std::cout << std::hex << "ushrt hex: " << *ushrt << '\n'
              << "ushrt bin: " << std::bitset<16>(*ushrt) << '\n'
              << std::dec << "ushrt dec: " << *ushrt << '\n'
              << std::hex << "shrt hex: " << *shrt << '\n'
              << "shrt bin: " << std::bitset<16>(*shrt) << '\n'
              << std::dec << "shrt dec: " << *shrt << '\n';
}
