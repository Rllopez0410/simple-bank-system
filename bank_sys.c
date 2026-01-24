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
