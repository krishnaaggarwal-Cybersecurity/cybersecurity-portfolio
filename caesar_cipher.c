/*
 * Caesar Cipher - Basic Encryption/Decryption in C
 * Author: Krishna Aggarwal
 * Description: Demonstrates symmetric key encryption concept
 *              Foundation of modern cryptography
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Encrypt a message using Caesar Cipher
void encrypt(char *message, int key) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            message[i] = (char)((ch - base + key) % 26 + base);
        }
    }
}

// Decrypt a message using Caesar Cipher
void decrypt(char *message, int key) {
    encrypt(message, 26 - key);
}

int main() {
    char message[200];
    int key, choice;

    printf("=== Caesar Cipher - Encryption Tool ===\n");
    printf("1. Encrypt\n2. Decrypt\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter key (1-25): ");
    scanf("%d", &key);

    if (choice == 1) {
        encrypt(message, key);
        printf("Encrypted: %s\n", message);
    } else {
        decrypt(message, key);
        printf("Decrypted: %s\n", message);
    }

    return 0;
}
