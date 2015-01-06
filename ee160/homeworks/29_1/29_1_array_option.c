// NOTE: Using the modulus is more trustworthy and easier to read than using arrays, 
//       This is a memory intensive method.


#include <stdio.h>
#define LIMIT 800         
main() {
    int a = 1;      // a = counter for multiples of 5
    int b = 1;      // b = counter for multiples of 3
    int number_input;
    int number_counter = 0;
    
    int divisible_by_3[LIMIT];
    int divisible_by_5[LIMIT];
    
    printf("Please enter any positive integer:");
    scanf("%d", &number_input);
    

    for(number_counter=1;number_counter<=number_input;number_counter++) {
        divisible_by_3[b] = b*3; 
        divisible_by_5[a] = a*5;
        
        if(number_counter == divisible_by_5[a] && number_counter == divisible_by_3[b]){
            a++; b++; 
            printf("FizzBuzz\n");
            continue;}
        
        else if(number_counter == divisible_by_3[b]) {
            b++;
            divisible_by_3[b] = b*3; 
            printf("Fizz\n");  
            continue;} 
            
        else if(number_counter == divisible_by_5[a]) {
            a++;
            divisible_by_5[a] = a*5;
            printf("Buzz\n"); 
            continue;}
            
        if (number_counter != divisible_by_3[b] || number_counter != divisible_by_5[a]) {
            printf("%d\n", number_counter); }
    
    }
    
}