#ifndef MAGIC_DB_H
  #define MAGIC_DB_H

struct magic_t magic_data[3] = {{.size = MAGIC_PNG_LEN, .code = MAGIC_PNG}, {.size = MAGIC_JPG_LEN, .code = MAGIC_JPG}, {.size= MAGIC_ZIP_LEN, .code = MAGIC_ZIP}};

#endif // MAGIC_DB_H
