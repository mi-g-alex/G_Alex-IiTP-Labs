//
// Created by g_alex on 3/16/23.
//

#ifndef L2T3_RPE_H
#define L2T3_RPE_H

#include <QtWidgets>
#include "../stack/stack.h"

class rpe {
public:
    QString toRpe(const QString& s);

    /*QString fromRpe(QString s);

    long double getNumber(QString, long long pos); */

    long double countRpe(std::string s);

    bool isSymbol(char c) {
        return (c == '/' || c == '-' || c == '*' || c == '+' || c == '^' || c == '~');
    }

};


#endif //L2T3_RPE_H
