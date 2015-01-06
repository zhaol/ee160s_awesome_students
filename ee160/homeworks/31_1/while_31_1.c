#include <stdio.h> 
#define ARRAY_OFFSET -1

main() {
    int MAX_NUMBER_OF_ROWS;
    int MAX_NUMBER_OF_COLUMNS;
    int rows = 0;
    int columns = 0;
    
    printf("How many rows are needed?\n");
    scanf("%d", &MAX_NUMBER_OF_ROWS);
    printf("How many columns are needed?\n");
    scanf("%d", &MAX_NUMBER_OF_COLUMNS);
//to the people who are highlighting everyingthing, can you at least unhighlight it soon so it's easier for others to view the code?
//kinda annoying having to read it when my entire screen is bright lime green

    //define this after user inputs 
    int table_of_values[MAX_NUMBER_OF_ROWS][MAX_NUMBER_OF_COLUMNS];
    
    while (rows <= MAX_NUMBER_OF_ROWS + ARRAY_OFFSET) {
        while(columns <= MAX_NUMBER_OF_COLUMNS + ARRAY_OFFSET) {
            
        printf("Please enter a value for: [%d][%d]\n", rows, columns);
        scanf("%d", &table_of_values[rows][columns]); 
        printf("[%d][%d]: %d\n", rows, columns, table_of_values[rows][columns]);
        
        columns++;
        }
    rows++;
    columns = 0;    // this resets the inner while loop
        
    }
    
    // repeats until entire loop ends when rows > MAX_NUMBER_OF_ROWS
    
    
    // aleeeexxxxxxx
    //what does the array offset do?
    // it just subtracts the original number input by one
    // Since arrays start at zero, the ARRAY_OFFSET keeps the counter(rows and columns) 
    // and the array balanced.
    //Okayyy thanks :D This makes so much more sense :)
    // no problem :3
    // I'm gonna post the for loop version 
    //okay :D
}