#ifndef _BASE_64_WITH_FILE
#define _BASE_64_WITH_FILE
#include "base64.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

int encode_base_64(char *file_path);
int decode_base_64(char *file_path);

#ifdef __cplusplus
}
#endif

#endif
