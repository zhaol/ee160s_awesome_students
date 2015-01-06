/*   File:  display.c
//   By:    The Awesome Class of EE160
//   Date:	Today :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display_highscore.h"

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
  
  int loop = 1;
  int high_score = 0;
  
  char name_of_player[MAX_AMOUNT_OF_CHARACTERS];
  int list_of_high_scores[HIGHEST_SCORES_LISTED];

  SETUP_DISPLAY
  clear_screen();
  seed_random_generator(&x_item_position, &y_item_position);
  attacker_position (&y_attacker_position, &x_attacker_position);

  while (command != QUIT_KEY) { // a do..while loop would have been a nicer fit here; we will talk about the do..while loop later
    clear_screen();
    display_instructions();
    update_position(&x_position, &y_position, command);
    update_attacker_position(&x_attacker_position, &y_attacker_position, x_position, y_position, loop);
    display_position_and_highscore(x_position, y_position, x_item_position, y_item_position, x_attacker_position, y_attacker_position, high_score);
    high_score_tracker(&high_score, x_item_position, x_position, y_item_position, y_position, list_of_high_scores);
    redraw_screen(x_position, y_position, x_item_position, y_item_position, x_attacker_position, y_attacker_position);
    command = getchar(); // you should Google getchar and play around with this function to get comfortable with it
    
    loop++;
    if (loop == 3) { loop = 1; }
    
    if (y_item_position == y_position && x_item_position == x_position) {
				seed_random_generator(&x_item_position, &y_item_position);
				growing_score(list_of_high_scores, high_score);
				new_high_score(list_of_high_scores);
    }     
				
				if (y_attacker_position == y_position && x_attacker_position == x_position) {
                printf("\nGame Over\n");
                high_score_result(name_of_player, list_of_high_scores, high_score);  
                return;
                } 
                
    if (y_attacker_position == y_item_position && x_attacker_position == x_item_position) {
                printf("Game Over\n");
                return;
                }
                
                
    
    
  }
  
  BREAKDOWN_DISPLAY
  return 0;
}