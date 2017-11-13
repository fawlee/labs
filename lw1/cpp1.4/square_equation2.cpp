#include <cstdio>
#include <stdio.h>
#include <math.h>

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;
    float d = 0;  // Это наш дискриминант
    float x1 = 0; // Это первый корень уравнения
    float x2 = 0; // Это второй корень уравнения
    //Показать пользователю куда он попал и что нужно сделать
    std::puts("This program calculates x from formula ax^2+bx+c=0\nPlease, write a:");
    std::scanf("%f", &a); // "сканируем"  а/ считываем a

    std::puts("Please, write b:");
    std::scanf("%f", &b); // "сканируем"  b/ считываем b

    std::puts("Please, write c:");
    std::scanf("%f", &c); // "сканируем"  c/ считываем c

    /*
    Выше описанный код по выводу сообщений и сканированию
    чисел в переменные, можно так же описать вот так:

    std::puts("This program calculates x from formula ax^2+bx+c=0\nPlease, write a, b and c:");
    std::scanf("%f %f %f", &a, &b, &c);

    Выводим пользователю что нужно ввести a, b и с и второй строчкой считываем их
    */

    d = (b * b) - (4 * a * c); // Расчитываем дискриминант

    if (abs(d) == d) // Если дискриминант <= 0, то находим корни уравнения
    {

        x1 = ((-b) + sqrt(d)) / (2 * a); // Расчитываем первый корень
        x2 = ((-b) - sqrt(d)) / (2 * a); // Расчитываем второй корень

        std::printf("Solution:\nx1 = %f\nx2 = %f", x1, x2); // Выводим корни \n перевод на новую строчку
    }
    else // Если дискриминант отрицательный то нет корней
    {
        std::puts("No roots, negative discriminant");
    }
}