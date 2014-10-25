#include <stdio.h>

//#include "helper_function.h"
//#include "helper_function.c"

#define CONTINUE_PROGRAM 'n'

int ask_to_exit() {
  char exit_program_flag;
  printf ("\n");
  printf ("Are you finished checking all your accounts?:\n");
  printf ("Enter 'n' to check more accounts; Enter any other character to exit\n");
  scanf (" %c", &exit_program_flag);
  return(exit_program_flag);
}

/* ### How is get_name defined? ### */

main(){
  char personal_information;
  char exit_program_flag = CONTINUE_PROGRAM;
  
  while(exit_program_flag == CONTINUE_PROGRAM){
    personal_information = get_name();
    
    if (personal_information == 'c'){
      printf("You have authorization.\n");
    }else if(personal_information != 'c'){ //using an else (instead of else if) is probably sufficient here
      printf("You do not have authorization.\n");
    }
    exit_program_flag = ask_to_exit();
  }
  return 0;
}