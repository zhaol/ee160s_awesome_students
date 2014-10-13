/*   File:  net_balance_with_account_information_function.c
//   By:    The Awesome Students of EE160
//   Date:	Today :)

modify net_balance.c so the block of code to display account information is performed using a function:

*/

#include <stdio.h>

// This program allows a teller to enter in account details and the program will calculate account information for the teller
float net_balance(float account_balance, float minimum_balance_fee);
int account_summary_info(int minimum_balance_fee_charged_flag);
    int add_one(int total_accounts_with_minimum_balance_fees);
    int add_together(int total_minimum_balance_fees, int minimum_balance_fee);  

  int minimum_balance_fee = 35;
  float account_balance;
  int total_minimum_balance_fees = 0;
  int total_accounts_with_minimum_balance_fees = 0;
    
int main() {
  //float account_balance;
  char account_type;
  char exit_program_flag = 'n';
  int total_number_of_accounts = 0;
  float total_amount_in_accounts = 0;
  //int minimum_balance_fee = 35;
  //int total_minimum_balance_fees = 0;
  //int total_accounts_with_minimum_balance_fees = 0;
  int minimum_balance_fee_charged_flag = 0;
  
  while (exit_program_flag == 'n') {
    printf ("Please enter the account balance: ");
    scanf ("%f", &account_balance);
    printf ("c = checking, s = saving\n");
    printf ("Please enter the account type:\n");
    scanf (" %c", &account_type);
      
    if (account_type == 's') {
      if (account_balance < 1000) {
        minimum_balance_fee_charged_flag = 1;
        printf ("A minimum balance fee needs to be charged to this account.\n");
      } else {
        minimum_balance_fee_charged_flag = 0;
        printf ("A minimum balance fee does not need to be charged to this account.\n");
      }
    } else {
      if (account_balance < 500) {
        minimum_balance_fee_charged_flag = 1;
        printf ("A minimum balance fee needs to be charged to this account.\n");
      } else {
        minimum_balance_fee_charged_flag = 0;
        printf ("A minimum balance fee does not need to be charged to this account.\n");
      }
    }  
    
// function that replaced the code
account_summary_info(minimum_balance_fee_charged_flag);
 

    // Update account summary information
    total_number_of_accounts++;
    total_amount_in_accounts += account_balance;
    
    printf ("\n");
    printf ("Are you finished checking all your accounts?:\n");
    printf ("Enter 'n' to check more accounts; Enter any other character to exit\n");
    scanf (" %c", &exit_program_flag);
  }
  
  // Display accounts summary information
  printf ("==== Accounts Summary ====\n");
  printf ("The total number of accounts: %d\n", total_number_of_accounts);
  printf ("The total amount in all accounts: $%.2f\n", total_amount_in_accounts);
  printf ("The percentage of the total minimum balance fees with respect to the total account balances: %.1f%%\n", total_minimum_balance_fees / total_amount_in_accounts * 100);
  printf ("The percentage of accounts that were charged a minimum balance fee: %.1f%%\n", 100.0 * total_accounts_with_minimum_balance_fees / total_number_of_accounts);
  
  return 0;
}

float net_balance(float account_balance, float minimum_balance_fee) {
  return(account_balance - minimum_balance_fee);
}

int account_summary_info(int minimum_balance_fee_charged_flag) {
      if (minimum_balance_fee_charged_flag) {
          
      total_accounts_with_minimum_balance_fees = add_one(total_accounts_with_minimum_balance_fees);
      total_minimum_balance_fees = add_together(total_minimum_balance_fees, minimum_balance_fee);
      
      printf ("Minimum Balance Fee to Account Balance Percentage: %.1f%%\n", (float) minimum_balance_fee / account_balance * 100);
      printf ("The new account balance is %.2f\n", net_balance(account_balance, minimum_balance_fee));
    } else {
      printf ("Minimum Balance Fee to Account Balance Percentage: %.1f%%\n", (float) 0 / account_balance);
      printf ("The new account balance is $%.2f\n", net_balance(account_balance, 0)); // 0 for no minimum balance fee
      
  }
}           
    // these functions are used for the add_together and add_one definitions
            int add_together(int total_minimum_balance_fees, int minimum_balance_fee) {
            return (total_minimum_balance_fees + minimum_balance_fee);
            }

            int add_one(int total_accounts_with_minimum_balance_fees) {
            return ++total_accounts_with_minimum_balance_fees;
        }