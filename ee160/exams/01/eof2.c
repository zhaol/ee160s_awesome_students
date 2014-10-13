#include <stdio.h>

main(){
    int c, nblanks, ntabs, nnewlines;
    nblanks = ntabs = nnewlines = 0;

    printf("%d\n", EOF);

    while((c = getchar()) != EOF){
        printf("c = %d", c);
        switch(c){
            case ' ': 
                nblanks++;
                break;
            case '\t':
                ntabs++;
                break;
            case '\n':
                nnewlines++;
                break;
        }   
    }
    printf("blanks: %d\ntabs: %d\nnewlines: %d", nblanks, ntabs, nnewlines);
    printf("c = %d", c);
    return 0;
}