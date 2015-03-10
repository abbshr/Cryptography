#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "crypt.h"

int main(int argc, char const *argv[])
{
  if (argc < 2) {
    printf("%s\n", "usage: ./vigenere keylen FILE");
    printf("%s\n", "usage: cat FILE | ./vigenere keylen");
    return 1;
  }
  
  srand((unsigned) time(NULL));
  int n = atoi(argv[1]);
  char* directory = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int len = 26;

  int i = 0;
  char *k = (char *) malloc(sizeof(char) * (n + 1));
  genkey(k, n, directory, len);
  
  FILE *rs;
  if (argc > 2) {
    rs = fopen(argv[2], "r");
    if (!rs) {
      perror("EEXIST");
      return 1;
    }
  } else {
    rs = fdopen(0, "r");
  }
  
  int m;
  // output the cipher
  while ((m = fgetc(rs)) != EOF)
    if ((m >= 65 && m <= 90) || (m >= 97 && m <= 122))
      printf("%c", directory[(getIndex(m, directory, len) + getIndex(k[i++ % n], directory, len)) % len]);
    else
      printf("%c", m);

  free(k);
  fclose(rs);

  return 0;
}