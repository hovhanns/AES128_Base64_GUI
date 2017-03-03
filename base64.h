#ifndef BASE_64_H
#define BASE_64_H 

#ifdef __cplusplus
extern "C" {
#endif



#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *base_64_encode(char *line, int line_size);
int base_64_decode_len(const char *bufcoded);
char *base_64_decode(const char *bufcoded);

#ifdef __cplusplus
}
#endif


#endif
