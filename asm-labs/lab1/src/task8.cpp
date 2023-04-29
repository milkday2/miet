#include <cstdio>

int main(void) {
  char s1[32];
  char s2[32];
  char s3[32];
  scanf("%s %31s %31[^\n]", s1,s2,s3);
  printf("s1:***%s***\ns2:***%s***\ns3:***%s***\n", s1,s2,s3);
  return 0;
}
