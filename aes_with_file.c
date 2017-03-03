#include "aes_with_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 16*64+1
int encrypt(char *file_path, char *key_path)
{
	int input_file_size = -1;
	int i = 0;
    unsigned char arr_key[17];
    unsigned char arr_in[17];
    unsigned char arr_output[17];
	char *output_path = NULL;
	FILE *fp_input;
	FILE *fp_key;
	FILE *fp_output;
    memset(arr_key, 0, 17);
    memset(arr_in, 0, 17);
    memset(arr_output, 0, 17);

	fp_input = fopen(file_path, "r");
	if (fp_input==NULL)
	{
		printf("Can't open input file\n");
		return -1;
	}

	fp_key = fopen(key_path, "r");
	if (key_path==NULL)
	{
		printf("Can't open key file\n");
		return -1;
	}

	output_path =  calloc(strlen(file_path) + 5,sizeof(char));
	if (output_path==NULL)
	{
		printf("can't allocate memory\n");
		return -1;
	}

	strcpy(output_path, file_path);
	strcat(output_path, ".aes");

	fp_output = fopen(output_path, "w");
	if (fp_output==NULL)
	{
		printf("can't open output file\n");
		return -1;
	}

	

	fseek(fp_input, 0L, SEEK_END);
	input_file_size = ftell(fp_input);
	fseek(fp_input, 0L, SEEK_SET);	

	fread(arr_key, sizeof(char), 16, fp_key);	

	
	for (i = 0; i < input_file_size - input_file_size%16; i+=16)
	{
		fread(arr_in, sizeof(char),16, fp_input);		
		AES128_encrypt(arr_in, arr_key, arr_output);
		fwrite(arr_output, sizeof(char), 16, fp_output);
		memset(arr_in, 0, 16);
		memset(arr_output, 0, 16);
	}

	fread(arr_in, sizeof(char), input_file_size-i, fp_input);
	AES128_encrypt(arr_in, arr_key, arr_output);
    fwrite(arr_output, sizeof(char), input_file_size-i, fp_output);

	fclose(fp_input);
	fclose(fp_output);
	fclose(fp_key);
	


	return 0;
}

int decrypt(char *enc_file_path, char *key_path)
{
	int input_file_size = -1;
	int i = 0;
    unsigned char arr_key[17];
    unsigned char arr_in[17];
    unsigned char arr_output[17];
	char *output_path = NULL;
	FILE *fp_input;
	FILE *fp_key;
	FILE *fp_output;
	memset(arr_key, 0, 17);
	memset(arr_in, 0, 17);
	memset(arr_output, 0, 17);	

	fp_input = fopen(enc_file_path, "r");
	if (fp_input==NULL)
	{
		printf("Can't open input file\n");
		return -1;
	}

	fp_key = fopen(key_path, "r");
	if (key_path==NULL)
	{
		printf("Can't open key file\n");
		return -1;
	}

    output_path =  calloc(strlen(enc_file_path) + 7,sizeof(char));
	if (output_path==NULL)
	{
		printf("can't allocate memory\n");
		return -1;
	}

    strcpy(output_path, enc_file_path);
    strcat(output_path, ".aes-d");

	fp_output = fopen(output_path, "w");
	if (fp_output==NULL)
	{
		printf("can't open output file\n");
		return -1;
	}

	fread(arr_key, sizeof(char), 16, fp_key);


	fseek(fp_input, 0L, SEEK_END);
	input_file_size = ftell(fp_input);
	fseek(fp_input, 0L, SEEK_SET);
	printf("input file size: %d\n", input_file_size);


	for (i = 0; i < input_file_size - input_file_size%16; i+=16)
	{
		fread(arr_in, sizeof(char),16, fp_input);		
		AES128_decrypt(arr_in, arr_key, arr_output);
        fwrite(arr_output, sizeof(char), 16, fp_output);
        memset(arr_in, 0, 17);
        memset(arr_output, 0, 17);
	}

    fread(arr_in, sizeof(char), 16, fp_input);
    if(arr_in[0]!='\0')
    {
        AES128_decrypt(arr_in, arr_key, arr_output);
        fwrite(arr_output, sizeof(char), 16, fp_output);
      /*int j = 0;
        while(j < input_file_size%16)
        {
            fwrite(arr_output[j++], sizeof(char), (size_t)1, fp_output); /// todo fix this
        }*/
    }

    fclose(fp_input);
    fclose(fp_output);
    fclose(fp_key);
    return 0;
}
int generate_key(char *path)
{
    srand(time(NULL));
    FILE *fp = NULL;
    fp = fopen(path, "w");
    if(fp==NULL)
    {
        printf("can't open file");
        return -1;
    }

    unsigned char ch[16];
    int i = 0;
    for(i = 0; i<16; i++)
    {
        ch[i] = rand()%200 + 1;
        ch[i] += 30;
    }
    fwrite(ch,sizeof(char),16,fp);

    fclose(fp);
    return 0;
}
