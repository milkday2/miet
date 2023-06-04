#include <stdio.h>
#include <stdlib.h>

#define NR 9
#define NC 12
#define LEN 9

int alphabetIndex(char c, char alphabet[NC]) {
  for (int i = 0; i < NC; i++)
    if (alphabet[i] == c)
      return i;
  return -1;
}
char *turing_machine(const char *sequence, int len, int state, int pos,
                     int table[NR][NC][3], char alphabet[NC]) {
  char *seq = malloc(len + 1);
  for (int i = 0; i < len + 1; i++)
    seq[i] = sequence[i];

  int col;
  int new_state;
  while (1) {
    col = alphabetIndex(seq[pos], alphabet);
    if (table[state][col][0] == -1 && table[state][col][1] == -1 &&
        table[state][col][2] == -1)
      return seq;

    if (table[state][col][0] > -1)
      new_state = table[state][col][0];
    if (table[state][col][1] > -1) {
      seq[pos] = alphabet[table[state][col][1]];
    }
    if (table[state][col][2] == 0)
      pos--;
    if (table[state][col][2] == 1)
      pos++;
    state = new_state;
  }
}

int main(void) {
  char alphabet[NC] = {'|', '*', '0', '1', '2', '3',
                       '4', '5', '6', '7', '8', '9'};
  int table[NR][NC][3];
  for (int i = 0; i < NR; i++)
    for (int j = 0; j < NC; j++)
      for (int k = 0; k < 3; k++)
        table[i][j][k] = -1;
  for (int i = 0; i < NR; i++) {
    table[i][0][0] = i + 1;
    table[i][0][1] = 1;
    table[i][0][2] = 1;
  }
  table[NR - 1][0][0] = -1;
  table[NR - 1][0][1] = 11;
  table[NR - 1][0][2] = -1;
  for (int i = 0; i < NR; i++) {
    table[i][1][0] = -1;
    table[i][1][1] = i + 2;
    table[i][1][2] = -1;
  }

  char *seq = malloc(10);
  char seqs[10][10] = {"*********", "|********", "||*******", "|||******",
                       "||||*****", "|||||****", "||||||***", "|||||||**",
                       "||||||||*", "|||||||||"};
  for (int i = 0; i < 10; i++) {
    seq = turing_machine(seqs[i], 9, 0, 0, table, alphabet);
    printf("%s\n", seq);
    free(seq);
  }

  return 0;
}
