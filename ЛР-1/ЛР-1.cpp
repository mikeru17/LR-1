#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Макрос. При нахождении в коде _SCORE_ вместо него будет подставляться значение 3.
#ifndef _SCORE_
#define _SCORE_ 3
#endif // !_SCORE_

const string TASK1_DESCRIPT = "Задача 1.\nНаписать программу, которая заменяет все четные числа в целочисленном статическом массиве на 0 (массив из 10 элементов).\n\n";
const string TASK2_DESCRIPT = "Задача 2.\nВвод символа с клавиатуры (с проверкой что это именно символ), ввод строки с клавиатуры (с проверкой что это именно строка). Вывод в консоль номера, который символ занимает в строке, если он там есть. Если нет — вывод сообщения об отсутствии символа.\n\n";
const string TASK3_DESCRIPT = "Задача 3.\nРасчет определителя матрицы, матрица размером 3 на 3. Ввод чисел построчно. Числа только целые.\n\n";
const int COUNT = 10;

// Задача 1.
void RunTask1() {
    int arr[COUNT];
    cout << "Ввод массива (10 элементов)...\n";
    for (int i = 0; i < COUNT; i++)
    {
        cout << "Введите " << i << "-й элемент: ";
        cin >> arr[i];
    }

    // setw - форматированный вывод.
    cout << setw(19) << "\nИзначальный массив:";
    for (int i = 0; i < COUNT; i++)
    {
        cout << setw(10) << arr[i];
    }

    cout << setw(19) << "\nИзмененный массив: ";
    for (int i = 0; i < COUNT; i++)
    {
        // Проверка четности элемента и замена на 0.
        if (arr[i] % 2 == 0)
        {
            arr[i] = 0;
        }
        cout << setw(10) << arr[i];
    }
}

// Задача 2.
void RunTask2() {
    char letter;
    string str;

    cout << "Введите буквенный символ: ";
    do
    {
        cin >> letter;
        // Проверка, что введена буква.
        if (!isalpha(letter))
        {
            cout << "Ошибка. Пожалуйста, введите буквенный символ: ";
        }
    } while (!isalpha(letter));

    cout << "Введите вашу строку (не менее 2-х символов): ";
    do
    {
        cin >> str;
        // Проверка, что введено не менее 2-х символов (т.е. это строка).
        if (str.length() <= 1)
        {
            cout << "Ошибка. Пожалуйста, введите строку (не менее 2-х символов): ";
        }
    } while (str.length() <= 1);

    // Проверка, имеется ли введенный символ в строке. Если да, вывод его позиции.
    if (str.find(letter) != -1)
    {
        cout << "\nПервое вхождение введенного символа наблюдается в " << str.find(letter) << "-й позиции строки";
    }
    else
    {
        cout << "\nВведенного символа нет в строке";
    }
}

// Задача 3.
void RunTask3() {
    int matrix[_SCORE_][_SCORE_];
    cout << "Ввод матрицы " << _SCORE_ << " x " << _SCORE_ << "\n";
    // Цикл для строк.
    for (int i = 0; i < _SCORE_; i++)
    {
        cout << "Ввод " << i + 1 << "-й строки:\n";
        // Цикл для столбцов.
        for (int j = 0; j < _SCORE_; j++)
        {
            cout << "Введите " << j + 1 << "-й элемент: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nВаша матрица " << _SCORE_ << " x " << _SCORE_ << ":\n\n";
    for (int i = 0; i < _SCORE_; i++)
    {
        for (int j = 0; j < _SCORE_; j++)
        {
            cout << setw(10) << matrix[i][j];
        }
        cout << "\n\n";
    }

    // Расчет определителя матрицы по формуле.
    int determ = (matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) + (matrix[0][2] * matrix[1][0] * matrix[2][1]) - (matrix[0][2] * matrix[1][1] * matrix[2][0]) - (matrix[0][0] * matrix[1][2] * matrix[2][1]) - (matrix[0][1] * matrix[1][0] * matrix[2][2]);
    cout << "\nОпределитель вашей матрицы равен " << determ;
}

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "----- ЛР-1 начала выполнение! -----\n\n";
    int userChoice;
    // Главное меню для перехода между задачами.
    do
    {
        cout << "----- Главное меню -----\n";
        cout << "Что вы хотите сделать?\nНа выбор есть 4 варианта:\n";
        cout << "1 - Задача 1\n2 - Задача 2\n3 - Задача 3\n0 - Выход\n\nВведите номер вашего выбора: ";
        cin >> userChoice;
        cout << "\n";

        switch (userChoice)
        {
        case 1:
            cout << TASK1_DESCRIPT;
            RunTask1();
            break;
        case 2:
            cout << TASK2_DESCRIPT;
            RunTask2();
            break;
        case 3:
            cout << TASK3_DESCRIPT;
            RunTask3();
            break;
        case 0:
            cout << "Выбран вариант выхода из программы. Программа завершается...\n\n";
            break;
        default:
            cout << "Введен некорректный номер. Пожалуйста, повторите попытку";
            break;
        }

        if (userChoice != 0)
        {
            cout << "\n\n----------------------------------------------------------------------------------------------------\n\n";
        }
    } while (userChoice != 0);

    system("pause");
    return 0;
}
