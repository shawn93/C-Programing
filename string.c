#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse(const char* s) {
    char *str;
    str = (char *) malloc(sizeof (char)* strlen(s));
    if(str == NULL) 
        return NULL; // heap exhausted
    int i = 0;
    while (i < strlen(s)) {
        str[i] = s[strlen(s) - 1 - i];
        i++;
    }

    return str;
}

char* drop(const char* s, char c) {
    char *str;
    int i,j;
    str = (char *) malloc(sizeof (char)* strlen(s));
    if(str == NULL) 
        return NULL; // heap exhausted
    for (i=0; i < strlen(s); i++) {
        str[i] = '\0';
    }
    for (i=0, j=0; i < strlen(s); i++) {
        if (s[i] != c) {
            str[j] = s[i];
            j++;
        }     
    }
    
    return str;
}

char* twice(const char* s) {
    char* result;
    result = (char *) malloc(sizeof (char)* (strlen(s)*2));
    if(result == NULL) 
        return NULL; // heap exhausted
    int j;
    int i = 0;
    while (i < strlen(s)*2) {
        j = i;
        if (i >= strlen(s))
            j = i - strlen(s);
        result[i] = s[j]; 
        i++;
    }

    return result;
}

int main(void) {
    char s[] = "quick"; 
    char* t = twice(s);
    printf("%s\n", t); 
    free(t);

    char u[] = "jumps over"; 
    char* r = reverse(u);
    printf("%s\n", r); 
    free(r);
    
    char v[] = "lazy dog"; 
    char* d = drop(v, 'o');
    printf("%s\n", d);
    free(d);
}
