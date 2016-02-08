/* squeeze: delete all c from s */ 
#include <stdio.h>
int main(void)
{
  char s[]="warning";
  char c='n';
  printf("before delete: %s\n",s);
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i]; //s[++j]=s[i]?
  s[j] = '\0';

  printf("after delete: %s\n",s);
}
