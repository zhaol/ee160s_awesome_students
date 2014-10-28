#include <stdio.h>
#define CONTINUE_PROGRAM 'n'

// Please don't use global variables
int your_age;
char exit_program = CONTINUE_PROGRAM;

int main(){
    while(exit_program == CONTINUE_PROGRAM){
        printf("Enter your age:\n");
        scanf("%d", &your_age);
        printf("Your age is %d.\n", your_age);
        printf("Are you done checking your age?\n");
        printf("Press 'n' to continue..otherwise click other character to cancel.\n");
        // had to change from this:
        // scanf(" %c", &exit_program);
        // to this:
        scanf(" %c", &exit_program);
        //return("%c", exit_program); // not sure what you are trying to accomplish here
    }
}