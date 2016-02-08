#include <stdio.h>
#define STACK_SIZE 20

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty() {
    top=0;
}

int is_full() {
    return top==STACK_SIZE;
}

void push(int i)
{
  if(is_full()) 
    printf("stack overflow. The imput is not balanced.");
  else
    contents[top++]=i;
}

int is_empty() {
    return top ==0;
}

int pop(void)
{
  if(is_empty())
    return -1; //-1 means stack empty
  else
    return contents[--top];
}

int main(void) {

    int c, i, j, tmp, isbalanced;
    do {
        j = 0;
        printf("Enter your input that contains parenthesis or Q to quit:\n");
        while ((c = getchar()) != '\n') {
            j++;
            tmp = c;
            if(c == '(' || c == '<' || c == '[' || c == '{') {
                push(c);
                }
            if(c == ')' || c == '>' || c == ']' || c == '}') {
                if(c == ')' && pop() == '(') {
                    continue;
                    }
                else if(c == '>' && pop() == '<') {
                    continue;
                    }
                else if(c == ']' && pop() == '[') {
                    continue;
                    }
                else if(c == '}' && pop() == '{') {
                    continue;
                    }
                else {
                    top++;
                    isbalanced = 0;
                    }
                }
            }

        if(tmp == 'Q' && j ==1)
            return 0;
        if(top == 0)
            isbalanced = 1;
        else
            isbalanced = 0;        

        if(isbalanced == 1)
            printf("The input is balanced.\n");
        else
            printf("The input is not balanced.\n");
        make_empty();
    } 
    while (i >= 0);

    return 0;
}