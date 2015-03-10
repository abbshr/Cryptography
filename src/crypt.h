int getIndex(char c, char* directory, int len) {
  int i = -1;
  while ((++i < len) && (directory[i] != c && directory[i] != (c + 32)));
  return i;
}

void genkey(char *key, int len, char* directory, int threhold) {
  int i = 0;
  while (i < len)
    key[i++] = directory[rand() % threhold];
  key[i] = '\0';
  return;
}
