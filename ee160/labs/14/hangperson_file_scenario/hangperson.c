#include <stdio.h>
#include "hangperson.h"
main() {

char phrase[MAX_LETTERS];
char guesses[MAX_LETTERS];
char letter;
int amount_of_guesses = 5;
int number_of_letters = 0;
int right_answer_counter = 0;
int duplicate_letters = 0;
int number_of_letters_with_duplicate;
int flag;
int index=0;

display_rules(amount_of_guesses);
get_phrase(phrase);
saving_phrase(phrase);
letter_count(phrase, &number_of_letters);
number_of_letters_with_duplicate = number_of_letters;

printf("Player 2's turn!\n");    

do {
    
printf("You have %d guess(es).\n", amount_of_guesses);
letter = get_guesses();
guesses[index] = letter;

guess_evaluator(phrase, letter, number_of_letters, &flag, &duplicate_letters);
guess_tracker(guesses, number_of_letters_with_duplicate);
amount_of_guesses_tracker(&amount_of_guesses, flag, &right_answer_counter, &index);
display_guesses(guesses);

if(duplicate_letters > 1) { (number_of_letters_with_duplicate)--;}
if(right_answer_counter == number_of_letters 
|| right_answer_counter == number_of_letters_with_duplicate) { 
        printf("You win!\n");
        display_phrase(phrase);
        return; }

} while (amount_of_guesses != 0);

printf("Game Over :(\n");
display_phrase(phrase);

}



