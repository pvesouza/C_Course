#include <stdio.h>
#include <stdlib.h>

int sum_with_no_recursion(int n);
int sum_with_recursion(int n);
int mdc_no_recursion(int n1, int n2);
int mdc_recursion(int n1, int n2);
void reverse_string(const char *str);
void reverse_string_recursive(char *str);

const char *pedro = "pedro victor";

int main()
{
    int ch = '\0';

    do{
       printf("Enter a positive integer number\n");
       ch = getc(stdin);
       ch = ch - 48;
    }while(ch < 0);

    printf("The sum is %d\n", sum_with_no_recursion(ch));

    printf("The sum is %d\n", sum_with_recursion(ch));

    printf("The MDC is: %d\n", mdc_no_recursion(75, 45));

    printf("The MDC is: %d\n", mdc_recursion(75, 45));

    reverse_string(pedro);

    char str[100];

    fflush(stdin);

    scanf("%s", str);
    printf("%s\n", str);

    reverse_string_recursive(str);


    return 0;
}

int sum_with_no_recursion(int n) {
    int sum = 0;

    for (int i = 0; i <= n; i++) {
        sum = sum + i;
    }

    return sum;
}

int sum_with_recursion(int n) {

    if (n == 0){
        return 0;
    }
    int sum = n + sum_with_recursion(n - 1);
    printf("%d and %d\n", n, sum);
    return sum;
}

int mdc_no_recursion(int n1, int n2) {

    int mdc = 1;
    int greater = 0;
    int lesser = 0;

    if (n1 > n2) {
        greater = n1;
        lesser = n2;
    } else {
        greater = n2;
        lesser = n1;
    }

    mdc = lesser;
    while(greater % lesser != 0) {
         mdc = greater % lesser;
         greater = lesser;
         lesser = mdc;
    }
    return mdc;
}

int mdc_recursion(int n1, int n2) {
    int mdc = 1;

    if (n1 > n2) {
        mdc = n1 % n2;
        if (mdc == 0){
            return n2;
        }

        mdc = mdc_recursion(n2, mdc);
        return mdc;

    } else {
        mdc = n2 % n1;
        if (mdc == 0){
            return n1;
        }

        mdc = mdc_recursion(n1, mdc);
        return mdc;
    }
}

void reverse_string(const char *str){
    int count = 0;
    char ch = '\0';

    for (ch = str[0]; ch != '\0'; count++){
        ch = str[count];
        printf("%c", ch);
    }

    printf("\n");

    for (int i = count - 2; i >=0 ; i--){
        printf("%c", str[i]);
    }

    printf("\n");
}

void reverse_string_recursive(char *str){
    static int i = 0;
    char ch = *str;
    i++;
    // Stop condition
    if (ch == '\0'){
        printf("\n");
        return;
    }
    reverse_string_recursive(str + 1);
    if (ch != '\0')
        printf("%c", ch);
    return ;
}
