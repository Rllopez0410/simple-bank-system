#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef enum {
	access_granted,
	access_denied
} ACCT_VARIFY;

struct Deposit {
	float deposit_amount;
	char deposit_time[30];
};

struct Withdraw {
	float withdraw_amount;
	char withdraw_time[30];
};

struct Account {
	char user_name[30];
	char user_password[30];
	char first_name[30];
	char last_name[30];
	char email[30];
	float checking;
	float savings;
	int deposit_count;
	int withdraw_count;
	struct Deposit deposit_history[11];
	struct Withdraw withdraw_history[11];
};

void create_account_username(char *username, size_t size) {
	printf("Create a username...\n");
	scanf("%29s", username);
}

void create_account_password(char *password, size_t size) {
	printf("Create a password...\n");
	scanf("%29s", password);
}

void create_account_fname(char *fname, size_t size) {
	printf("Type your first name...\n");
	scanf("%29s", fname);
}

void create_account_lname(char *lname, size_t size) {
	printf("Type your last name...\n");
	scanf("%29s", lname);
}

void create_account_email(char *email, size_t size) {
	printf("Type your email...\n");
	scanf("%29s", email);
}

void get_checking_account(struct Account customer[21], int index) {
	printf("Checking: $%.2f\n", customer[index].checking);
	return;
}

void get_savings_account(struct Account customer[21], int index) {
	printf("Savings: $%.2f\n", customer[index].savings);
	return;
}

void get_deposit_info(struct Account customer[21], int index) {
	struct Deposit new_deposit;
	float funds;
	time_t current_time = time(NULL);
	printf("Enter the amount you'll like to deposit...\n");
	scanf("%f", &funds);
	new_deposit.deposit_amount = funds;
	strcpy(new_deposit.deposit_time, ctime(&current_time));
	customer[index].checking += funds;
	customer[index].deposit_history[customer[index].deposit_count] = new_deposit;
	printf("A deposit ammount of $%.2f...\n", new_deposit.deposit_amount, new_deposit.deposit_time);
	return;
}

void get_withdraw_info(struct Account customer[21], int index) {
	struct Withdraw new_withdraw;
	float funds;
	time_t current_time = time(NULL);
	printf("Enter the amount you'll like to withdraw...\n");
	scanf("%f", &funds);
	new_withdraw.withdraw_amount = funds;
	if (funds > customer[index].checking) {
		printf("Insufficient funds in your checking...\n");
	} else {
		customer[index].checking -= funds;
		customer[index].withdraw_history[customer[index].withdraw_count] = new_withdraw;
		strcpy(new_withdraw.withdraw_time, ctime(&current_time));
		printf("A withdraw ammount of $%.2f has been made to your checking account...\n", new_withdraw.withdraw_amount);
		printf("Your new checking balance is $%.2f...\n", customer[index].checking);
	}
	return;
}

void get_savings_tranfer(struct Account customer[21], int index) {
	float tranfer_amount;
	printf("Enter the amount you'll like to tranfer to your savings...\n");
	scanf("%f", &tranfer_amount);
	if (tranfer_amount > customer[index].checking) {
		printf("Insufficient funds in your checking...\n");
	} else {
		customer[index].checking -= tranfer_amount;
		customer[index].savings += tranfer_amount;
		printf("$%.2f Have been moved into your savings account...\n", tranfer_amount);
	}
	return;
}

void get_checking_tranfer(struct Account customer[21], int index) {
	float tranfer_amount;
	printf("Enter the amount you'll like to tranfer to your checking...\n");
	scanf("%f", &tranfer_amount);
	if (tranfer_amount > customer[index].savings) {
		printf("Insufficient funds in your savings...\n");
	} else {
		customer[index].savings -= tranfer_amount;
		customer[index].checking += tranfer_amount;
		printf("$%.2f Have been moved into your checking account...\n", tranfer_amount);
	}
	return;
}

void get_tranfer_info(struct Account customer[21], int index) {
	int choice;
	printf("Would you like to tranfer from [0] Checking --> Savings or [1] Savings --> Checking...\n");
	scanf("%d", &choice);

	switch (choice) {
		case 0:
			printf("Tranfering funds to savings...\n");
			get_savings_tranfer(customer, index);
			break;
		case 1:
			printf("Tranfering funds to checking...\n");
			get_checking_tranfer(customer, index);
			break;
		default:
			printf("Invalid choice. Please try again...\n");
	}
	return;
}

