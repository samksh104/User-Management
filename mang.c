#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

typedef struct {
    char username[30];
    char password[30];
} User;

User users[MAX_USERS];
int user_count = 0;

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", users[user_count].username);

    printf("Enter password: ");
    scanf("%s", users[user_count].password);

    printf("User registered successfully!\n");
    user_count++;
}

void login_user() {
    char uname[30], pass[30];
    printf("Enter username: ");
    scanf("%s", uname);

    printf("Enter password: ");
    scanf("%s", pass);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, uname) == 0 &&
            strcmp(users[i].password, pass) == 0) {
            printf("Login successful. Welcome, %s!\n", uname);
            return;
        }
    }
    printf("Invalid username or password.\n");
}

int main() {
    int option;

    while (1) {
        printf("\n=== User Management System ===\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                register_user();
                break;
            case 2:
                login_user();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}
