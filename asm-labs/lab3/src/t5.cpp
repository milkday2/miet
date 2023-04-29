#include <cstdio>

unsigned short floor256mult(unsigned short);
unsigned short ceil256mult(unsigned short);

int main(void){
    unsigned short D = 256;
    unsigned short x = 42545;
    printf("%hu  %hx\n",floor256mult(x),floor256mult(x));
    printf("%hu  %hx\n",ceil256mult(x),ceil256mult(x));
    return 0;
}

unsigned short floor256mult(unsigned short n){
    return n & 0xff00;
}

unsigned short ceil256mult(unsigned short n){
    return (n & 0xff00)+256;
}
