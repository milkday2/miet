#include <cstdio>
#include <iostream>

void printPointer(void *p);

int main(void)
{
    std::cout << std::hex;
    printf("--printPointer\n");
    long long ll = 0x8877665544332211;
    char str[] = "abcdefgh0123456789";
    printf("long long:\n");
    printPointer(&ll);
    printf("\nchar[]:\n");
    printPointer(&str);

    return 0;
}

void printPointer(void *p)
{
    char *p1 = reinterpret_cast<char *>(p);
    unsigned short *p2 = reinterpret_cast<unsigned short *>(p);
    double *p3 = reinterpret_cast<double *>(p);
    // std::cout<<"*p = "<<*p<<'\n'; error: must be a pointer to a complete object type
    std::cout << "*p1 = " << *p1 << '\n'
              << "*(p1+1) = " << *(p1 + 1) << '\n'
              << "*p2 = " << *p2 << '\n'
              << "*(p2+1) = " << *(p2 + 1) << '\n'
              << "*p3 = " << *p3 << '\n'
              << "*(p3+1) = " << *(p3 + 1) << '\n';
}
