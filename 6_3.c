#include <stdio.h>
#include <stdlib.h>

int get_digits_sum(int num) {
    int sum = 0;
    num = abs(num); 
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(void) {
    int number = -1; // Инициализируем любым числом, кроме 0
    int harshad_count = 0, other_count = 0;
    long long harshad_sum = 0, other_sum = 0;
    int scan_status;

    printf("Вводите целые числа (0 для окончания ввода):\n");

    printf("-> ");
    // Цикл выполняется, пока ввод успешен И введенное число не равно 0
    while ((scan_status = scanf("%d", &number)) != EOF && (scan_status == 0 || number != 0)) {
        if (scan_status == 0) {
            printf("Ошибка: введен неверный тип данных. Пожалуйста, введите целое число.\n");
            while (getchar() != '\n'); // Очистка буфера от некорректных символов
            printf("-> ");
            continue;
        }

        int digits_sum = get_digits_sum(number);

        if (digits_sum != 0 && number % digits_sum == 0) {
            harshad_count++;
            harshad_sum += number;
        } else {
            other_count++;
            other_sum += number;
        }
        
        printf("-> ");
    }

    printf("\n--- Результаты классификации ---\n");
    if (harshad_count > 0) {
        printf("Числа Харшад: количество = %d, среднее = %.2f\n", 
               harshad_count, (double)harshad_sum / harshad_count);
    } else {
        printf("Числа Харшад не вводились.\n");
    }

    if (other_count > 0) {
        printf("Остальные числа: количество = %d, среднее = %.2f\n", 
               other_count, (double)other_sum / other_count);
    } else {
        printf("Остальные числа не вводились.\n");
    }

    return 0;
}
