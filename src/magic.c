#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magic.h"
#include "magic_db.h"

int write_magic(char* out, char* in, char* magic)
{
  printf("changing %s to %s magic in %s file\n", in, magic, out);
  int index = get_type_index(magic);
  FILE* fp_in = fopen(in, "r");
  FILE* fp_out = fopen(out, "w");

  // set magic number
  for (unsigned short int i = 0; i < magic_data[index].size; i++)
    fputc(magic_data[index].code[i], fp_out);

  // padding
  fputs("\n\n", fp_out);

  // and the original content
  char cur;
  while ((cur = fgetc(fp_in)) != EOF)
    fputc(cur, fp_out);

  // padding
  fputs("\n\n", fp_out);
    
  return 0;
}

int get_type_index(char* magic)
{
  if (strcasecmp(magic, "png") == 0)
    return 0;
  else if (strcasecmp(magic, "jpg") == 0)
    return 1;
  else if (strcasecmp(magic, "zip") == 0)
    return 2;
  else if (strcasecmp(magic, "rpm") == 0)
    return 3;
  else if (strcasecmp(magic, "gif") == 0)
    return 4;

  return -1;
}


