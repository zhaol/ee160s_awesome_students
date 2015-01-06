void clear_screen () {
  int i;
  for (i=1; i <= SCREEN_HEIGHT; i++) {
    printf ("\n");
  }
}

void seed_random_generator (int *y_item_position, int *x_item_position) {
  srand(time(NULL)); // This is needed so the random generator function, rand(), generates different random numbers each time the program starts
  
  *y_item_position = rand()%29+1;
	*x_item_position = rand()%16+2;
}

void attacker_position (int *y_attacker_position, int *x_attacker_position) {
    srand(time(NULL));
        
  *y_attacker_position = rand()%10+2;
	*x_attacker_position = rand()%20+2;
}

void display_position(int x_position, int y_position, int x_item_position, int y_item_position, int x_attacker_position, int y_attacker_position) {
  printf("Current Position: x: %d, y: %d\n", x_position, y_position);
  printf("Money Position: x: %d, y: %d\n", x_item_position, y_item_position);
  printf("Attacker Position: x: %d, y: %d\n", x_attacker_position, y_attacker_position);
    
}

void display_instructions() {
  printf("Press 'w' to go UP, 's' to go DOWN, 'a' to go LEFT, 'd' to go RIGHT, and 'q' to quit\n");
}

void update_position(int* x_position_pointer, int* y_position_pointer, char command) {
  switch (command) { // we will be learning about the switch statement later (but you can Google it for now)
    case UP_KEY:
      update_y_position(y_position_pointer, -1);
      break;
    case DOWN_KEY:
      update_y_position(y_position_pointer, 1);
      break;
    case LEFT_KEY:
      update_x_position(x_position_pointer, -1);
      break;
    case RIGHT_KEY:
      update_x_position(x_position_pointer, 1);
      break;
  }
}

// This was changed. Now the attacker teleports as well.

void update_y_attacker_position(int* y_attacker_position_pointer, int delta, int y_position) {
	if (*y_attacker_position_pointer > y_position) {
			*y_attacker_position_pointer -= delta;
			if (*y_attacker_position_pointer > SCREEN_HEIGHT - 5 && y_position < 5) {
				*y_attacker_position_pointer += delta*2;
				if (*y_attacker_position_pointer >= SCREEN_HEIGHT) {
					*y_attacker_position_pointer = 2;	
					} 
				}
			} else if (*y_attacker_position_pointer < y_position) {
				*y_attacker_position_pointer  += delta;
				if (*y_attacker_position_pointer < 5 && y_position > SCREEN_HEIGHT - 3) {
						*y_attacker_position_pointer -= delta*2;
						if (*y_attacker_position_pointer == 1) {
						*y_attacker_position_pointer = SCREEN_HEIGHT - 1; 
					}
			 }
		}
	}


void update_x_attacker_position(int* x_attacker_position_pointer, int delta, int x_position) {
	if (*x_attacker_position_pointer > x_position) {
		*x_attacker_position_pointer -= delta;
		if (*x_attacker_position_pointer > SCREEN_WIDTH - 10 && x_position < 10) {
				*x_attacker_position_pointer += delta*2;
				if (*x_attacker_position_pointer == SCREEN_WIDTH - 2) {
					*x_attacker_position_pointer = 0;
				}
			}	
		} else if (*x_attacker_position_pointer < x_position) {
			*x_attacker_position_pointer  += delta;
			if (*x_attacker_position_pointer < 10 && x_position > SCREEN_WIDTH - 10) {
						*x_attacker_position_pointer -= delta*2;
						if (*x_attacker_position_pointer == -1) {
						*x_attacker_position_pointer = SCREEN_WIDTH - 3; 
				}
			}
		}
  }

	
void update_attacker_position(int* x_attacker_position_pointer, int* y_attacker_position_pointer, int x_position, int y_position) {
			update_x_attacker_position(x_attacker_position_pointer, 1, x_position); 
			update_y_attacker_position(y_attacker_position_pointer, 1, y_position);
}



void update_y_position(int* y_position_pointer, int delta) {
        *y_position_pointer += delta;
    if (*y_position_pointer == 1) {
        *y_position_pointer = SCREEN_HEIGHT - 1;
    } else if (*y_position_pointer >= SCREEN_HEIGHT) {
    		*y_position_pointer = 2;
    }
}


void update_x_position(int* x_position_pointer, int delta) {
        *x_position_pointer += delta;
    if (*x_position_pointer == -1) {
        *x_position_pointer = SCREEN_WIDTH - 3;
    } else if (*x_position_pointer == SCREEN_WIDTH - 2) {
    		*x_position_pointer = 0;
    }
}

