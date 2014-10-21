#include <stdio.h>
#include <string.h>

/* lower: convert c to lower case */
int lower(int c)
{
  char *Uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *Lowercase = "abcdefghijklmnopqrstuvwxyz";
  char *p = NULL;  //a NULL string
  p = strchr(Uppercase, c);
  printf("p points to %c\n", *p);
  if (NULL == p) {
    return c;
  } else {
    int uppercase_offset_from_A = p - Uppercase; // example: D is offset from A by 3 because D is 3 alphabets away from A
    printf("offset: %d\n", uppercase_offset_from_A);
    return *(Lowercase + uppercase_offset_from_A);
  }
}

int main () {
  printf("%c\n", lower('D'));
    
  return 0;
}


/* Notes:
I've replaced:
return NULL == (p = strchr(Uppercase, c)) ? c : *(Lowercase + (p - Uppercase));
with:
p = strchr(Uppercase, c); // #A
if (NULL == p) {
  return c;
} else {
  int uppercase_offset_from_A = p - Uppercase; // #B
  return *(Lowercase + uppercase_offset_from_A); #C
}
to break out what that one line is doing.

From there you can see that:
#A: p is set to the location of D
#B: subtracing p from Uppercase is essentially subtracting D from A and finding the number of alphabets in between (aka the offset)
#C: then you just add that same offset to Lowercase which is essentially counting the same number of alphabets from a
*/