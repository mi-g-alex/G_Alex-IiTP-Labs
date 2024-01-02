#include <iostream>
#include "solves/forStart.h"

void start1() {
    while (true) {
        long long i = 0;
        char *str = new char[100];
        char d;
        d = ' ';
        while ((d != '\n') && i < 100) {
            d = (char) getchar();
            str[i++] = d;
        }
        if (str[0] != '\n') {
            if (!toDoTask1(str, i)) {
                std::cout << "Error\n";
                delete[] str;
            } else {
                delete[] str;
                break;
            }
        } else {
            //std::cout << "Error\n";
            delete[] str;
        }
    }
}

void start2() {
    while (true) {
        long long i = 0;
        char *str = new char[100]{};
        char d = ' ';
        while ((d != '\n') && i < 100) {
            d = (char) getchar();
            str[i] = d;
            i++;
        }

        if (str[0] != '\n') {
            toDoTask2(str, i);
            delete[] str;
            break;
        } else {
            //std::cout << "Error\n";
            delete[] str;
        }
    }
}

void start3() {
    char **a;
    long long *num;
    num = new long long[80];
    a = new char *[80];
    for (int i = 0; i < 80; ++i) {
        a[i] = new char[80];
    }
    long long line = 0;
    char d = (char) getchar();
    if(d == '\n') d = (char) getchar();
    while (d != '\n' || line == 0) {
        long long j = 0;
        while (d == ' ') d = (char) getchar();
        while (d != ' ' && d != '\n') {
            a[line][j++] = d;
            d = (char)getchar();
        }
        num[line] = j;
        if(j != 0) line++;
    }
    toDoTask3(a, num, line);
}

void start4() {
    std::cout << "Введите 0 чтобы выйти\n";
    std::string input;
    while (getline(std::cin, input)) {
        if (input == "0") break;
        toDoTask4(input);
    }
}

void start5() {
    toDoTask5();
}

void start6() {
    toDoTask6();
}

void start7() {
    toDoTask7();
}

void start8() {
    toDoTask8();
}

int main() {
    std::cout << "Lab: 7\n\n"
                 "Tasks:\n"
                 "1\tДана строка символов, состоящая из цифр, разделенных пробелами.\n\t"
                 "Вывести на экран числа этой строки в порядке возрастания их значений.\n\n"

                 "2\tНайти, каких букв в тексте больше – гласных или согласных\n\n"

                 "3\tВвести массив строк. В функции для каждой строки проверить, является она симметричной или нет.\n"
                 "\t(Симметричной считается строка, которая одинаково читается слева направо и справа налево).\n"
                 "\tВывести на экран саму строку и результат её обработки.\n"
                 "\tСтандартных функций работы со строками не использовать.\n\n"

                 "4\t1 апреля 2023\n\n"

                 "5\tВосстановление строки\n\n"

                 "6\tSOLO\n\n"

                 "7\tМакс подстрока не палиндром\n\n"

                 "8\tФишки со сдвигами\n\n"

                 "Что запускаем?:\n";


    std::string number;
    std::cin >> number;
    while (number.size() != 1 || number[0] > '9' || number[0] < '1') {
        std::cout << "Error\n";
        std::cin >> number;
    }
    char x;
    switch (number[0]) {
        case '1':
            x = (char) getchar();
            std::cout << "Введите элементы\n";
            start1();
            break;
        case '2':
            x = (char) getchar();
            std::cout << "Введите элементы\n";
            start2();
            break;
        case '3':
            x = (char) getchar();
            std::cout << "Введите элементы\n";
            start3();
            break;
        case '4':
            std::cout << "Введите элементы\n";
            start4();
            break;
        case '5':
            std::cout << "Введите элементы (сначала кол-во тестов)\n";
            start5();
            break;
        case '6':
            std::cout << "Введите элементы\n";
            start6();
            break;
        case '7':
            std::cout << "Введите элементы\n";
            start7();
            break;
        case '8':
            std::cout << "Введите элементы (сначала кол-во тестов)\n";
            start8();
            break;
    }


}


