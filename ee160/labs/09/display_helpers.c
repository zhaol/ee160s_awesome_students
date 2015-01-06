void clear_screen () {
	int i;
	for (i=1; i <= SCREEN_HEIGHT; i++) {
		printf ("\n");
	}
}

void seed_random_generator (int *x_position_pointer, int *y_position_pointer) {
	srand(time(NULL)); // This is needed so the random generator function, rand(), generates different random numbers each time the program starts


	*y_position_pointer = rand()%19+2;
	*x_position_pointer = rand()%37;

}

void display_position(int x_position, int y_position, int x_item_position, int y_item_position) {
	printf("Current Position: x: %d, y: %d\n", x_position, y_position);
	printf("Money Position: x: %d, y: %d\n", x_item_position, y_item_position);
}

void display_instructions() {
	printf("Press 'w' to go UP, 's' to go DOWN, 'a' to go LEFT, 'd' to go RIGHT, and 'q' to quit\n");
}

void update_position(int* x_position_pointer, int* y_position_pointer, char command) {

	switch (command) { // we will be learning about the switch statement later (but you can Google it for now)

		case UP_KEY:
			if (*y_position_pointer != 2) {
				update_y_position(y_position_pointer, -1);
			}
			break;
		case DOWN_KEY:
			if (*y_position_pointer != 19) {
				update_y_position(y_position_pointer, 1);
			}
			break;
		case LEFT_KEY:
			if (*x_position_pointer != 0) {
				update_x_position(x_position_pointer, -1);
			}
			break;
		case RIGHT_KEY:
			if (*x_position_pointer != 37) {
				update_x_position(x_position_pointer, 1);
			}
			break;
	}
}

void update_y_position(int* y_position_pointer, int delta) {
	*y_position_pointer += delta;
}

void update_x_position(int* x_position_pointer, int delta) {
	*x_position_pointer += delta;
}

void redraw_screen(int x_position, int y_position, int x_item_position, int y_item_position) {
	int current_screen_row = 1;
	int current_screen_column = 1;
	while (current_screen_row <= SCREEN_HEIGHT) {
		draw_horizontal_borders(current_screen_row);


		if (not_top_or_bottom_row(current_screen_row)) {
			if (current_screen_row == y_position && current_screen_row == y_item_position) {
				draw_with_both_tokens(x_position, x_item_position);
			} else {

				if (current_screen_row == y_position) {
					draw_row_with_token(x_position);
				}
				else if (current_screen_row == y_item_position) {
					draw_row_with_eaten_token(x_item_position);
				} else {
					draw_empty_row();
				}
			}
		}
		if (y_item_position == y_position && x_item_position == x_position) {
				seed_random_generator(&x_item_position, &y_item_position);
				
			}
		current_screen_row++;  
	}
}

void draw_with_both_tokens(int x_position, int x_item_position) {
	int remaining_line_width = SCREEN_WIDTH;
	if (x_item_position > x_position) {
		remaining_line_width -= draw_left_border();
		remaining_line_width -= draw_empty_spaces(x_position);
		remaining_line_width -= print_token();
		remaining_line_width -= draw_empty_spaces(x_item_position - x_position);
		remaining_line_width -= print_eaten_token();
		draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
		draw_right_border();
	} else if (x_item_position < x_position) {
		remaining_line_width -= draw_left_border();
		remaining_line_width -= draw_empty_spaces(x_item_position);
		remaining_line_width -= print_eaten_token();
		remaining_line_width -= draw_empty_spaces(x_position - x_item_position);
		remaining_line_width -= print_token();
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

void draw_row_with_eaten_token(int x_item_position) {
	int remaining_line_width = SCREEN_WIDTH;
	remaining_line_width -= draw_left_border();
	remaining_line_width -= draw_empty_spaces(x_item_position);
	remaining_line_width -= print_eaten_token();
	draw_empty_spaces(REMAINING_LINE_WIDTH_WITHOUT_RIGHT_BORDER);
	draw_right_border();
}

int print_eaten_token() {
	printf ("%c", EATEN_TOKEN);
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