#include <cstdio>
#include <iostream>
#include <iomanip>

void viewPointer(void *p);

int main(void)
{
    printf("--viewPointer\n");
    char c = 'a';
    double d = 3.14;
    int i = 3;
    printf("char:\n");
    viewPointer(&c);
    printf("\ndouble:\n");
    viewPointer(&d);
    printf("\nint:\n");
    viewPointer(&i);
    return 0;
}

void viewPointer(void *p)
{
    char *p1 = reinterpret_cast<char *>(p);
    unsigned short *p2 = reinterpret_cast<unsigned short *>(p);
    double *p3 = reinterpret_cast<double *>(p);
    printf("p = %p\n", p);
    printf("p+1 = %p\n", p + 1);
    printf("p1 = %p\n", p1);
    printf("p1+1 = %p\n", p1 + 1);
    printf("p2 = %p\n", p2);
    printf("p2+1 = %p\n", p2 + 1);
    printf("p3 = %p\n", p3);
    printf("p3+1 = %p\n", p3 + 1);
}
