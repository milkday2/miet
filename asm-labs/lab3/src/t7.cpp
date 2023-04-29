#include <cstdio>

float abs_f32(float x) {
  int xint = *(reinterpret_cast<int *>(&x)) & 0x7fffffff;
  return *reinterpret_cast<float*>(&xint);
}

int main(void){
    float x;
    scanf("%f",&x);
    printf("%f\n",abs_f32(x));
}