void redraw_screen(int x_position, int y_position, int x_item_position, int y_item_position, int x_attacker_position, int y_attacker_position) {
	int current_screen_row = 1;
	int current_screen_column = 1;
	while (current_screen_row <= SCREEN_HEIGHT) {
		draw_horizontal_borders(current_screen_row);

		if (not_top_or_bottom_row(current_screen_row)) {
			if (current_screen_row == y_position && current_screen_row == y_item_position && current_screen_row == y_attacker_position) {
			draw_with_all_tokens(x_position, x_item_position, x_attacker_position);
			}	else if (current_screen_row == y_position && current_screen_row == y_attacker_position) {
			draw_with_moving_attacker(x_position, x_attacker_position); 
			} else if (current_screen_row == y_position && current_screen_row == y_item_position) {
				draw_with_both_tokens(x_position, x_item_position); 
			} else if (current_screen_row == y_item_position && current_screen_row == y_attacker_position) {
				draw_with_attaker_and_item(x_attacker_position, x_item_position); 
			
			} else {

				if (current_screen_row == y_position) {
					draw_row_with_token(x_position);
				}
				else if (current_screen_row == y_item_position) {
					draw_row_with_item(x_item_position);
				}
				else if (current_screen_row == y_attacker_position) {
				   draw_row_with_attacker(x_attacker_position);
				} else {
					draw_empty_row();
				}
			}
		}
		current_screen_row++;  
	}
}

void draw_with_both_tokens(int x_position, int x_item_position) {
	int remaining_line_width = SCREEN_WIDTH;
	
    if (x_item_position < x_position) {
		remaining_line_width -= draw_left_border();
		remaining_line_width -= draw_empty_spaces(x_item_position);
		remaining_line_width -= print_item();
		remaining_line_width -= draw_empty_spaces(x_position - x_item_position - 1);
		remaining_line_width -= print_token();
		draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
		draw_right_border(); 
      	} else if (x_item_position > x_position) {
		remaining_line_width -= draw_left_border();
		remaining_line_width -= draw_empty_spaces(x_position);
		remaining_line_width -= print_token();
		remaining_line_width -= draw_empty_spaces(x_item_position - x_position - 1);
		remaining_line_width -= print_item();
		draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
		draw_right_border(); 
      	} else if (x_item_position == x_position) {
		remaining_line_width -= draw_left_border();
		remaining_line_width -= draw_empty_spaces(x_position);
		remaining_line_width -= print_token();
		draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
		draw_right_border();
		}
}


void draw_with_moving_attacker(int x_position, int x_attacker_position) {
	int remaining_line_width = SCREEN_WIDTH;
	  if (x_attacker_position < x_position) {
		remaining_line_width -= draw_left_border();
		remaining_line_width -= draw_empty_spaces(x_attacker_position);
		remaining_line_width -= print_attacker();
		remaining_line_width -= draw_empty_spaces(x_position - x_attacker_position - 1);
		remaining_line_width -= print_token();
		draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
		draw_right_border(); 
      	} else if (x_attacker_position > x_position) {
		remaining_line_width -= draw_left_border();
		remaining_line_width -= draw_empty_spaces(x_position);
		remaining_line_width -= print_token();
		remaining_line_width -= draw_empty_spaces(x_attacker_position - x_position - 1);
		remaining_line_width -= print_attacker();
		draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
		draw_right_border(); 
	}
}

void draw_with_attaker_and_item (int x_attacker_position, int x_item_position) {
	int remaining_line_width = SCREEN_WIDTH;
	
    if (x_attacker_position < x_item_position) {
		remaining_line_width -= draw_left_border();
		remaining_line_width -= draw_empty_spaces(x_attacker_position);
		remaining_line_width -= print_attacker();
		remaining_line_width -= draw_empty_spaces(x_item_position - x_attacker_position - 1);
		remaining_line_width -= print_item();
		draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
		draw_right_border(); 
      	} else if (x_attacker_position > x_item_position) {
		remaining_line_width -= draw_left_border();
		remaining_line_width -= draw_empty_spaces(x_item_position);
		remaining_line_width -= print_item();
		remaining_line_width -= draw_empty_spaces(x_attacker_position - x_item_position - 1);
		remaining_line_width -= print_attacker();
		draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
		draw_right_border(); 
      	} else if (x_attacker_position == x_item_position) {
		remaining_line_width -= draw_left_border();
		remaining_line_width -= draw_empty_spaces(x_item_position);
		remaining_line_width -= print_item();
		draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
		draw_right_border();
		}
}

