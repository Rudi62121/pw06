#include <stdio.h>

int main(void) {
    int choice = 0; // Инициализируем значением, отличным от 5
    double amount, percent, result;
    int input_ok; // Флаг для контроля ввода вещественных чисел

    while (choice != 5) {
        printf("\n======= ФИНАНСОВЫЙ КАЛЬКУЛЯТОР =======\n");
        printf("1. Рассчитать процент от суммы\n");
        printf("2. Начислить НДС 20%% (Сумма + НДС)\n");
        printf("3. Выделить НДС 20%% (Сумма без НДС)\n");
        printf("4. Рассчитать чаевые 10%%\n");
        printf("5. Выход\n");
        printf("Выберите пункт меню (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка: введите корректный номер пункта меню!\n");
            while (getchar() != '\n'); 
            choice = 0; // Сбрасываем, чтобы цикл не завершился из-за мусора в переменной
            continue;
        }

        switch (choice) {
            case 1:
                input_ok = 0;
                while (input_ok == 0) {
                    printf("Введите сумму: ");
                    if (scanf("%lf", &amount) == 1) input_ok = 1;
                    else { printf("Неверный ввод числа! "); while (getchar() != '\n'); }
                }
                
                input_ok = 0;
                while (input_ok == 0) {
                    printf("Введите процент: ");
                    if (scanf("%lf", &percent) == 1) input_ok = 1;
                    else { printf("Неверный ввод числа! "); while (getchar() != '\n'); }
                }
                
                result = amount * (percent / 100.0);
                printf("%.2f%% от суммы %.2f составляет: %.2f\n", percent, amount, result);
                break;

            case 2:
                input_ok = 0;
                while (input_ok == 0) {
                    printf("Введите сумму: ");
                    if (scanf("%lf", &amount) == 1) input_ok = 1;
                    else { printf("Неверный ввод числа! "); while (getchar() != '\n'); }
                }
                result = amount * 1.20;
                printf("Сумма %.2f с начисленным НДС 20%%: %.2f (НДС = %.2f)\n", 
                       amount, result, result - amount);
                break;

            case 3:
                input_ok = 0;
                while (input_ok == 0) {
                    printf("Введите сумму: ");
                    if (scanf("%lf", &amount) == 1) input_ok = 1;
                    else { printf("Неверный ввод числа! "); while (getchar() != '\n'); }
                }
                result = amount / 1.20;
                printf("Сумма без НДС 20%% от исходной %.2f: %.2f (НДС = %.2f)\n", 
                       amount, result, amount - result);
                break;

            case 4:
                input_ok = 0;
                while (input_ok == 0) {
                    printf("Введите сумму счета: ");
                    if (scanf("%lf", &amount) == 1) input_ok = 1;
                    else { printf("Неверный ввод числа! "); while (getchar() != '\n'); }
                }
                result = amount * 0.10;
                printf("Чаевые 10%% от %.2f составят: %.2f (Итого к оплате: %.2f)\n", 
                       amount, result, amount + result);
                break;

            case 5:
                printf("Выход из программы. До свидания!\n");
                break;

            default:
                printf("Неверный пункт меню! Пожалуйста, повторите выбор.\n");
                break;
        }
    }

    return 0;
}
