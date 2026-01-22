#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct Deposit {
	int deposit_amount;
};

struct Withdraw {
	int withdraw_amount;
};

struct Account {
	char user_name[30];
	char password[30];
	char first_name[30];
	char last_name[30];
	char email[30];
	int checking;
	int savings;
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

void create_account(struct Account customer[21], int account_count) {
	// create a function that creates a user with all there accont info and add it to the array
	struct Account new_account;
	create_account_username(new_account.user_name, sizeof(new_account.user_name));
	create_account_password(new_account.password, sizeof(new_account.password));
	create_account_fname(new_account.first_name, sizeof(new_account.first_name));
	create_account_lname(new_account.last_name, sizeof(new_account.last_name));
	create_account_email(new_account.email, sizeof(new_account.email));
	new_account.checking = 0;
	new_account.savings = 0;
	customer[account_count] = new_account;
	return;
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
