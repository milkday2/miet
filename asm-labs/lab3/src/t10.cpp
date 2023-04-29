#include <cmath>
#include <cstdio>
#include <limits>

double harmonic_sum(double power, double error) {
  if (power <= 1.0)
    return std::numeric_limits<double>::infinity();
  int N = 1 / std::pow((power - 1) * error, 1.0 / (power - 1)) + 1;
  double sum = 0.0;
  for (int i = N; i > 0; i--) {
    sum += 1.0 / std::pow((double)(i), power);
  }
  return sum;
}

int main(void) {
  double eps;
  double power;
  printf("power:");
  scanf("%lf", &power);
  printf("error:");
  scanf("%lf", &eps);
  printf("%f\n", harmonic_sum(power, eps));
}