void draw_with_all_tokens(int x_position, int x_item_position, int x_attacker_position) {
		int remaining_line_width = SCREEN_WIDTH;
			
		if (x_item_position > x_position && x_item_position > x_attacker_position && x_position > x_attacker_position) {
    remaining_line_width -= draw_left_border();
		remaining_line_width -= draw_empty_spaces(x_attacker_position);
		remaining_line_width -= print_attacker();
		remaining_line_width -= draw_empty_spaces(x_position - x_attacker_position);
		remaining_line_width -= print_token();
		remaining_line_width -= draw_empty_spaces(x_item_position - x_position - x_attacker_position);
		remaining_line_width -= print_item();
		draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
		draw_right_border(); 
    	} else if (x_item_position > x_position && x_item_position > x_attacker_position && x_attacker_position > x_position) {
     			remaining_line_width -= draw_left_border();
     			remaining_line_width -= draw_empty_spaces(x_position);
					remaining_line_width -= print_token();
					remaining_line_width -= draw_empty_spaces(x_attacker_position - x_position);
					remaining_line_width -= print_attacker();
      		remaining_line_width -= draw_empty_spaces(x_item_position - x_attacker_position - x_position);
      		remaining_line_width -= print_item();
					draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
					draw_right_border(); 
      			} 
	  //if (x_position > x_item_position && x_position > x_attacker_position && x_attacker_position > x_item_position) { // alan: might be easier to read if rewritten like below:
	  if (x_item_position < x_attacker_position && x_attacker_position < x_position) {
		remaining_line_width -= draw_left_border();
		remaining_line_width -= draw_empty_spaces(x_item_position);
		remaining_line_width -= print_item();	
		remaining_line_width -= draw_empty_spaces(x_attacker_position - x_item_position);
		remaining_line_width -= print_attacker();
		remaining_line_width -= draw_empty_spaces(x_position - x_attacker_position - x_item_position); // alan: the input to this equation should be revisited
		remaining_line_width -= print_token();
		draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
		draw_right_border(); 
			} else if (x_position > x_item_position && x_position > x_attacker_position && x_item_position > x_attacker_position) {
					remaining_line_width -= draw_left_border();
					remaining_line_width -= draw_empty_spaces(x_attacker_position);
					remaining_line_width -= print_attacker();	
					remaining_line_width -= draw_empty_spaces(x_item_position - x_attacker_position);
					remaining_line_width -= print_item();
					remaining_line_width -= draw_empty_spaces(x_position - x_item_position - x_attacker_position);
					remaining_line_width -= print_token();
					draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
					draw_right_border(); 
					}
    if (x_attacker_position > x_position && x_attacker_position > x_item_position && x_item_position > x_position) {
    remaining_line_width -= draw_left_border();
    remaining_line_width -= draw_empty_spaces(x_position);
		remaining_line_width -= print_token();
		remaining_line_width -= draw_empty_spaces(x_item_position - x_position);
		remaining_line_width -= print_item();
		remaining_line_width -= draw_empty_spaces(x_attacker_position - x_item_position - x_position);
		remaining_line_width -= print_attacker();
		draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
		draw_right_border(); 
      } else if (x_attacker_position > x_position && x_attacker_position > x_item_position && x_position > x_item_position) {
      		remaining_line_width -= draw_left_border();
					remaining_line_width -= draw_empty_spaces(x_item_position);
					remaining_line_width -= print_item();
					remaining_line_width -= draw_empty_spaces(x_position - x_item_position);
					remaining_line_width -= print_token();
      		remaining_line_width -= draw_empty_spaces(x_attacker_position - x_position - x_item_position);
      		remaining_line_width -= print_attacker();
					draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
					draw_right_border();
      		}
      	
} 




void draw_row_with_token(int x_position) {
	int remaining_line_width = SCREEN_WIDTH;
	remaining_line_width -= draw_left_border();
	remaining_line_width -= draw_empty_spaces(x_position);
	remaining_line_width -= print_token();
	draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
	draw_right_border();
}

int print_token() {
	printf ("%c", TOKEN);
	return 1;
}

void draw_row_with_item(int x_item_position) {
	int remaining_line_width = SCREEN_WIDTH;
	remaining_line_width -= draw_left_border();
	remaining_line_width -= draw_empty_spaces(x_item_position);
	remaining_line_width -= print_item();
	draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
	draw_right_border();
}

int print_item() {
	printf ("%c", ITEM);
	return 1;
}


void draw_row_with_attacker(int x_attacker_position) {
  int remaining_line_width = SCREEN_WIDTH;
	remaining_line_width -= draw_left_border();
	remaining_line_width -= draw_empty_spaces(x_attacker_position);
	remaining_line_width -= print_attacker();
	draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
	draw_right_border();
}


int print_attacker() {
    printf("%c", ATTACKER);
    return 1;
}

void draw_empty_row() {
	int remaining_line_width = SCREEN_WIDTH;
	remaining_line_width -= draw_left_border();
	draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
	draw_right_border();
}

int draw_empty_spaces(int number_of_empty_spaces) {
	int i;
	for(i=1; i <= number_of_empty_spaces; i++) {
		printf("%c", EMPTY_SPACE);
	}
	return number_of_empty_spaces;
}

void draw_horizontal_borders(int current_screen_row) {
	int i;  
	if ((current_screen_row == 1) || (current_screen_row == SCREEN_HEIGHT)) {
		for (i=1; i <= SCREEN_WIDTH; i++) {
			printf ("%c", HORIZONTAL_BORDER);
		}
		printf ("\n");
	}
}

int not_top_or_bottom_row(int current_screen_row) {
	return ((current_screen_row != 1) && (current_screen_row != SCREEN_HEIGHT));
}

int draw_left_border() {
	printf("%c", VERTICAL_BORDER);  
	return 1;
}

void draw_right_border() {
	printf("%c\n", VERTICAL_BORDER);
}


