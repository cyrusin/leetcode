#include <stdio.h>

int IsSpace(const char *s);
int IsDigit(const char *s);

int StringToInt(const char *s){
    if (s==NULL){
        return 0;
    }

    while (IsSpace(s)){
        ++s;
    }

    int sign = 1;

    if (*s == '-') {
        sign = -1;
        ++s;
    }

    if (!IsDigit(s)){
        return 0;
    }

    unsigned int MAX;
    if (sign > 0){
        MAX = ((unsigned)~0)>>1;
    }else{
        MAX = -(((unsigned)~0)>>1) - 1;
    }

    unsigned int result = 0;
    while(*s != '\0'){
        unsigned int c = *s - '0';
        if ((result > MAX/10) || ((result == MAX/10) && (c > MAX%10))){
            result = MAX;
            break;
        }
        result = result * 10 + c;
        ++s;
    }

    if (sign > 0){
        return result;
    }else{
        return -result;
    }
}

int IsSpace(const char *s){
    return *s == ' ';
}

int IsDigit(const char *s){
    return *s >= '0' && *s <= '9';
}

int main(int argc, char *argv[]){
    char string[] = "123456";
    int int_s = StringToInt(string);
    printf("string: 123456, int: %d\n", int_s);

    char string1[] = "-123346";
    int int_s1 = StringToInt(string1);
    printf("string1: -123456, int: %d\n", int_s1);

    int MAX_P = ((unsigned)~0)>>1;
    printf("MAX POS: %d\n", MAX_P);
    int MAX_N = -(((unsigned)~0)>>1)-1;
    printf("MAX NEG: %d\n", MAX_N);

    char string2[] = "2147483647";
    int int_s2 = StringToInt(string2);
    printf("string2: 2147483647, int: %d\n", int_s2);

    char string3[] = "-2147483648";
    int int_s3 = StringToInt(string3);
    printf("string3: -21474836478, int: %d\n", int_s3);

    char string4[] = "21474836479";
    int int_s4 = StringToInt(string4);
    printf("string4: 21474836479, int: %d\n", int_s4);

    char string5[] = "-21474836479";
    int int_s5 = StringToInt(string5);
    printf("string5: -21474836479, int: %d\n", int_s5);


}
