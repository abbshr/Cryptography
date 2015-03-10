#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "crypt.h"

int main(int argc, char const *argv[])
{
  int t;
  double p;

  FILE *rs = fopen(argv[1], "r");

  for (int i = 0; i < len; i++)
    p += pow(records[i] / total, 2);

  printf("IC: %lf\n", p);

  return 0;
}