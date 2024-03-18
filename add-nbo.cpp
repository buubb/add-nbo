#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t add_nbo(char *argv){
	FILE *fp;
        uint32_t num;
	uint32_t a;
	
	fp = fopen(argv,"rb");

        if (fp == NULL){
		printf("File open failed..\n");
		return 1;
	}

	fread(&num, 1, 4, fp);
	int fileSize = ftell(fp);

	if (fileSize < 4){
		printf("File size is small than 4bytes.\n");
		return 1;
	}

	a = ntohl(num);

	return a;
}

int main(int argc, char *argv[]){
        uint32_t a,b,res;
        if (argc <= 2){
                printf("Input: ./add-nbo <file1> <file2>, Try again\n");
        }else{
                a = add_nbo(argv[1]);
                b = add_nbo(argv[2]);
                res = a+b;
                printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a,a,b,b,res,res);
        }
}
