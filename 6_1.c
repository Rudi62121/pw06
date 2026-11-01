#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch;
    int upper_count = 0;
    int lower_count = 0;
    int other_count = 0;

    printf("Введите text (для завершения введите '#'):\n");

    while ((ch = getchar()) != EOF && ch != '#') {
        if (isupper(ch)) {
            upper_count++;
        } else if (islower(ch)) {
            lower_count++;
        } else {
            other_count++;
        }
    }

    printf("\n--- Статистика потока ---\n");
    printf("Символов верхнего регистра: %d\n", upper_count);
    printf("Символов нижнего регистра: %d\n", lower_count);
    printf("Остальных символов: %d\n", other_count);

    return 0;
}