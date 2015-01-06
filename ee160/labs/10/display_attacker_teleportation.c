/*   File:  display.c
//   By:    The Awesome Class of EE160
//   Date:	Today :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display_attacker_teleportation.h"

// This program provides the basic foundations to all future game type lab assignments in EE160
int main () {
  int i;
  char command;
  int x_position = HORIZONTAL_START;
  int y_position = VERTICAL_START;
  int x_item_position;
  int y_item_position;
  int x_attacker_position;
  int y_attacker_position;

  SETUP_DISPLAY
  clear_screen();
  seed_random_generator(&x_item_position, &y_item_position);
  attacker_position (&y_attacker_position, &x_attacker_position);

  while (command != QUIT_KEY) { // a do..while loop would have been a nicer fit here; we will talk about the do..while loop later
    clear_screen();
    display_instructions();
    update_position(&x_position, &y_position, command);
    update_attacker_position(&x_attacker_position, &y_attacker_position, x_position, y_position);
    
    display_position(x_position, y_position, x_item_position, y_item_position, x_attacker_position, y_attacker_position);
    
    redraw_screen(x_position, y_position, x_item_position, y_item_position, x_attacker_position, y_attacker_position);
    command = getchar(); // you should Google getchar and play around with this function to get comfortable with it
    
    if (y_item_position == y_position && x_item_position == x_position) {
				seed_random_generator(&x_item_position, &y_item_position);
                } 
    if (y_attacker_position == y_position && x_attacker_position == x_position) {
                printf("Game Over\n");
                return;
                } 
  }
  
  BREAKDOWN_DISPLAY
  return 0;
}