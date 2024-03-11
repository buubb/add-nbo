#include <stdio.h>
#include <stdint.h>
#include "add-nbo.h"

int main(int argc, char **argv){
	if (argc <= 2){
		printf("Input: ./add-nbo <file1> <file2>, Try again\n");
	}else{	
		add_nbo(argv);
	}
}
uint32_t myhtonl(uint32_t a){
	uint32_t b = (a & 0xFF000000) >> 24;
        uint32_t c = (a & 0x00FF0000) >> 8;
	uint32_t d = (a & 0x0000FF00) << 8;
	uint32_t e = (a & 0x000000FF) << 24;
        return b|c|d|e;
}
uint32_t add_nbo(char **argv){
	FILE *fp1, *fp2;
        uint8_t num1[4],num2[4];
	uint32_t a,b;
	uint32_t res;
	
	fp1 = fopen(argv[1],"rb");
	fp2 = fopen(argv[2],"rb");

        if (fp1 == NULL or fp2 == NULL){
		printf("File open failed..\n");
		return 1;
	}

	fread(num1, 1, 4, fp1);
	int fileLength1 = ftell(fp1);

        fread(num2, 1, 4, fp2);
	int fileLength2 = ftell(fp2);
	

	uint32_t* p1 = reinterpret_cast<uint32_t*>(num1);
	uint32_t* p2 = reinterpret_cast<uint32_t*>(num2);
	
       	a = myhtonl(*p1);
	b = myhtonl(*p2);
	res = a+b;
	
	if (fileLength1 < 4 or fileLength2 < 4){
		printf("File size is small than 4bytes.\n");
	}	
	else{
		printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a,a,b,b,res,res);
	}

       	fclose(fp1);
        fclose(fp2);

	return 0;
}
