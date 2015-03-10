#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
  if (argc < 2) {
    printf("%s\n", "usage: ./icanalyze len FILE");
    return 1;
  }
  
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
  
  int i = 0;
  int t = atoi(argv[1]);
  // split probabilities into t groups
  double *p = (double *) malloc(sizeof(double) * t);
  double m;

  // initialize
  while (i < t) {
    p[i++] = 0;
  }

  i = 0;

  // cal every IC
  while (fscanf(rs, "%lf", &m) != EOF)
    p[i++ % t] += pow(m, 2);

  int detected = 1;
  // output IC results for every group
  for (i = 0; i < t; i++) {
    if (fabs(p[i] - 0.65) > 0.3) 
      detected = 0;
    printf("group %d IC: %.3lf\n", i, p[i]);
  }

  if (detected)
    printf("detected key length: %d\n", t);

  free(p);
  fclose(rs);
  
  return 0;
}