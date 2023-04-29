#include <cstdio>

double leibsum(double eps) {
  int N = 3 / eps + 7;
  double sum = 0.0;
  for (int i = N - 1; i > 6; i--) {
    if (i % 2)
      sum -= 3.0 / ((double)(i)-6.0);
    else
      sum += 3.0 / ((double)(i)-6.0);
  }
  return sum;
}

int main(void){
    double eps;
    scanf("%lf",&eps);
    printf("%f\n",leibsum(eps));
}
