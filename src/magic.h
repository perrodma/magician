#ifndef MAGIC_H
  #define MAGIC_H

#define MAGIC_IMPLEMENTED "png jpg zip rpm gif"
#define MAX_CODE_SIZE 100
#define MAGIC_PNG "\x89\x50\x4e\x47\x0d\x0a\x1a\x0a\x00\x00\x00\x0d\x49\x48\x44\x52\x00\x00\x02\x80\x00\x00\x01\xe0\x08\x06\x00\x00\x00\x35\xd1\xdc\xe4\x00\x00\x00\x06\x62\x4b\x47\x44\x00\xff\x00\xff\x00\xff"
#define MAGIC_PNG_LEN 47

#define MAGIC_JPG "\xff\xd8\xff\xdb"
#define MAGIC_JPG_LEN 4

#define MAGIC_ZIP "PK\x03\x04\x0a\x00\x00\x00\x00\x00\xd5\x93\x8c\x4b\x5f\xd3\xb1\x48\x13\x00\x00\x00\x13\x00\x00\x00\x08\x00"
#define MAGIC_ZIP_LEN 28

#define MAGIC_RPM "\xed\xab\xee\xdb"
#define MAGIC_RPM_LEN 4

#define MAGIC_GIF "\x47\x49\x46\x38\x39\x61"
#define MAGIC_GIF_LEN 6

typedef struct magic_t {
  char code[MAX_CODE_SIZE];
  int size;
}magic_t;




int write_magic(char* out, char* in, char* magic);
int get_type_index(char* magic);

#endif // MAGIC_H


