#ifndef AES_WITH_FILE
#define AES_WITH_FILE

#include "aes.h"
#ifdef __cplusplus
extern "C" {
#endif
int encrypt(char *file_path, char *key_path);
int decrypt(char *enc_file_path, char *key_path);
int generate_key(char *path);
#ifdef __cplusplus
}
#endif


#endif
