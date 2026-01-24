#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct Deposit {
	float deposit_amount;
};

struct Withdraw {
	float withdraw_amount;
};

typedef enum {
	access_granted,
	access_denied
} ACCT_VARIFY;

struct Account {
	char user_name[30];
	char user_password[30];
	char first_name[30];
	char last_name[30];
	char email[30];
	float checking;
	float savings;
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
	printf("Checking: %.2f\n", customer[index].checking);
	// Create logic that'll tranfer money from checking to savings
	return;
}

void get_savings_account(struct Account customer[21], int index) {
	printf("Savings: %.2f\n", customer[index].savings);
	// Create logic that'll tranfer money from savings to checking
	return;
}

void get_deposit_info(struct Account customer[21], int index) {
	float depositing_amount;
	printf("Enter the amount you'll like to deposit...\n");
	scanf("%f", &depositing_amount);
	customer[index].checking += depositing_amount;
	printf("A deposit ammount of %.2f has been added to your checking account...\n", depositing_amount);
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
	customer[account_count] = new_account;
	printf("welcome %s... Your account has been created...\n", new_account.first_name);
	return;
}

void log_in_menu(struct Account customer[21], int index) {
	bool logged_in = true;
	char customer_options[5][15] = {"View Checking", "View Savings", "Deposit Funds", "Withdraw Funds", "Logout"};

	while (logged_in) {
		for (int i = 0; i < 5; i++) {
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
				break;
			case 4:
				printf("Withdrawing funds...\n");
				break;
			case 5:
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
	int account_count;
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
