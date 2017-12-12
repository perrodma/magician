#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "magic.h"

void usage(char* prg_name);

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    usage(argv[0]);
    return 1;
  }
  if (!strcasestr(MAGIC_IMPLEMENTED, argv[1]))
  {
    printf("Magic bytes not implemented or incorrect\n");
    return 2;
  }
  if (argc < 3 || access(argv[2], R_OK) == -1)
  {
    printf("source filename doesn't exist or not provided\n");
    return 3;
  }
  char* out_name = NULL;
  if (argc == 4)
  {
    out_name = malloc(sizeof(char) * (strlen(argv[3]) + 1));
    strncpy(out_name, argv[3], sizeof(char) * (strlen(argv[3]) + 1));
  }
  else
  {
    out_name = malloc(sizeof(char) * (strlen(argv[2] + 20)));
    strcpy(out_name, argv[2]);
    strcat(out_name, ".");
    strncat(out_name, argv[1], 20);
  }
  
  return write_magic(out_name, argv[2], argv[1]);

}


void usage(char* prg_name)
{
  printf("Usage : %s output_type source_file_name [new_file_name]\n", prg_name);
  printf("output type : png\n");
}
