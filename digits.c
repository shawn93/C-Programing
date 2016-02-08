#include <stdio.h>
int main()
{
  int c, i, nwhite, nother;
  int ndigit[10];
  nwhite = nother = 0;
  for (i = 0; i < 10; ++i)
    //initialize the array elements to 0 
    ndigit[i]=  0;
  while ((c = getchar()) != '\n')
    if (c >= '0' && c <='9') //digits 0 to 9
      ++ndigit[c-'0'];
    else
      if (c ==' '||c=='\n'||c=='\t')  
	++nwhite; //white space
      else
	++nother; //others
  printf("digits =");
  for(i = 0; i < 10; ++i)
    printf("%d ", ndigit[i]);
  printf("\nwhite space %d, other =%d\n",nwhite,	nother);
}