void create_account(struct Account customer[21], int account_count) {
	struct Account new_account;
	create_account_username(new_account.user_name, sizeof(new_account.user_name));
	create_account_password(new_account.user_password, sizeof(new_account.user_password));
	create_account_fname(new_account.first_name, sizeof(new_account.first_name));
	create_account_lname(new_account.last_name, sizeof(new_account.last_name));
	create_account_email(new_account.email, sizeof(new_account.email));
	new_account.checking = 0.00;
	new_account.savings = 0.00;
	new_account.deposit_count = 0;
	new_account.withdraw_count = 0;
	customer[account_count] = new_account;
	printf("welcome %s... Your account has been created...\n", new_account.first_name);
}

void log_in_menu(struct Account customer[21], int index) {
	bool logged_in = true;
	char customer_options[6][15] = {"View Checking", "View Savings", "Deposit Funds", "Withdraw Funds", "Tranfer Funds", "Logout"};

	while (logged_in) {
		for (int i = 0; i < 6; i++) {
			printf("[%d]==> %s\n", i + 1, customer_options[i]);
		}	
		
		int choice;
		printf("Choose an option with the corresponding number...\n");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Viewing checking account...\n");
				get_checking_account(customer, index);		
				break;
			case 2:
				printf("Viewing Savings account...\n");
				get_savings_account(customer, index);
				break;
			case 3:
				printf("Depositing funds...\n");
				get_deposit_info(customer, index);
				customer.[index].deposit_count++;
				break;
			case 4:
				printf("Withdrawing funds...\n");
				get_withdraw_info(customer, index);
				customer.[index].withdraw_count++;
				break;
			case 5:
				printf("Tranfering funds...\n");
				get_tranfer_info(customer, index);
				break;
			case 6:
				printf("Logging out...\n");
				logged_in = false;
				break;
			default:
				printf("Unknown option. Please try again...\n");
		}
	}
	return;
}

void customer_log_in(struct Account customer[21], int account_count) {

	int index;
	char username_typed[30];
	char password_typed[30];
	bool username_verified = false;
	bool password_verified = false;
	ACCT_VARIFY status;

	printf("Please type in your username...\n");
	scanf("%29s", &username_typed);
	for (int i = 0; i < account_count; i++) {
		if (strcmp(customer[i].user_name, username_typed) == 0) {
			username_verified = true;
			index = i;
			break;
		} else {
			index = -1;
			continue;
		}	
	}

	printf("Please type in your password...\n");
	scanf("%29s", &password_typed);
	for (int i = 0; i < account_count; i++) {
		if (strcmp(customer[i].user_password, password_typed) == 0) {
			password_verified = true;
			index = i;
			break;
		} else {
			index = -1;
			continue;
		}	
	}
	
	if (username_verified && password_verified) {
		status = access_granted;
	} else {
		status = access_denied;
	}
	
	switch (status) {
		case access_granted:
			log_in_menu(customer, index);
			break;
		case access_denied:
			printf("Username or password were incorrect... Please try again...\n");
			break;
		default:
			printf("Unknown Error");
	}
	
}

int main() {
	struct Account customer[21];
	int account_count = 0;
	bool running = true;
	char menu_options[5][15] = {"Create Account", "Log-In", "Admin Log-In", "Exit"};
	
	while (running) {
		printf("========================\n===Welcome To TR Bank===\n========================\n");
		for (int i = 0; i < 4; i++) {
			printf("[%d]==> %s\n", i + 1, menu_options[i]);
		}

		int choice;
		printf("Choose an option with the corresponding number...\n");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Creating an account...\n");
				create_account(customer, account_count);
				account_count++;
				break;
			case 2:
				printf("Logging into your account...\n");
				customer_log_in(customer, account_count);
				break;
			case 3:
				printf("Loggin into adminstrator account...\n");
				break;
			case 4:
				printf("Exiting program...\n");
				running = false;
				break;
			default:
				printf("The given option is not valid...\n");
		}
	}

	return 0;
}
