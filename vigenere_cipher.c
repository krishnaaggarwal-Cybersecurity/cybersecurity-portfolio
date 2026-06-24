#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 500
#define MAX_KEY 100

void vigenereEncrypt(char *text, const char *key) {
    int keyLen = strlen(key);
    int j = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            char base = islower((unsigned char)text[i]) ? 'a' : 'A';
            char keyChar = tolower((unsigned char)key[j % keyLen]) - 'a';
            text[i] = (char)((text[i] - base + keyChar) % 26 + base);
            j++;
        }
    }
}

void vigenereDecrypt(char *text, const char *key) {
    int keyLen = strlen(key);
    int j = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            char base = islower((unsigned char)text[i]) ? 'a' : 'A';
            char keyChar = tolower((unsigned char)key[j % keyLen]) - 'a';
            text[i] = (char)((text[i] - base - keyChar + 26) % 26 + base);
            j++;
        }
    }
}

int main() {
    char text[MAX_TEXT];
    char key[MAX_KEY];
    int choice;

    printf("=== Vigenere Cipher Tool ===\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice: ");

    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice.\n");
        return 1;
    }

    getchar();

    printf("Enter text: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        printf("Error reading text.\n");
        return 1;
    }
    text[strcspn(text, "\n")] = '\0';

    printf("Enter alphabetic key: ");
    if (fgets(key, sizeof(key), stdin) == NULL) {
        printf("Error reading key.\n");
        return 1;
    }
    key[strcspn(key, "\n")] = '\0';

    for (int i = 0; key[i] != '\0'; i++) {
        if (!isalpha((unsigned char)key[i])) {
            printf("Invalid key. Use alphabetic characters only.\n");
            return 1;
        }
    }

    if (choice == 1) {
        vigenereEncrypt(text, key);
        printf("Encrypted text: %s\n", text);
    } else {
        vigenereDecrypt(text, key);
        printf("Decrypted text: %s\n", text);
    }

    return 0;
}
