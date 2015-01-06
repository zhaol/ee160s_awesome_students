// this is not finished, but hopefully someone else could figure it out
// I think you might have to use a 2D Array instead



#include <stdio.h>
#define MAX_COLUMNS 15
#define ARRAY_OFFSET -1
#define ARRAY_ADDITION 1

main() {
    
    int index;
    int delta;
    char matrix[MAX_COLUMNS];
    
    FILE *file_pointer;
    file_pointer = fopen("31_2_input.txt", "r");
    
    if (file_pointer == NULL) {
        printf("Error opening file\n");
    } else {
        printf("Successfully opened file\n");
    
    
        while (fscanf(file_pointer, "%s", matrix) != EOF) {
            
        for(index=0;index<=MAX_COLUMNS;index++) {
            delta = MAX_COLUMNS;
            
            // this just helped me keep track of the array
            // printf("[%d]", index)
            
            // this entered a new row after array reached MAX_COLUMNS
            if(index==delta) {printf("\n"); delta+=delta;}
            
            
            if(matrix[index] == 'O') {
                printf("_"); } 
            else if(matrix[index] == 'X') {
                    printf("X"); }
            
            // this avoided printing out the extra spaces    
            else { continue; }
                }
            }
        }
    
}