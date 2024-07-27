#include <stdio.h>

int main(int argc, char **argv)
{
  printf("Hello %s!\n", "world");

  /* Watch this! Gcc changes this printf call to puts("So long!"). YOW! */
  printf("So long!\n");

  return 0;
}
