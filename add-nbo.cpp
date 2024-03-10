#include <stdio.h>
#include <stdint.h>
#include "add-nbo.h"

int main(int argc, char **argv){
	add_nbo(argv);
}
int myntohs(int a){
        int b = (a & 0xFF000000) >> 24;
        int c = (a & 0x00FF0000) >> 8;
	int d = (a & 0x0000FF00) << 8;
	int e = (a & 0x000000FF) << 24;
        return b|c|d|e;
}
uint32_t add_nbo(char **argv){
	
        FILE *fp1, *fp2;
        int num1[4],num2[4];
	int a,b;
	int res;
        fp1 = fopen(argv[1],"rb");
        fread(num1, 4, 1, fp1);

        fp2 = fopen(argv[2],"rb");
        fread(num2, 4, 1, fp2);
	
       	a = myntohs(num1[0]);
	b = myntohs(num2[0]);
	res = a+b;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a,a,b,b,res,res);
       
       	fclose(fp1);
        fclose(fp2);

	return 0;
}
