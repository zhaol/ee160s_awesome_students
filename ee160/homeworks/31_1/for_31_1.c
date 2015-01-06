#include <stdio.h>
#define ARRAY_OFFSET -1

main() {
    int columns;                
    int rows;               
    int max_rows;
    int max_columns;
    
    printf("How many rows are needed?\n");
    scanf("%d", &max_rows);
    printf("How many columns are needed?\n");
    scanf("%d", &max_columns);
    
    int table_of_values[max_rows][max_columns];
        
        for(rows=0; rows<=max_rows+ARRAY_OFFSET; rows++) {
            for(columns=0; columns<=max_columns+ARRAY_OFFSET; columns++) {
        
        printf("Please enter a value for: [%d][%d]\n", rows, columns);
        scanf("%d", &table_of_values[rows][columns]); 
        printf("[%d][%d]: %d\n", rows, columns, table_of_values[rows][columns]);
            }
        }
    }
        
    // EDIT: If you want to summarize the values at the end, then you need this part
    
    /*      for(rows=0; rows<=max_rows+ARRAY_OFFSET; rows++) {
            for(columns=0; columns<=max_columns+ARRAY_OFFSET; columns++) {
            printf("[%d][%d]: %d\n", rows, columns, table_of_values[rows][columns]); }
            }
    */
