#include<stdio.h>

main() {
    float list_of_values[5];
    int index;
    int compare_counter;
    
    index = 0;
    while (index < 5) {
        printf("Add a value:\n");
        scanf ("%f", &list_of_values[index]);
        index++;
    }
  
    index = 0;
    while (index < 5) {
        //int compare_counter = 1;
        int compare_counter = 0;
        
        while (compare_counter < 5) {
            /*
            if (list_of_values[index] < list_of_values[0])
            list_of_values[index]=list_of_values[0]; // the program needs to swap values; this is just overwriting the other values
            
            if (list_of_values[index] < list_of_values[1])
            list_of_values[index]=list_of_values[1]; // the program needs to swap values; this is just overwriting the other values
            
            if (list_of_values[index] < list_of_values[2])
            list_of_values[index]=list_of_values[2]; // the program needs to swap values; this is just overwriting the other values
            
            if (list_of_values[index] < list_of_values[3])
            list_of_values[index]=list_of_values[3]; // the program needs to swap values; this is just overwriting the other values
            
            if (list_of_values[index] < list_of_values[4])
            list_of_values[index]=list_of_values[4]; // the program needs to swap values; this is just overwriting the other values
            */
            if (list_of_values[compare_counter] < list_of_values[compare_counter+1]) {
                float temp = list_of_values[compare_counter+1];
                list_of_values[compare_counter+1] = list_of_values[compare_counter];
                list_of_values[compare_counter] = temp;
            }
            
        
        
            compare_counter++;   
        }
        printf("The list of values are: %.2f \n", list_of_values[index]); // this isn't displaying what you were intending
    
        index++;
        int check_counter;
        for(check_counter=0;check_counter<5;check_counter++) {
            printf("this is what the computer currently has as list_of_values[%d]: %f\n", check_counter, list_of_values[check_counter]);
        }
    }
    printf("after everything is done:\n");
    int check_counter;
    for(check_counter=0;check_counter<5;check_counter++) {
        printf("list_of_values[%d]: %f\n", check_counter, list_of_values[check_counter]);
    }
}