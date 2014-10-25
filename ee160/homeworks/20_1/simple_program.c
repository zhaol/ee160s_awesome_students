#include<stdio.h>

main() {
    float max[5];
    int index;
    int compared;
    
    index = 0;
    while (index < 5) {
        printf("Add a value:\n");
        scanf ("%f", &max[index]);
        index++;
    }
  
    index = 0;
    while (index < 5) {
        int compared = 1;
        
        while (compared < 5) {
            printf("DEBUG: %f, %f, %f, %f, %f\n", max[0], max[1], max[2], max[3], max[4]);
            if (max[compared] < max[compared + 1]) {
                int temp = max[compared];
                max[compared] = max[compared + 1];
                max[compared + 1] = temp;
            }
    
            compared++;   
        }
        
        index++;
    }
    printf("The number is: %f \n", max[0]);
    printf("The number is: %f \n", max[1]);
    printf("The number is: %f \n", max[2]);
    printf("The number is: %f \n", max[3]);
    printf("The number is: %f \n", max[4]);
}