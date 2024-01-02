#include <iostream>
#include <string>

bool isItNumber(char c) {
    return (c >= '0' && c <= '9');
}

long long checkInput(long long t) {



    std::string s;

    do {

        std::cin >> s;

        bool wasDot = false;
        bool wasE = false;
        bool isNumber = true;

        for (long long i = 0; i < s.length() && isNumber; i++) {
            if ((s[i] != 'e' && s[i] != 'E') && s[i] != '-' && s[i] != '.' && !isItNumber(s[i])) isNumber = false;

            if (s[i] == '-')
                if (i != 0 && (s[i - 1] != 'e' && s[i - 1] != 'E' || i == s.length() - 1)) isNumber = false;

            if (s[i] == 'e' || s[i] == 'E') {
                if (wasE) isNumber = false;
                wasE = true;
                if (i == 0 || i == s.length() - 1) isNumber = false;
            }

            if (s[i] == '.') {
                if (wasE || wasDot || s[i + 1] == '-') isNumber = false;
                else if (!wasDot) wasDot = true;
            }

        }
        if (isNumber) {
            if (wasDot || wasE) isNumber = false;
            else if (s[0] == '-') {
                s[0] = '1';
                if (s > "19223372036854775808") isNumber = false;
                s[0] = '-';
            } else {
                if (s > "9223372036854775807") isNumber = false;
            }
            if (isNumber) return stoll(s);
        }
        std::cerr << "Error\n";
    } while (true);
}

long double checkInput(long double t) {

    std::string s;
    do {
        bool isNumber = true;
        bool wasDot = false;
        bool wasE = false;
        std::cin >> s;

        for (long long i = 0; i < s.length() && isNumber; i++) {
            if ((s[i] != 'e' && s[i] != 'E') && s[i] != '-' && s[i] != '.' && !isItNumber(s[i])) isNumber = false;

            if (s[i] == '-')
                if (i != 0 && (s[i - 1] != 'e' && s[i - 1] != 'E' || i == s.length() - 1)) isNumber = false;

            if (s[i] == 'e' || s[i] == 'E') {
                if (wasE) isNumber = false;
                wasE = true;
                if (i == 0 || i == s.length() - 1) isNumber = false;
            }

            if (s[i] == '.') {
                if (wasE || wasDot || s[i + 1] == '-') isNumber = false;
                else if (!wasDot) wasDot = true;
            }

        }
        if (isNumber) {

            bool is0 = true;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != '0' && s[i] != '.' && s[i] != '-') is0 = false;
            }

            if (is0) {
                t = 0;
                return t;
            }


            std::string s1;
            if (s.size() > 307) isNumber = false;
            else if (!wasE) {
                if (wasDot) {
                    while (s[s.length() - 1] == '0' && s.length() != 1 && s[s.length() - 2] != '-') {
                        s.erase(s.length() - 1, 1);
                    }
                }
                if (s[s.length() - 1] == '.') s.erase(s.length() - 1, 1);
                s1 = s;
                s1[s1.length() - 1]--;
                if (stold(s) == stold(s1)) isNumber = false;
                else {
                    return stold(s);
                }
            } else {
                int e = s.find('e');
                if (e == -1) e = s.find('E');
                if (wasDot)
                    while (s[e - 1] == '0') {
                        s.erase(e - 1, 1);
                        e--;
                    }
                if (s[e - 1] == '.') {
                    s.erase(e - 1, 1);
                    e--;
                }
                s1 = s;
                s1[e - 1]--;
                if (stold(s) == stold(s1)) isNumber = false;
                else {
                    return stold(s);
                }
            }
        }
        if(isNumber) return t;
        else std::cerr << "Error\n";
    } while(true);
}


void inputNumber(long long *t) {
    *t = checkInput(*t);
}

void inputNumber(long double *t) {
    *t = checkInput(*t);
}

void inputArray(auto t, const long long *n, const std::string &text) {

    std::cout << text << "\n";
    for (long long i = 0; i < *n; i++) {
        t[i] = checkInput(t[i]);
    }
}

void outputArray(auto array, long long n) {
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << "\t";
    }
    std::cout << "\n\n";
}

int main() {

    std::string previewText = "Задача #1\nВариант 9\n\nРешение написал Александр Горгун\n\nСуть задания: ввести в консоль одномерный массив размером k.\nВывести в консоль 2 массива:\nОдин из массивов состоит из отрицательных элементов исходного массива.\nА второй из оставшихся элементов.\n\n";
    std::cout << previewText;

    const long long maxArraySize = 1000;
    long double defaultArray[maxArraySize],
            firstArray[maxArraySize],
            secondArray[maxArraySize];
    long long numberOfItems;
    long long i;

    while (true) {

        std::cout << "\nВведите кол-во  элементов в массиве (0 - выход из программы):\n";

        do {
            inputNumber(&numberOfItems);
            if (numberOfItems == 0) return 0;
            if (numberOfItems < 1 || numberOfItems > maxArraySize) std::cerr << "Error\n";
        } while (numberOfItems < 1 || numberOfItems > maxArraySize);


        inputArray(defaultArray, &numberOfItems,
                   "\nВведите массив состоящий из " + std::to_string(numberOfItems) + " элемента(ов)\n");

        long long firstArrayPoint = 0, secondArrayPoint = 0;

        for (i = 0; i < numberOfItems; i++)
            (defaultArray[i] < 0 ? firstArray[firstArrayPoint++] : secondArray[secondArrayPoint++]) = defaultArray[i];

        std::cout << "\nПервый массив:\n";
        if (firstArrayPoint) {
            outputArray(firstArray, firstArrayPoint);
        } else {
            std::cout << "Пусто\n\n";
        }

        std::cout << "Второй массив:\n";
        if (secondArrayPoint) {
            outputArray(secondArray, secondArrayPoint);
        } else {
            std::cout << "Пусто\n\n";
        }

        std::cout << "Ah shit. Here we go again.\n\n";
    }
}
