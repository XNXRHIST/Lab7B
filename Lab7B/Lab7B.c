#include <stdio.h>//Підключаємо необхідні бібліотеки
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

//Ініціалізує масив випадковими числами з діапазону [-100;100]
int initializeArray(int array[], int size);

//Виводить масив на екран, виділяючи червоним кольором від'ємні числа
void printArray(int array[], int size);

//Обчислює добуток від'ємних елементів масиву
int getProductOfNegatives(int array[], int size);

//Обчислює суму елементів після мінімального елемента масиву
int getSumAfterMin(int array[], int size);

//Ініціалізує масив випадковими числами з діапазону [-100;100]
int initializeArray(int array[], int size) {
    srand(time(NULL));  //Ініціалізуємо генератор випадкових чисел залежно від поточного часу

    int i;
    for (i = 0; i < size; i++) {
        array[i] = rand() % 201 - 100;  //Генеруємо випадкові числа з діапазону [-100;100]
    }

    return size;
}

//Виводить масив на екран, виділяючи червоним кольором від'ємні числа
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] < 0) {
            printf("\x1b[31m");  //Встановлюємо червоний колір для від'ємних чисел
        }
        printf("%d ", array[i]);
        printf("\x1b[0m");  //Скидаємо колір після виведення числа
    }
    printf("\n");
}

//Обчислює добуток від'ємних елементів масиву
int getProductOfNegatives(int array[], int size) {
    int добуток = 1;

    int i;
    for (i = 0; i < size; i++) {
        if (array[i] < 0) {
            добуток *= array[i];
        }
    }

    return добуток;
}

//Обчислює суму елементів після мінімального елемента масиву
int getSumAfterMin(int array[], int size) {
    int мінІндекс = 0;

    int i;
    for (i = 1; i < size; i++) {
        if (array[i] < array[мінІндекс]) {
            мінІндекс = i;
        }
    }

    int сума = 0;
    for (i = мінІндекс + 1; i < size; i++) {
        сума += array[i];
    }

    return сума;
}
int main() {
    int array[ARRAY_SIZE];
    int size = initializeArray(array, ARRAY_SIZE);

    printf("Масив: ");
    printArray(array, size);

    int добутокВідємних = getProductOfNegatives(array, size);
    printf("Добуток від'ємних елементів: %d\n", добутокВідємних);//Виводимо інформацію на екран юзера

    int сумаПісляМін = getSumAfterMin(array, size);
    printf("Сума елементів після мінімального: %d\n", сумаПісляМін);

    return 0;//Кінець програми
}
