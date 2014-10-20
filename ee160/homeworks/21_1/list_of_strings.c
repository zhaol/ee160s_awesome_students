#include <stdio.h>

int main () {
  int i;

  char *names[] = {"Guy", "Girl", "Other Guy"};
  int starting_position_of_names[] = { 0, 4, 9 };
  char **pnames = names;

  for(i = 0; i < 3; i++) {
    printf("names[%d]: %s\n", i, names[i]);
    printf("&names[%d]: %p\n", i, &names[i]);
    printf("adress of pnames+%d: %p\n", i, (pnames+i));
    printf("%s\n", (*pnames)+starting_position_of_names[i]);
  }

  return 0;
}
