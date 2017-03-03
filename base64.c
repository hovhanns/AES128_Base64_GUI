#include "base64.h"
static const char basis_64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static const unsigned char pr2six[256] =
{
    /* ASCII table */
  /*1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	*/
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,	//1
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,	//2
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 62, 64, 64, 64, 63,	//3
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 64, 64, 64, 64, 64, 64,	//4
    64,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,	//5
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 64, 64, 64, 64, 64,	//6
    64, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,	//7
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 64, 64, 64, 64, 64,	//8
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,	//9
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,	//10
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,	//11
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,	//12
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,	//13
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,	//14
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,	//15
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64	//16
};

char *base_64_encode(char *line, int line_size)
{
    if (!line)
    {
        printf("pass non NULL line\n");
        return NULL;
    }
    int i = 0;
    //int line_size = 0;
    //line_size = strlen(line);
    char *encoded = NULL;

    int encoded_size = (line_size/3)*4;
    encoded_size+= (line_size%3)==0?0:4;

    encoded = (char*) calloc( encoded_size, sizeof(char) );

    for (i = 0; i < line_size-2; i+=3)
    {
        *encoded++ = basis_64[(line[i] >> 2) & 0x3F];
        *encoded++ = basis_64[((line[i] & 0x3) << 4) |
                                ((int) (line[i + 1] & 0xF0) >> 4)];
        *encoded++ = basis_64[((line[i + 1] & 0xF) << 2) |
                            ((int) (line[i + 2] & 0xC0) >> 6)];
        *encoded++ = basis_64[line[i + 2] & 0x3F];
    }

    if (i < line_size)
    {
        *encoded++ = basis_64[(line[i] >> 2) & 0x3F];
        if (i == (line_size - 1))
        {
            *encoded++ = basis_64[((line[i] & 0x3) << 4)];
            *encoded++ = '=';
        }
        else
        {
            *encoded++ = basis_64[((line[i] & 0x3) << 4) |
                                    ((int) (line[i + 1] & 0xF0) >> 4)];
            *encoded++ = basis_64[((line[i + 1] & 0xF) << 2)];
        }
        *encoded++ = '=';
    }
    *encoded = '\0';
    encoded-=encoded_size;

    return encoded;

}

int base_64_decode_len(const char *bufcoded)
{
    int nbytesdecoded;
    register const unsigned char *bufin;
    register int nprbytes;

    bufin = (const unsigned char *) bufcoded;
    while (pr2six[*(bufin++)] <= 63);

    nprbytes = (bufin - (const unsigned char *) bufcoded) - 1;
    nbytesdecoded = ((nprbytes + 3) / 4) * 3;

    printf("len - %d\n", nbytesdecoded + 1);
    return nbytesdecoded + 1;
}


char *base_64_decode(const char *bufcoded)
{
    int nbytesdecoded;
    register const unsigned char *bufin;
    register unsigned char *bufout;
    register int nprbytes;

    bufin = (const unsigned char *) bufcoded;
    while (pr2six[*(bufin++)] <= 63);
    nprbytes = (bufin - (const unsigned char *) bufcoded) - 1;
    nbytesdecoded = ((nprbytes + 3) / 4) * 3;

    bufout = (unsigned char *)calloc(base_64_decode_len(bufcoded), sizeof(char));

    bufin = (const unsigned char *) bufcoded;

    while (nprbytes > 4)
    {
        *(bufout++) =
        (unsigned char) (pr2six[*bufin] << 2 | pr2six[bufin[1]] >> 4);
        *(bufout++) =
        (unsigned char) (pr2six[bufin[1]] << 4 | pr2six[bufin[2]] >> 2);
        *(bufout++) =
        (unsigned char) (pr2six[bufin[2]] << 6 | pr2six[bufin[3]]);
        bufin += 4;
        nprbytes -= 4;
    }

    /* Note: (nprbytes == 1) would be an error, so just ingore that case */
    if (nprbytes > 1)
    {
        *(bufout++) =
        (unsigned char) (pr2six[*bufin] << 2 | pr2six[bufin[1]] >> 4);
    }
    if (nprbytes > 2)
    {
        *(bufout++) =
        (unsigned char) (pr2six[bufin[1]] << 4 | pr2six[bufin[2]] >> 2);
    }
    if (nprbytes > 3)
    {
        *(bufout++) =
        (unsigned char) (pr2six[bufin[2]] << 6 | pr2six[bufin[3]]);
    }

    *(bufout++) = '\0';
    nbytesdecoded -= (4 - nprbytes) & 3;
    *(bufout-=nbytesdecoded+1);


    return bufout;


    //return nbytesdecoded;
}
