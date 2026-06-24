#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 200

int main() {
    char password[MAX_LEN];
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int score = 0;

    printf("=== Password Strength Checker ===\n");
    printf("Enter password: ");

    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("Error reading password.\n");
        return 1;
    }

    password[strcspn(password, "\n")] = '\0';
    int len = strlen(password);

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper((unsigned char)password[i])) hasUpper = 1;
        else if (islower((unsigned char)password[i])) hasLower = 1;
        else if (isdigit((unsigned char)password[i])) hasDigit = 1;
        else hasSpecial = 1;
    }

    if (len >= 8) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    printf("\nAnalysis:\n");
    printf("- Length: %d\n", len);
    printf("- Uppercase: %s\n", hasUpper ? "Yes" : "No");
    printf("- Lowercase: %s\n", hasLower ? "Yes" : "No");
    printf("- Digit: %s\n", hasDigit ? "Yes" : "No");
    printf("- Special Character: %s\n", hasSpecial ? "Yes" : "No");

    printf("\nStrength: ");
    if (score <= 2) printf("Weak\n");
    else if (score == 3 || score == 4) printf("Moderate\n");
    else printf("Strong\n");

    return 0;
}
