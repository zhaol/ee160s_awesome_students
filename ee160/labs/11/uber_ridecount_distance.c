#include <stdio.h>

int main () {
  FILE *input_file = fopen("datasets/uber_sample.tsv", "r");
  int ids[400];
  char datetime[100];
  float latitude[400];
  float longitude[400];
  
  if(input_file != NULL) {
    printf("File opened successfully\n");
    
    int index = 0;
    fscanf(input_file, "%d %s %f %f",
      &ids[index],
      datetime,
      &latitude[index],
      &longitude[index]);
    
    printf("ids: %d\n", ids[index]);
    printf("datetime: %s\n", datetime);
    printf("hour_text: %c%c\n", datetime[11], datetime[12]);
    printf("minute_text: %c%c\n", datetime[14], datetime[15]);
    printf("second_text: %c%c\n", datetime[17], datetime[18]);
    printf("x_positions: %f\n", latitude[index]);
    printf("y_positions: %f\n", longitude[index]);
    
    fclose(input_file);
  } else {
    printf("File failed to open\n");
  }
  
  return 0;
}