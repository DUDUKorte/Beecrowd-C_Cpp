#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int strncasecmp(const char *s1, const char *s2, size_t n) {
    while (n-- && *s1 && *s2 && tolower(*s1) == tolower(*s2)) {
        s1++;
        s2++;
    }
    return (n == -1) ? 0 : tolower(*s1) - tolower(*s2);
}

void replaceTag(char *starterChar, char *sourceTag, char *targetTag) {
    char *currentChar = starterChar;
    char result[1024];
    result[0] = '\0';

    int insideTag = 0;

    while (*currentChar) {
        if (*currentChar == '<') {
            insideTag = 1;
            strncat(result, currentChar, 1);
            currentChar++;
            
        } else if (*currentChar == '>') {
            insideTag = 0;
            strncat(result, currentChar, 1);
            currentChar++;
            
        } else if (insideTag) {
            if (strncasecmp(currentChar, sourceTag, strlen(sourceTag)) == 0) {
                strcat(result, targetTag);
                currentChar += strlen(sourceTag);
            } else {
                strncat(result, currentChar, 1);
                currentChar++;
            }
        } else {
            strncat(result, currentChar, 1);
            currentChar++;
        }
    }

    strcpy(starterChar, result);
}

int main() {
    char sourceTag[12];
    char targetTag[1002];
    char line[52];

    while (scanf("%s", sourceTag) != EOF) {
        scanf("%s", targetTag);
        getchar();

        if (fgets(line, sizeof(line), stdin) != NULL) {
            line[strcspn(line, "\n")] = '\0';

            replaceTag(line, sourceTag, targetTag);

            printf("%s\n", line);
        }
    }

    return 0;
}