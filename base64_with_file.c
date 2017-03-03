#include "base64_with_file.h"
#include <string.h>
int encode_base_64(char *file_path)
{
    if(file_path==NULL)
    {
        printf("file_path is null\n");
        return -1;
    }
    FILE *fp_in;
    FILE *fp_out;
    char *fp_out_path = NULL;
    int f_size = 0;
    unsigned char buffer[301];
    memset(buffer, '\0', 301);
    fp_in = fopen(file_path, "r");
    if (fp_in==NULL)
    {
        printf("can't open input file\n");
        return -1;
    }

    fseek(fp_in, 0L, SEEK_END);
    f_size = ftell(fp_in);
    fseek(fp_in, 0L, SEEK_SET);

    fp_out_path = (char*)calloc(strlen(file_path) + 5, sizeof(char));
    if (fp_out_path==NULL)
    {
        printf("can't allocate memory\n");
        return -1;
    }
    strcpy(fp_out_path, file_path);
    strcat(fp_out_path, ".b64");
    fp_out = fopen(fp_out_path, "w");
    if (fp_out==NULL)
    {
        printf("can't open file\n");
        return -1;
    }

    int i;
    for (i = 0; i < f_size  - f_size%300; i+=300)
    {
        printf("%d\n", i);
        fread(buffer, 1, 300, fp_in);
        char *enc_msg = NULL;
        enc_msg = base_64_encode(buffer, 300);
        if (enc_msg==NULL)
        {
            printf("enc is null!\n");
            return -1;
        }
        fwrite(enc_msg, sizeof(char), strlen(enc_msg), fp_out);
        memset(buffer, '\0', 301);

        free(enc_msg);
    }

    fread(buffer, 1, f_size % 300, fp_in);
    char *enc_msg = NULL;
    enc_msg = base_64_encode(buffer,  f_size % 300);
    if (enc_msg==NULL)
    {
        printf("enc is null!\n");
        return -1;
    }
    fwrite(enc_msg, sizeof(char), strlen(enc_msg), fp_out);


    fclose(fp_in);
    fclose(fp_out);
    return 0;


}
int decode_base_64(char *file_path)
{

    if(file_path==NULL)
    {
        printf("file_path is null\n");
        return -1;
    }
    FILE *fp_in;
    FILE *fp_out;
    char *fp_out_path = NULL;
    int f_size = 0;
    unsigned char buffer[401];
    memset(buffer, '\0', 401);
    fp_in = fopen(file_path, "r");
    if (fp_in==NULL)
    {
        printf("can't open input file\n");
        return -1;
    }

    fseek(fp_in, 0L, SEEK_END);
    f_size = ftell(fp_in);
    fseek(fp_in, 0L, SEEK_SET);

    fp_out_path = (char*)calloc(strlen(file_path) + 7, sizeof(char));
    if (fp_out_path==NULL)
    {
        printf("can't allocate memory\n");
        return -1;
    }
    strcpy(fp_out_path, file_path);
    strcat(fp_out_path, ".b64-d");
    fp_out = fopen(fp_out_path, "w");
    if (fp_out==NULL)
    {
        printf("can't open file\n");
        return -1;
    }
    int i;
    for (i = 0; i < f_size  - f_size%400; i+=400)
    {
        fread(buffer, sizeof(char), 400, fp_in);
        char *dec_msg = NULL;
        dec_msg = base_64_decode(buffer);
        if (dec_msg==NULL)
        {
            printf("enc is null!\n");
            return -1;
        }
        fwrite(dec_msg, sizeof(char), 300, fp_out);
        memset(buffer, '\0', 401);
        free(dec_msg);
    }

    fread(buffer, sizeof(char), f_size%400, fp_in);
    int dec_len = base_64_decode_len(buffer);
    char *dec_msg = NULL;
    dec_msg = base_64_decode(buffer);
    if (dec_msg==NULL)
    {
        printf("enc is null!\n");
        return -1;
    }
    fwrite(dec_msg, sizeof(char),dec_len, fp_out);

    fclose(fp_out);
    fclose(fp_in);
    return 0;

}
