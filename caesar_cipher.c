#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 500

void encrypt(char *message, int key) {
    key = key % 26;

    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (isalpha((unsigned char)ch)) {
            char base = islower((unsigned char)ch) ? 'a' : 'A';
            message[i] = (char)((ch - base + key + 26) % 26 + base);
        }
    }
}

void decrypt(char *message, int key) {
    encrypt(message, 26 - (key % 26));
}

int main() {
    char message[MAX_LEN];
    int choice, key;

    printf("=== Caesar Cipher Tool ===\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice: ");

    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Enter key (1-25): ");
    if (scanf("%d", &key) != 1 || key < 1 || key > 25) {
        printf("Invalid key. Key must be between 1 and 25.\n");
        return 1;
    }

    getchar();

    printf("Enter message: ");
    if (fgets(message, sizeof(message), stdin) == NULL) {
        printf("Error reading message.\n");
        return 1;
    }

    message[strcspn(message, "\n")] = '\0';

    if (choice == 1) {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}
