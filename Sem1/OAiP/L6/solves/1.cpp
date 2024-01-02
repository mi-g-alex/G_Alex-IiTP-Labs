//V9
#include <iostream>

bool isNumber(char x) {
    return (x >= '0' && x <= '9');
}

bool toDoTask1(char *start, long long s) {
    char *str = new char[100];
    str[0] = ' ';
    int i = 0, j = 0;
    char d = ' ';
    while (j < s) {
        d = start[j++];
        int len = 0;
        if (d != ' ') {
            if (!isNumber(d)) {
                while (d != ' ' && d != '\n') d = start[j++];
                j--;
            }
            else {
                while (d != ' ' && d != '\n' && isNumber(d)) {
                    str[i] = d;
                    d = start[j++];
                    len++;
                }
                if (len == 1) i++;
            }
        }
    }
    std::sort(str, str + i);
    if (i == 0) {
        delete[] str;
        return false;
    }
    for (j = 0; j < i; j++)
        std::cout << str[j] << " ";
    std::cout << "\n";
    delete[] str;
    return true;
}


