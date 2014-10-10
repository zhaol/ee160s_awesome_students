#include <stdio.h>

main() {
    
    double first_number;
    double second_number;
    double user_input;
    double sum;
    int counter;
    
    sum = 0;
    counter = 1;
    
    printf ("Enter a number to specify how many inputs you'll be summing: \n");
    scanf ("%lg", &user_input);
    printf ("You have %lg numbers to input. \n", user_input);
    while (counter < user_input) {
        printf ("Enter a number to add: ");
        scanf ("%lg", &first_number);
        
        sum = sum + first_number;
        counter = counter + 1;
    }
    printf ("Enter your final number to add: ");
    scanf ("%f", &second_number);
    sum = sum + second_number;
    printf ("The sum of all numbers is %lg \n", sum);
    
}

//Lab based on how many inputs user designates. If input is 3, User can add 3 numbers