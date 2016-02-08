#include <stdio.h>
#define INPUTSIZE 20
#define RESULTSIZE 15
#define NUMSIZE 10
//argv[1] is the input file name
//argv[2] is the output file name

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Error. No Input file.\n");
		return 0;
	}
	int i,j;
	char input[INPUTSIZE];
	char result[RESULTSIZE];
	char ph_num[NUMSIZE];
	FILE *fp;
	fp = fopen(argv[1],"r");
	FILE *fw;
	if (argc == 2){
		fw = fopen("output.txt","w");
	}
	else if (argc == 3){
		fw = fopen(argv[2],"w");
	}
	if (fp != NULL) {
		while (fgets(input,20,fp) != NULL) {
			// For debug
			// printf("input %s\n", input);
			for (i=j=0; i<INPUTSIZE; i++) {
				if (input[i] >= '0' && input[i] <= '9') {
					ph_num[j] = input[i];
					j++;					
				}
			}
			//For debug
			// printf("ph_num %s\n", ph_num);
			result[0] = '(';
			result[1] = ph_num[0];
			result[2] = ph_num[1];
			result[3] = ph_num[2];
			result[4] = ')';
			result[5] = ' ';
			result[6] = ph_num[3];
			result[7] = ph_num[4];
			result[8] = ph_num[5];	
			result[9] = '-';
			result[10] = ph_num[6];
			result[11] = ph_num[7];
			result[12] = ph_num[8];	
			result[13] = ph_num[9];	
			//For debug
			// printf("%s\n", result);
			fwrite(&result,sizeof(result),1,fw);
			fwrite("\n",1,1,fw);
		}
		fclose(fw);
	}
	else {
		printf("File not exist.\n");
	}
	fclose(fp);
	return 0;
}