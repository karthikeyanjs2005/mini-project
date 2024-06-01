#include <stdio.h>
#include <string.h>

// Function to remove common characters
int removeCommonCharacters(char *str1, char *str2) {
    int count = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Array to keep track of removed characters
    int removed[256] = {0};

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j] && !removed[(unsigned char)str1[i]]) {
                str1[i] = str2[j] = '0';
                count++;
                removed[(unsigned char)str1[i]] = 1;
                break;
            }
        }
    }

    return (len1 + len2 - 2 * count);
}

// Function to get the result from the FLAMES calculation
char getFlamesResult(int count) {
    char flames[] = "FLAMES";
    int index = 0;

    for (int i = 6; i > 1; i--) {
        index = (index + count - 1) % i;
        for (int j = index; j < i - 1; j++) {
            flames[j] = flames[j + 1];
        }
        flames[i - 1] = '\0';
    }

    return flames[0];
}

int main() {
    char name1[100], name2[100];

    // Get the names from the user
    printf("Enter the first name: ");
    scanf("%s", name1);
    printf("Enter the second name: ");
    scanf("%s", name2);

    // Remove common characters and calculate remaining characters
    int remaining_count = removeCommonCharacters(name1, name2);

    // Get the FLAMES result
    char result = getFlamesResult(remaining_count);

    // Print the result
    switch (result) {
        case 'F': printf("The relationship is: Friends\n"); break;
        case 'L': printf("The relationship is: Lovers\n"); break;
        case 'A': printf("The relationship is: Affection\n"); break;
        case 'M': printf("The relationship is: Marriage\n"); break;
        case 'E': printf("The relationship is: Enemies\n"); break;
        case 'S': printf("The relationship is: Siblings\n"); break;
        default: printf("Error calculating FLAMES.\n"); break;
    }

    return 0;
}
