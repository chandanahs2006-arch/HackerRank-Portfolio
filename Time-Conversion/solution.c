#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

char* timeConversion(char* s) {
    int hour, minute, second;
    char period[3];

    // Parse time and AM/PM
    sscanf(s, "%2d:%2d:%2d%2s", &hour, &minute, &second, period);

    // Convert to 24-hour format
    if (strcmp(period, "AM") == 0) {
        if (hour == 12) {
            hour = 0;
        }
    } else { // PM
        if (hour != 12) {
            hour += 12;
        }
    }

    // Allocate memory for result (HH:MM:SS + '\0')
    char *result = (char *)malloc(9 * sizeof(char));

    sprintf(result, "%02d:%02d:%02d", hour, minute, second);

    return result;
}

int main() {
    char s[11];

    scanf("%10s", s);

    char *result = timeConversion(s);

    printf("%s\n", result);

    free(result);

    return 0;
}
