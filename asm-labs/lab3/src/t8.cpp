#include <cstdio>

template <typename T> T harmonic_sum(int N) {
  T sum = 0.0;
  for (int i = 1; i < N + 1; i++) {
    sum += (T)(1) / (T)(i);
  }
  return sum;
}
template <typename T> T harmonic_sum_reversed(int N) {
  T sum = 0.0;
  for (int i = N; i > 0; i--) {
    sum += (T)(1) / (T)(i);
  }
  return sum;
}

int main(void) {
  float SdE3 = harmonic_sum<float>(1000);
  float SdE6 = harmonic_sum<float>(1000000);
  float SdE9 = harmonic_sum<float>(1000000000);
  float SaE3 = harmonic_sum_reversed<float>(1000);
  float SaE6 = harmonic_sum_reversed<float>(1000000);
  float SaE9 = harmonic_sum_reversed<float>(1000000000);

  printf("\nfloat:\n");
  printf("Sd(10e+3) = %f\n"
         "Sa(10e+3) = %f\n"
         "Sd(10e+6) = %f\n"
         "Sa(10e+6) = %f\n"
         "Sd(10e+9) = %f\n"
         "Sa(10e+9) = %f\n",
         SdE3, SaE3, SdE6, SaE6, SdE9, SaE9);

  double SdE3_64 = harmonic_sum<double>(1000);
  double SdE6_64 = harmonic_sum<double>(1000000);
  double SdE9_64 = harmonic_sum<double>(1000000000);
  double SaE3_64 = harmonic_sum_reversed<double>(1000);
  double SaE6_64 = harmonic_sum_reversed<double>(1000000);
  double SaE9_64 = harmonic_sum_reversed<double>(1000000000);

  printf("\ndouble:\n");
  printf("Sd(10e+3) = %f\n"
         "Sa(10e+3) = %f\n"
         "Sd(10e+6) = %f\n"
         "Sa(10e+6) = %f\n"
         "Sd(10e+9) = %f\n"
         "Sa(10e+9) = %f\n",
         SdE3_64, SaE3_64, SdE6_64, SaE6_64, SdE9_64, SaE9_64);
  return 0;
}
