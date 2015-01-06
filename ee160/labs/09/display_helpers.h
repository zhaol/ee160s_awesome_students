void clear_screen ();
void seed_random_generator ();
void display_instructions();
void display_position(int x_position, int y_position, int x_item_position, int y_item_position);
void update_position(int* x_position, int* y_position, char command);
void update_y_position(int* y_position_pointer, int delta);
void update_x_position(int* x_position_pointer, int delta);
void redraw_screen(int x_position, int y_position, int x_item_position, int y_item_position);
void draw_with_both_tokens(int x_position, int x_item_position);
void draw_row_with_token(int x_position);
void draw_row_with_eaten_token(int x_item_position);
int print_token();
int print_eaten_token();
void draw_empty_row();
int draw_empty_spaces(int number_of_empty_spaces);
void draw_horizontal_borders(int current_screen_row);
int not_top_or_bottom_row(int current_screen_row);
int draw_left_border();
void draw_right_border();