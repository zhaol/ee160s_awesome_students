#include <stdio.h>

int main () {
    char account_holder[10];
    account_holder[0] = 'b';
    if ((account_holder[0] >= 'a') && (account_holder[0] <= 'z')){
        account_holder[0] = account_holder[0] - 32;
    }
    printf("account_holder[0]: %c\n", account_holder[0]);
    return 0;
}