#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Функция ввода массива с защитой от некорректного ввода
int input_array(const char *name, int **arr, int *size) {
    printf("Введите размер массива %s: ", name);
    if (scanf("%d", size) != 1 || *size <= 0) {
        printf("Ошибка: размер должен быть положительным целым числом.\n");
        return 0;
    }

    *arr = (int*)malloc(*size * sizeof(int));
    if (*arr == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 0;
    }

    printf("Введите %d элементов массива %s:\n", *size, name);
    for (int i = 0; i < *size; i++) {
        if (scanf("%d", &(*arr)[i]) != 1) {
            printf("Ошибка ввода элемента.\n");
            free(*arr);
            return 0;
        }
    }
    return 1;
}

int main() {
    int *K = NULL, *L = NULL;
    int m, n;

    if (!input_array("K", &K, &m)) return 1;
    if (!input_array("L", &L, &n)) {
        free(K);
        return 1;
    }

    // Поиск максимального элемента в K, отсутствующего в L
    int max_val = INT_MIN;
    int found = 0;

    for (int i = 0; i < m; i++) {
        int present_in_L = 0;
        for (int j = 0; j < n; j++) {
            if (K[i] == L[j]) {
                present_in_L = 1;
                break;
            }
        }
        if (!present_in_L && K[i] > max_val) {
            max_val = K[i];
            found = 1;
        }
    }

    if (found) {
        printf("Наибольший элемент в K, отсутствующий в L: %d\n", max_val);
    } else {
        printf("Нет элемента в K, отсутствующего в L.\n");
    }

    free(K);
    free(L);
    return 0;
}
