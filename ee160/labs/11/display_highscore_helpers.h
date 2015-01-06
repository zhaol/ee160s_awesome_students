void clear_screen ();
void seed_random_generator();
void display_position_and_highscore(int x_position, int y_position, int x_item_position, int y_item_position, int x_attacker_position, int y_attacker_position, int high_score);
void update_position(int* x_position, int* y_position, char command);
void update_y_position(int* y_position_pointer, int delta);
void update_x_position(int* x_position_pointer, int delta);
void update_attacker_position(int* x_attacker_position_pointer, int* y_attacker_position_pointer, int x_position, int y_position, int loop);
void draw_with_moving_attacker(int x_position, int x_attacker_position);
void attacker_position (int *y_attacker_position, int *x_attacker_position);
void update_y_attacker_position(int* y_attacker_position_pointer, int delta, int y_position);
void update_x_attacker_position(int* x_attacker_position_pointer, int delta, int x_position);

int draw_empty_spaces(int number_of_empty_spaces);
int not_top_or_bottom_row(int current_screen_row);
int draw_left_border();
void draw_horizontal_borders(int current_screen_row);
void draw_right_border();
void draw_empty_row();
void draw_row_with_token(int x_position);
void draw_row_with_item(int x_item_position);
void draw_row_with_attacker(int x_attacker_position);
int print_token();
int print_item();
int print_attacker();

void redraw_screen(int x_position, int y_position, int x_item_position, int y_item_position, int x_attacker_position, int y_attacker_position);
void draw_with_both_tokens(int x_position, int x_item_position);
void draw_with_attaker_and_item (int x_attacker_position, int x_item_position);
void draw_with_all_tokens(int x_position, int x_item_position, int x_attacker_position);

void high_score_tracker (int* high_score, 
int x_item_position, 
int x_position,
int y_item_position, 
int y_position,
int list_of_high_scores[]);

void high_score_result(char name_of_player[], int list_of_high_scores[], int high_score);
void highest_score_user_input(char name_of_player[]);
void growing_score(int list_of_high_scores[], int high_score);
void new_high_score(int list_of_high_scores[]);