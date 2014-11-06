#include <stdio.h>

int main(){

  FILE *file_pointer = fopen("23_1_lyrics.txt", "r");
  char text1[4];
  int counter;
  
  if(file_pointer == NULL) {
    printf("error opening file\n");
  } else {
    printf("file opened\n");
    
    int fscanf_return;
    while(fscanf_return != EOF) {
      fscanf_return = fscanf(file_pointer, "%s", text1);
      printf(" DEBUG: fscanf returns: %d\n", fscanf_return);
      printf("%s", text1);
    }
    
    fclose(file_pointer);
  }
  return 0;
}