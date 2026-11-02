#include <stdio.h>

int main(void) {
    double consumption;
    double total_cost = 0.0;
    double step1 = 0.0, step2 = 0.0, step3 = 0.0;
    int is_valid = 0; // Флаг: 0 - ввод некорректен, 1 - ввод успешен

    while (is_valid == 0) {
        printf("Введите потребленный объем электроэнергии (кВтч): ");
        
        if (scanf("%lf", &consumption) != 1) {
            printf("Ошибка: введен неверный тип данных. Требуется число.\n");
            while (getchar() != '\n'); // Очищаем буфер
        } else if (consumption < 0) {
            printf("Ошибка: объем потребления не может быть отрицательным!\n");
        } else {
            is_valid = 1; // Успех, выходим из цикла
        }
    }

    // Ступенчатый расчет стоимости
    if (consumption <= 200.0) {
        step1 = consumption * 0.05;
        total_cost = step1;
    } else if (consumption <= 500.0) {
        step1 = 200.0 * 0.05;
        step2 = (consumption - 200.0) * 0.10;
        total_cost = step1 + step2;
    } else {
        step1 = 200.0 * 0.05;
        step2 = (500.0 - 200.0) * 0.10;
        step3 = (consumption - 500.0) * 0.15;
        total_cost = step1 + step2 + step3;
    }

    printf("\n--- Разбивка по тарифным ступеням ---\n");
    printf("Общее потребление: %.2f кВтч\n", consumption);
    printf("1-я ступень (до 200 кВтч по 0.05): %.2f\n", step1);
    printf("2-я ступень (от 200 до 500 кВтч по 0.10): %.2f\n", step2);
    printf("3-я ступень (свыше 500 кВтч по 0.15): %.2f\n", step3);
    printf("Итоговая стоимость: %.2f\n", total_cost);

    return 0;
}
