#include <stdio.h>
main() {
    double average;
    char continue_flag = 'y';
    double total_amount_of_numbers;
    int counter;
    int number;
    double total_numbers_entered;
    int maximum_number;
    int minimum_number;
    int second_number;

total_amount_of_numbers = 0;
total_numbers_entered = 0;
maximum_number = 0;
minimum_number = 0;
second_number = 0;

while(continue_flag == 'y') {
    printf("Enter any number:");
    scanf("%d", &number);
    printf("%d", number); 
    
    if(counter == 0) {
        maximum_number = number;
        minimum_number = maximum_number;
    }
    if(counter == 1) {
        second_number = number;
        if(maximum_number < second_number) {
            minimum_number = maximum_number;
            maximum_number = second_number;
        } else {
            if(maximum_number > second_number) {
                minimum_number = second_number;
            }
        } }
        
    if(maximum_number < number) {
        maximum_number = number;
    }
        
    if(minimum_number > number && maximum_number > minimum_number) {
        minimum_number = number;
    }
        
        
    counter = counter + 1;
    total_numbers_entered = ++total_numbers_entered;
    total_amount_of_numbers = total_amount_of_numbers + number;

    printf("\nWould you like to enter more numbers?\n");
    printf("Enter \"y\" to continue. Type any other character to exit\n");
    scanf(" %c", &continue_flag);
    
    }
    
    average = (total_amount_of_numbers / total_numbers_entered);
    printf("Average of all entered numbers: %.2f\n", average);
    printf("total_amount_of_numbers: %.2f\n", total_amount_of_numbers);
    printf("total_numbers_entered: %.2f\n", total_numbers_entered);
    printf("Maximum number entered: %d\n", maximum_number);
    printf("Minimum number entered: %d\n", minimum_number);

    
}