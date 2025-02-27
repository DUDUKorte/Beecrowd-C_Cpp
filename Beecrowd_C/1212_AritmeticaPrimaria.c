#include <stdio.h>
#include <string.h>

int main(){

    char num1[11], num2[11];

    while(scanf("%s %s", num1, num2) && num1[0] != '0' || num2[0] != '0'){
        int len1 = strlen(num1);
        int len2 = strlen(num2);
        int carry = 0;

        int i = len1 - 1, j = len2 - 1;

        while(i >= 0 && j >= 0){
            int sum = (num1[i] - '0') + (num2[j] - '0');
            if(sum >= 10){
                carry++;
            }
            i--;
            j--;
        }

        if(carry == 0){
            printf("No carry operation.\n");
        }else{
            printf("%d carry operations.\n", carry);
        }
        
    }

    return 0;
}

