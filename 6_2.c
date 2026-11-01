#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");

    wint_t ch;
    int sequence_count = 0;
    int state = 0; 

    wprintf(L"Введите текст (для завершения введите '#'):\n");

    while ((ch = getwchar()) != WEOF && ch != L'#') {
        if (ch == L'п' || ch == L'П') {
            state = 1;
        } else if (state == 1 && (ch == L'о' || ch == L'О')) {
            state = 2;
        } else if (state == 2 && (ch == L'к' || ch == L'К')) {
            state = 3;
        } else if (state == 3 && (ch == L'а' || ch == L'А')) {
            sequence_count++;
            state = 0; 
        } else {
            state = 0; 
        }
    }

    wprintf(L"\nКоличество вхождений последовательности \"пока\": %d\n", sequence_count);

    return 0;
}
