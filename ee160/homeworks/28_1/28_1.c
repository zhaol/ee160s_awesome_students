/* Refactor do_while_refactor.c and helper_functions.c so that the function output_list_of_account_balances uses a for loop */



/*   File:  do_while_refactor.c
//   By:    The Awesome Students of EE160
//   Date:	Today :)
*/

#include <stdio.h>
#include "28_1_magic_numbers.h"
#include "28_1_helper_functions.h"
#include "28_1_helper_functions.c"

// This program allows a teller to enter in account details and the program will calculate account information for the teller
int main() {
  float account_balance;
  char account_type;
  char exit_program_flag;
  int total_number_of_accounts = 0;
  float total_amount_in_accounts = 0;
  int minimum_balance_fee = 35;
  int total_minimum_balance_fees = 0;
  int total_accounts_with_minimum_balance_fees = 0;
  int minimum_balance_fee_charged_flag = 0;
  float account_balances[MAX_NUMBER_OF_ACCOUNTS];
  int current_account_number = 0;
  char account_holder[MAX_ACCOUNT_HOLDER_SIZE]; 
  char valid_account_type_flag = VALID_ACCOUNT_TYPE;
  
  do  {
    current_account_number++;
    minimum_balance_fee_charged_flag = MINIMUM_BALANCE_FEE_NOT_CHARGED;
    valid_account_type_flag = VALID_ACCOUNT_TYPE;
    get_account_holder(account_holder);
    account_balance = get_account_balance();
    account_type = get_account_type();
    
    if ((account_type == 's') && (account_balance < SAVINGS_ACCOUNT_MINIMUM_BALANCE)) {
      minimum_balance_fee_charged_flag = MINIMUM_BALANCE_FEE_CHARGED;
    } else if ((account_type == 'c') && (account_balance < CHECKING_ACCOUNT_MINIMUM_BALANCE)) {
      minimum_balance_fee_charged_flag = MINIMUM_BALANCE_FEE_CHARGED;
    } else {
      if ((account_type != 's') && (account_type != 'c')) {
        printf ("The account type was invalid\n");
        valid_account_type_flag = INVALID_ACCOUNT_TYPE;
      } else {
        printf ("A minimum balance fee does not need to be charged to this account\n");
      }
    }      
    
    if (valid_account_type_flag == VALID_ACCOUNT_TYPE) {
      // Display account summary information
      printf ("=== Account Information for %s's Account ===\n", account_holder);
      if (minimum_balance_fee_charged_flag) {
        total_accounts_with_minimum_balance_fees++;
        total_minimum_balance_fees += minimum_balance_fee;
        printf ("Minimum Balance Fee to Account Balance Percentage: %.1f%%\n", minimum_balance_fee / account_balance * PERCENT_CONVERSION_FACTOR);
        printf ("The new account balance is %.2f\n", net_balance(account_balance, minimum_balance_fee));
      } else {
        printf ("Minimum Balance Fee to Account Balance Percentage: %.1f%%\n", NO_MINIMUM_BALANCE / account_balance);
        printf ("The new account balance is $%.2f\n", net_balance(account_balance, NO_MINIMUM_BALANCE));
      }
      
      update_account_summary_information(&total_number_of_accounts, &total_amount_in_accounts, account_balance);
      account_balances[current_account_number+ARRAY_OFFSET] = account_balance;
    }
    
    exit_program_flag = ask_to_exit();
  } while (exit_program_flag == CONTINUE_PROGRAM);
  
  output_account_summary_to_file(total_number_of_accounts, total_amount_in_accounts, total_minimum_balance_fees, total_accounts_with_minimum_balance_fees);
  output_list_of_account_balances(account_balances, total_number_of_accounts);
  
  return 0;
}