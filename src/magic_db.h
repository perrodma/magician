#ifndef MAGIC_DB_H
  #define MAGIC_DB_H

struct magic_t magic_data[5] = {{.size = MAGIC_PNG_LEN, .code = MAGIC_PNG}, {.size = MAGIC_JPG_LEN, .code = MAGIC_JPG}, {.size = MAGIC_ZIP_LEN, .code = MAGIC_ZIP}, {.size = MAGIC_RPM_LEN, .code = MAGIC_RPM}, {.size = MAGIC_GIF_LEN, .code = MAGIC_GIF}};

#endif // MAGIC_DB_H
