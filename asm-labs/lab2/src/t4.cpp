#include <cstdio>
#include <iostream>
#include <bitset>
#include <iomanip>
#include <limits.h>

void print32(void *p);
void print64(void *p);

int main(void)
{
    unsigned int min_uint = 0;
    printf("--ui32 min:\n");
    print32(&min_uint);

    unsigned int max_uint = UINT_MAX;
    printf("\n--ui32 max:\n");
    print32(&max_uint);

    int min_int = INT_MIN;
    printf("\n--i32 min:\n");
    print32(&min_int);

    int max_int = INT_MAX;
    printf("\n--i32 max:\n");
    print32(&max_int);

    unsigned int ux = 0x99887766;
    printf("\n--ui32 0x99887766:\n");
    print32(&ux);

    int x = 0x99887766;
    printf("\n--i32 0x99887766:\n");
    print32(&x);

    int y = 5;
    printf("\n--i32 5:\n");
    print32(&y);

    int z = -5;
    printf("\n--i32 -5:\n");
    print32(&z);

    unsigned long long min_ulong = 0;
    printf("\n--ui64 min:\n");
    print64(&min_ulong);

    unsigned long long max_ulong = ULONG_MAX;
    printf("\n--ui64 max:\n");
    print64(&max_ulong);

    long long min_long = LONG_MIN;
    printf("\n--i64 min:\n");
    print64(&min_long);

    long long max_long = LONG_MAX;
    printf("\n--i64 max:\n");
    print64(&max_long);

    long long xl = 0x99887766;
    printf("\n--i64 0x99887766:\n");
    print64(&xl);

    long long yl = 5;
    printf("\n--i64 5:\n");
    print64(&yl);

    long long zl = -5;
    printf("\n--i64 -5:\n");
    print64(&zl);

    return 0;
}

void print32(void *p)
{
    unsigned int *uint = reinterpret_cast<unsigned int *>(p);
    int *sint = reinterpret_cast<int *>(p);
    float *f = reinterpret_cast<float *>(p);
    std::cout << std::hex << "uint hex: " << *uint << '\n'
              << "uint bin: " << std::bitset<32>(*uint) << '\n'
              << std::dec << "uint dec: " << *uint << '\n'
              << std::hex << "sint hex: " << *sint << '\n'
              << "sint bin: " << std::bitset<32>(*sint) << '\n'
              << std::dec << "sint dec: " << *sint << '\n'
              << std::fixed << std::setprecision(3) << "float with fixed precision: " << *f << '\n'
              << std::scientific << "float scientific: " << *f << '\n';
}

void print64(void *p)
{
    unsigned long long *ulong = reinterpret_cast<unsigned long long *>(p);
    long long *slong = reinterpret_cast<long long *>(p);
    double *d = reinterpret_cast<double *>(p);
    std::cout << std::hex << "ulong hex: " << *ulong << '\n'
              << "ulong bin: " << std::bitset<64>(*ulong) << '\n'
              << std::dec << "ulong dec: " << *ulong << '\n'
              << std::hex << "slong hex: " << *slong << '\n'
              << "slong bin: " << std::bitset<64>(*slong) << '\n'
              << std::dec << "slong dec: " << *slong << '\n'
              << std::fixed << std::setprecision(3) << "double with fixed precision: " << *d << '\n'
              << std::scientific << "double scientific: " << *d << '\n';
}
