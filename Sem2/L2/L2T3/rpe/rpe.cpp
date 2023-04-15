#include "rpe.h"

QString rpe::toRpe(const QString &tmp) {
    std::string s = tmp.toStdString();
    stack symbols;
    QString ans;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ')
            s = s.erase(i--, 1);
    }
    s += ' ';
    if (s[0] == '-') s[0] = '~';
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '-') {
            if (isSymbol(s[i - 1]) || s[i - 1] == '(') s[i] = '~';
        }
    }
    for (int i = 0; i < s.size(); i++) {
       // if(s[i] != '(' && s[i] != ')' && s[i] != '+' && s[i] != '-' && s[i] != '^' && s[i] != '~' && s[i] != '*' && s[i] != s['/'] && (s['i'] < '0' || s[i] > '9')) return {"|"};
        if (s[i] == '(') {
            if (i == s.size() - 1) { return {"|"}; }
            else if(s[i + 1] == ')') {
                i++;
            }
            if (!isSymbol(s[i + 1]) || s[i + 1] == '~') symbols.push(s[i]);
            else
                return {"|1"};
        }
        if ((s[i] >= '0' && s[i] <= '9')) {
            QString t;
            while (s[i] >= '0' && s[i] <= '9' || s[i] == '.') {
                t += s[i];
                i++;
            }

            bool tru;
            t.toDouble(&tru);
            if (tru) ans += t + " ";
            else return {"|2"};
        }
        if (s[i] == ')') {
            if (symbols.getSize() > 0)
                while (symbols.top()->c != '(') {
                    ans += symbols.top()->c;
                    ans += ' ';
                    symbols.pop();
                    if (symbols.getSize() == 0) break;
                }
            if (symbols.getSize() != 0) symbols.pop();
            else return {"|"};
        }
        if (s[i] == '^') {
            if (!isSymbol(s[i + 1]))
                symbols.push('^');
            else return {"|3"};
        }

        if (s[i] == '~') {
            if (!isSymbol(s[i + 1])) {
                if (symbols.getSize() > 0) {
                    while (symbols.top()->c == '^') {
                        ans += symbols.top()->c;
                        ans += ' ';
                        symbols.pop();
                        if (symbols.getSize() == 0) break;
                    }
                }
                symbols.push(s[i]);
            } else return {"|4"};
        }

        if (s[i] == '*' || s[i] == '/') {
            if (!isSymbol(s[i + 1])) {
                if (symbols.getSize() > 0) {
                    while (symbols.top()->c == '^' || symbols.top()->c == '*' || symbols.top()->c == '/') {
                        ans += symbols.top()->c;
                        ans += ' ';
                        symbols.pop();
                        if (symbols.getSize() == 0) break;
                    }
                }
                symbols.push(s[i]);
            } else return {"|5"};
        }

        if (s[i] == '-' || s[i] == '+') {
            if (!isSymbol(s[i + 1])) {
                if (symbols.getSize() > 0) {
                    while (symbols.top()->c == '^' || symbols.top()->c == '*' || symbols.top()->c == '/'
                           || symbols.top()->c == '+' || symbols.top()->c == '-') {
                        ans += symbols.top()->c;
                        ans += ' ';
                        symbols.pop();
                        if (symbols.getSize() == 0) break;
                    }
                }
                symbols.push(s[i]);
            } else return {"|6"};
        }
    }

    while (symbols.getSize() > 0) {
        if(symbols.top()->c == '(') return {"|"};
        ans += symbols.top()->c;
        ans += ' ';
        symbols.pop();
    }
    ans += "\t= ";
    long double ttttmp = countRpe(ans.toStdString());
    if (ttttmp == INT64_MAX) ans = "|";
    else ans += QString::number((double) ttttmp);
    return ans;
}

long double rpe::countRpe(std::string s) {

    stack ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            QString t;
            while (s[i] >= '0' && s[i] <= '9' || s[i] == '.') {
                t += s[i];
                i++;
            }
            qDebug() << "Res1 : " << t;
            ans.push((long double) t.toDouble());
        }

        if (s[i] == '^') {
            if (ans.getSize() > 1) {
                long double tmp1 = ans.top()->x;
                ans.pop();
                long double tmp2 = ans.top()->x;
                tmp2 = std::pow(tmp2, tmp1);
                ans.pop();
                ans.push(tmp2);
            } else return INT64_MAX;

        }

        if (s[i] == '*') {
            if (ans.getSize() > 1) {
                long double tmp1 = ans.top()->x;
                ans.pop();
                long double tmp2 = ans.top()->x;
                tmp2 *= tmp1;
                ans.pop();
                ans.push(tmp2);
            } else return INT64_MAX;

        }

        if (s[i] == '/') {
            if (ans.getSize() > 1) {
                long double tmp1 = ans.top()->x;
                ans.pop();
                long double tmp2 = ans.top()->x;
                if (tmp1 == '0') return INT64_MAX;
                tmp2 /= tmp1;
                ans.pop();
                ans.push(tmp2);
            } else return INT64_MAX;
        }

        if (s[i] == '+') {
            qDebug() << "+";
            if (ans.getSize() > 1) {
                long double tmp1 = ans.top()->x;
                ans.pop();
                long double tmp2 = ans.top()->x;
                qDebug() << "+|";
                tmp2 += tmp1;
                qDebug() << "+~";
                ans.pop();
                ans.push(tmp2);
                qDebug() << (double) ans.top()->x;
            } else return INT64_MAX;
        }

        if (s[i] == '-') {
            if (ans.getSize() > 1) {
                long double tmp1 = ans.top()->x;
                ans.pop();
                long double tmp2 = ans.top()->x;
                tmp2 -= tmp1;
                ans.pop();
                ans.push(tmp2);
            } else return INT64_MAX;
        }

        if (s[i] == '~') {
            if (ans.getSize() > 0) {
                long double tmp1 = ans.top()->x;
                ans.pop();
                tmp1 *= -1;
                ans.push(tmp1);
            } else return INT64_MAX;
        }
    }
    return ans.top()->x;

}