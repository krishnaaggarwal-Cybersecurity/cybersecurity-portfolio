#include <stdio.h>
#include <string.h>

#define MAX_LEN 500

void xorCipher(char *text, char key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] ^= key;
    }
}

int main() {
    char text[MAX_LEN];
    char key;
    char original[MAX_LEN];

    printf("=== XOR Cipher Demo ===\n");
    printf("Enter text: ");

    if (fgets(text, sizeof(text), stdin) == NULL) {
        printf("Error reading text.\n");
        return 1;
    }

    text[strcspn(text, "\n")] = '\0';
    strcpy(original, text);

    printf("Enter a single character key: ");
    scanf("%c", &key);

    xorCipher(text, key);
    printf("Encrypted output: %s\n", text);

    xorCipher(text, key);
    printf("Decrypted output: %s\n", text);

    return 0;
}
