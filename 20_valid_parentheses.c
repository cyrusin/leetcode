#include <stdio.h>

#define bool char
#define false 0
#define true 1

bool isValid(char *s){
    if (s == NULL){
        return false;
    }

    int size = 0;
    char *p = s;
    while (*p++ != '\0'){
        size++;
    }

    if (size < 2){
        return false;
    }
    char stack[size];
    int top = -1;
    p = s;
    while (*p != '\0'){
        if (*p == '(' || *p == '{' || *p == '['){
            printf("Push stack: %c\n", *p);
            stack[++top] = *p;
            p++;
            continue;
        }
        if (*p == ')'){
            if (top < 0){
                return false;
            }else{
                if (stack[top] == '('){
                    top--;
                    p++;
                    continue;
                }else{
                    return false;
                }
            }
        }
        if (*p == ']'){
            if (top < 0){
                return false;
            }else{
                if (stack[top] == '['){
                    top--;
                    p++;
                    continue;
                }else{
                    return false;
                }
            }
        }
        if (*p == '}'){
            if (top < 0){
                return false;
            }else{
                if (stack[top] == '{'){
                    top--;
                    p++;
                    continue;
                }else{
                    return false;
                }
            }
        }
        p++;
    }
    if (top >= 0){
        return false;
    }
    return true;
}

int main(void){
    char s[] = "(])";
    printf("%s\n", s);
    bool result = false;
    result = isValid(s);
    if (result == true)
        printf("valid\n");
    else
        printf("not valid\n");
    return 0;
}
