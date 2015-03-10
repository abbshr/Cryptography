#include <stdio.h>
#include <stdlib.h>
#include "crypt.h"

int main(int argc, char const *argv[])
{
  if (argc < 1) {
    printf("%s\n", "usage: ./summary FILE");
    printf("%s\n", "usage: cat FILE | ./summary");
    return 1;
  }

  int i, m;
  double t = 0;
  
  char* directory = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int len = 26;
  /* A-Za-z: 0~51 */
  double records[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  };

  FILE *rs;
  if (argc > 1) {
    rs = fopen(argv[1], "r");
    if (!rs) {
      perror("EEXIST");
      return 1;
    }
  } else {
    rs = fdopen(0, "r");
  }

  while ((m = fgetc(rs)) != EOF)
    if ((m >= 65 && m <= 90) || (m >= 97 && m <= 122)) {
      t++;
      i = getIndex(m, directory, len);  
      records[i]++;
    }

  // output the probabilities from the char-stream
  for (i = 0; i < len; i++)
    printf("%lf\n", records[i] / t);

  fclose(rs);

  return 0;
}