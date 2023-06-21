#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char* builtins[] = {"cd", "hist", "help", "exit", "alias"};

int help(char **args)
{
  int i;
  printf("ByteShell Project by Naqiyah\n");
  printf("Type the name of programs and arguments , and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < sizeof(builtins) / sizeof(char *); i++) {
    printf("  %s\n", builtins[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}