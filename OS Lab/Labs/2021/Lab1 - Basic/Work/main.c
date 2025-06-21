#include "util.c"

int main(void)
{
  int sz;
  
  int fd = open("in.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  sz = write(fd, "hs8727sj8d9qbda017dnajsdo0p\n", strlen("hs8727sj8d9qbda017dnajsdo0p\n"));  
  close(fd);
  
  char* inText = (char *) calloc(100, sizeof(char));
  char* outText = (char *) calloc(100, sizeof(char));
  
  strcpy(inText, "in.txt");
  strcpy(outText, "out.txt");
  
  removeNonAlphabets(inText, outText);
  
  return 0;
}
