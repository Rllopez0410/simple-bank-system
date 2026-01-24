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
