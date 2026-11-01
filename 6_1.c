#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch;
    int spaces_count = 0;
    int newline_count = 0;
    int other_count = 0;

    printf("Введите текст (для завершения введите '#'):\n");

    while ((ch = getchar()) != EOF && ch != '#') {
        if (ch == ' ') {
            spaces_count++;
        } else if (ch == '\n') {
            newline_count++;
        } else {
            other_count++;
        }
    }

    printf("\n--- Статистика потока ---\n");
    printf("Количество пробелов: %d\n", spaces_count);
    printf("Количество символов новой строки: %d\n", newline_count);
    printf("Количество остальных символов: %d\n", other_count);

    return 0;
}
