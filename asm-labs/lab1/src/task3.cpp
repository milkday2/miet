#include <cstdio>
#include <stddef.h>

int main(void)
{
    printf("char %ld\n", sizeof(char));
    printf("signed char %ld\n", sizeof(signed char));
    printf("unsigned char %ld\n", sizeof(unsigned char));
    printf("wchar_t %ld\n", sizeof(wchar_t));
    printf("wchar_t* %ld\n", sizeof(wchar_t*));
    printf("short %ld\n", sizeof(short));
    printf("unsigned short %ld\n", sizeof(unsigned short));
    printf("int %ld\n", sizeof(int));
    printf("unsigned int %ld\n", sizeof(unsigned int));
    printf("long %ld\n", sizeof(long));
    printf("unsigned long %ld\n", sizeof(unsigned long));
    printf("long long %ld\n", sizeof(long long));
    printf("unsigned long long %ld\n", sizeof(unsigned long long));
    printf("float %ld\n", sizeof(float));
    printf("double %ld\n", sizeof(double));
    printf("long double %ld\n", sizeof(long double));
    printf("size_t %ld\n", sizeof(size_t));
    printf("ptrdiff_t %ld\n", sizeof(ptrdiff_t));
    printf("void* %ld\n", sizeof(void *));
    printf("char* %ld\n", sizeof(char *));
    printf("int* %ld\n", sizeof(int *));
    printf("unsigned int* %ld\n", sizeof(unsigned int *));
    return 0;
}
