//Small implementation of running-key XOR cipher for encrypting/decrypting files with password

#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if(argc < 5 || strncmp(argv[1],"-h",2) == 0) {
		printf("Usage:\n%s [-h|-e|-d] input-file output-file password\nOptions\n-e\tEncrypt input-file with supplied password and write to output-file\n-d\tDecrypt input-file with supplied password and write to output-file\n-h\tPrint this help menu\n", argv[0]);
		return 1;
	}
	
	if(strncmp(argv[1],"-e",2) == 0 || strncmp(argv[1],"-d",2) == 0) {
		
		FILE *input = fopen(argv[2],"rb");
		if(input == NULL) {
			perror(argv[0]);
			return 1;
		}
		
		FILE *output = fopen(argv[3],"wb");
		if(output == NULL) {
			perror(argv[0]);
			return 1;
		}
		
		int i = 0;
		char c = 0;
		
		
		while((c = fgetc(input)) != EOF) {
			fputc(c ^ argv[4][i % strlen(argv[4])],output);
			i++;
		}
	}
	else
		printf("Invalid option\n");
	
	return 0;
}
