#include <stdio.h>

main () {
    
    char azusa[10];
    int nakano;
    char ami;
    int mami;
    
    
    printf("Enter word: ");
    scanf(" %s", &azusa[0]);
    
    for (nakano = 0; nakano < 9; nakano++) {
        printf("===\n");
        for (mami = nakano + 1; mami < 9; mami++) {
            if (azusa[nakano] > azusa[mami]) {
                ami = azusa[nakano];
                azusa[nakano] = azusa[mami];
                azusa[mami] = ami;
                printf("ami: %c\n", ami);
                printf("%s\n", azusa);
                printf("azusa[nakano]: %c\n", azusa[nakano]);
                printf("azusa[mami]: %c\n", azusa[mami]);
                printf("mami: %d\n", mami);
                printf("nakano: %d\n", nakano);
            }
        }
    }
    
    for (nakano = 0; nakano < 9; nakano++) {
        printf("%c", azusa[nakano]);
    }
    printf("\n");
    printf("%s", azusa);
}