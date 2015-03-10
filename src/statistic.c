#include <stdio.h>
#include <stdlib.h>
#include "crypt.h"

int main(int argc, char const *argv[])
{
  char* directory = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int len = 26;
  FILE *rs = fdopen(0, "r");
  double p;
  int i = 0;
  while (fscanf(rs, "%lf", &p) != EOF)
    printf("char: %c %.3lf %c\n", directory[i++ % len], p * 100, '%');

  fclose(rs);

  return 0;
}