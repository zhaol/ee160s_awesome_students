char get_phrase(char phrase[]) {
    
    printf("Player 1, please enter in a phrase:\n");
    scanf( "%100[^\n]", phrase);       
}


char get_guesses() {
    char letter;
    printf("\nPlayer 2, enter a letter to guess: ");
    scanf(" %c", &letter);
    return(letter);
}


void saving_phrase(char phrase[]) {
    FILE *file_pointer = fopen("phrase.txt", "w");
    if(file_pointer == NULL) {
    printf("File did not open\n"); } else {
    fprintf(file_pointer, "%s", phrase);
    fclose(file_pointer); } 
}

void amount_of_guesses_tracker(int* amount_of_guesses, int flag, int* right_answer_counter, int* index) {
    if (flag) { printf("Correct!\n"); 
        (*right_answer_counter)++;
        (*index)++;
    } else {
        printf("Nope!\n");
        (*amount_of_guesses)--; }
}


void letter_count(char phrase[], int* number_of_letters){
FILE *read_file_pointer = fopen("phrase.txt", "r");
int index = 0;

if(read_file_pointer != NULL) {
    while(fscanf(read_file_pointer, "%c", phrase) != EOF) {            
            if(phrase[index] != ' ') {(*number_of_letters)++;}      
            index++; }
    fclose(read_file_pointer); 
    } else { printf("File did not open\n"); }
}


void guess_evaluator(char phrase[], char letter, int number_of_letters, int* flag, int* duplicate_letters) {
    FILE *read_file_pointer = fopen("phrase.txt", "r");
    int index;
    int check_if_duplicate_letters = 0;
    *flag = INCORRECT;

if (read_file_pointer != NULL) {
    while(fscanf(read_file_pointer, "%s", phrase) != EOF) {
        for (index=0;index<=number_of_letters+ARRAY_OFFSET;index++) {
            if(letter==phrase[index]) {
                check_if_duplicate_letters++;
                *flag = CORRECT; } 
        } } } else {
            printf("File did not open.\n"); }
        
        *duplicate_letters = check_if_duplicate_letters;
}


void guess_tracker(char guesses[], int number_of_letters_with_duplicate){
    int f=0;
    FILE *save_file_pointer = fopen("guesses.txt", "w");
    
    if(save_file_pointer != NULL) {
        for(f = 1; f <= number_of_letters_with_duplicate; f++){
        fprintf(save_file_pointer, "%c", guesses[f+ARRAY_OFFSET]); } 
    } else { printf("File did not open.\n"); }
    fclose(save_file_pointer);    
        
}


void display_guesses(char guesses[]) {
    FILE *save_file_pointer = fopen("guesses.txt", "r");
        
    if(save_file_pointer != NULL) {
        while(fscanf(save_file_pointer, "%s,", guesses) != EOF) {    
        printf("Your guesses so far: %s\n", guesses); } 
    } else { printf("File did not open.\n"); }
    fclose(save_file_pointer);
}


void display_phrase(char phrase[]) {
    FILE *file_pointer = fopen("phrase.txt", "r");
    
    if(file_pointer!= NULL) {
        printf("The phrase or word was: ");
        while(fscanf(file_pointer, "%s", phrase) != EOF){
            printf("%s ", phrase);
        } } else { printf("File did not open.\n"); }
        printf("\n");
        fclose(file_pointer);
}    


int display_rules(int amount_of_guesses) {
    printf("Hello! Before we begin you must read the rules.\n");
    printf("Player 1, you enter a phrase/word.\n"); 
    printf("Player 2, you only have \"%d\" guesses.\n", amount_of_guesses);
    printf("The guesses that you enter will be shown. If they are right, the letter will stay.\n");
    printf("Also, you can't enter the same letter twice!\n");
    printf("Let's start!\n\n");
}