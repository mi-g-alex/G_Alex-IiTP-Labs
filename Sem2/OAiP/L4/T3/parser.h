#include <string>
#include <regex>
#include <QString>

QString searchValues(const QString &s) {
    std::string cd = s.toStdString();
    std::regex pat(
            R"((?!MainWindow)([A-Z][A-Za-z_]*?|int|char|bool|std::string|QString)(\*)?\s+(\*)?(?!main)(\w+)((\s*=)\s*(?!new)([^\n;]+))?\s*;)");
    std::cmatch m;
    std::unordered_map<QString, int> types;
    QString res = "";
    while (std::regex_search(cd.c_str(), m, pat)) {
        std::string t_name = m[1].str();
        std::string p = m[2].str();
        std::string p_ = " " + m[3].str();
        std::string v_name = m[4].str();
        std::string d_value = m[7].str();
        types[t_name.c_str()]++;
        res += QString::fromStdString(t_name);
        if (p == "*") {
            res += QString::fromStdString(p);
        } else if (p_ == " *") {
            res += QString::fromStdString(p_);
        } else {
            res += " ";
        }
        res += QString::fromStdString(v_name);
        if (!d_value.empty()) {
            res += " = ";
            res += QString::fromStdString(d_value);
        }
        res += "\n";
        cd = m.suffix().first;
    }
    res += "\n\n";

    for (const auto &i: types) {
        res += "Count vars of type ";
        res += i.first;
        res += ": ";
        res += QString::number(i.second);
        res += "\n";
    }
    if (res == "\n\n") return "";
    return res;
}

QString searchClasses(const std::string &code) {
    std::string res_1 = code;
    std::string res_2 = code;
    std::string res_3 = code;
    std::string ans;
    int nmbOfClasses = 0, nmbOfStruct = 0, nmbOfArrays = 0;
    std::regex class_pattern(R"(class\s+\w+\s*\{)");
    std::regex struct_pattern(R"(struct\s+\w+\s*\{)");
    std::regex array_pattern(R"(\w+\s+\w+\s*\[\s*\d+\s*\](;|(\s*=\s*\{)?))");

    std::cmatch match;

    while (std::regex_search(res_1.c_str(), match, class_pattern)) {
        nmbOfClasses++;
        res_1 = match.suffix().first;
    }
    while (std::regex_search(res_2.c_str(), match, struct_pattern)) {
        nmbOfStruct++;
        res_2 = match.suffix().first;
    }
    while (std::regex_search(res_3.c_str(), match, array_pattern)) {
        nmbOfArrays++;
        res_3 = match.suffix().first;
    }

    return QString(
            "Классов: " + QString::number(nmbOfClasses) +
            "\nСтруктур: " + QString::number(nmbOfStruct) +
            "\nМассивов: " + QString::number(nmbOfArrays)
    );

}

QString searchPrototypes(const QString &s) {
    QString ans;
    std::regex pattern(R"((\w+\s*)(\*|\s)+\s*(\w+)\((.*?)\)\s*(\;|\{))");
    std::string input = s.toStdString();
    std::sregex_iterator next(input.begin(), input.end(), pattern);
    std::sregex_iterator end;

    while (next != end) {
        std::smatch match = *next;
        std::string str = match[0].str();
        if (str.find("regex") > str.size() - 1) {
            ans += QString::fromStdString(str) + "\n";
        }
        ++next;
    }
    return ans;
}

QString searchChanges(const QString &s) {
    std::string cd = s.toStdString();
    QString res;
    int line = 0, pos;
    std::cmatch match;
    std::regex pattern(R"((\b\w+\b)((\[[^\]]*\])*)\s*=\s*(.*);)");
    while (std::regex_search(cd.c_str(), match, pattern)) {
        pos = cd.find(match[0].str());
        line += std::count(&cd[0], &cd[0] + pos, '\n');
        res += "Line " + QString::number(line) + ": " + QString::fromStdString(match.str()) + "\n";
        cd = match.suffix().first;
    }
    return res;
}

QString searchLocVal(const QString &s) {
    QString result;
    QStringList lines = s.split("\n");
    int br = 0;
    for (int i = 0; i < lines.size(); ++i) {
        if (std::count(lines[i].begin(), lines[i].end(), '{')) br++;
        if (br > 0) {
            std::regex pattern("\\b(?!(class|struct|void|return)\\s)(\\w+)((\\s+)|(\\s*(\\*)\\s*))(\\w+)\\s*(=\\s*(\\S+))?\\s*(,\\s*\\w+\\s*(=\\s*(\\S+))?)*\;");
            std::string c = lines[i].toStdString();
            std::cmatch match;
            while (std::regex_search(c.c_str(), match, pattern)) {
                result += "line " + QString::number(i + 1) + " " + QString::fromStdString(match[0]) + "\n";
                c = match.suffix().first;
            }
        }
        if (std::count(lines[i].begin(), lines[i].end(), '}')) br--;
    }
    return result;
}

QString searchReloadFun(const QString &s) {
    std::string cd = s.toStdString();
    QString res = "";
    std::regex pattern(R"(\b([a-zA-Z_][a-zA-Z0-9_]*)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*\(([^()]*)\)\s*\{)");
    std::map<std::string, std::vector<int>> f;
    int count_ = 0;
    std::sregex_iterator s_start(cd.cbegin(), cd.cend(), pattern);
    std::sregex_iterator s_end;
    while (s_start != s_end) {
        std::string f_name = (*s_start)[2].str();
        std::string f_par = (*s_start)[3].str();
        auto m_end = cd.begin() + (*s_start).position() + (*s_start).length();
        f[f_name].push_back(count(cd.begin(), m_end, '\n'));
        ++s_start;
    }
    for (const auto &it: f) {
        if (it.second.size() > 1) {
            res += "Функции ";
            res += QString::fromStdString(it.first);
            res += " переопределены в строках: ";
            for (auto lin: it.second) {
                res += QString::number(lin) + " ";
                count_++;
            }
            res += '\n';
        }
    }
    res += "\n\nКол-во " + QString::number(count_);
    return res;
}


QString searchGlub(const QString &in) {
    QStringList lineL = in.split("\n");
    QString ans = "";
    std::regex pattern(R"(\b(if)\s*\(\S+.*\)\s*(\{?))");
    std::cmatch match;
    int br = 0;
    std::stack<int> s;

    for (int i = 0; i < lineL.size(); i++) {
        std::string l = lineL[i].toStdString();
        for (char j: l) {
            if (j == '{')
                br++;
            if (j == '}') {
                if (!s.empty() && s.top() == br) {
                    s.pop();
                }
                br--;
            }
        }
        while (std::regex_search(l.c_str(), match, pattern)) {
            if (match[2].str() == "{") {
                s.push(br);
                ans += QString::number(i + 1) + " : глуб - " + QString::number(s.size() + 1) + "\n";
            } else
                ans += QString::number(i + 1) + " : глуб - " + QString::number(s.size() + 2) + "\n";
            l = match.suffix().str();
        }
    }
    return ans;
}

QString searchError(const QString &s) {
    std::string code = s.toStdString();
    QString result;
    std::regex p(R"(((const)\s+(bool)\s+([a-z]*)\s*(=)\s*(true|false)\s*);)");
    std::string b;
    std::cmatch m;
    while (std::regex_search(code.c_str(), m, p)) {
        b = "while(";
        b += m[4].str();
        b.push_back(')');

        QStringList lineList = s.split('\n');
        for (const auto &i: lineList) {
            qDebug() << b.c_str() << " ";
            qDebug() << i.toStdString().c_str() << Qt::endl;
            if (!strcmp(b.c_str(), i.toStdString().c_str())) {
                result += m[1].str().c_str();
                result += '\n';
                result += i;
                result += '\n';
            }
        }
        code = m.suffix().first;
    }
    result += '\n';
    std::regex pattern(R"((while\(true\)|while\(false\)))");
    std::cmatch match;
    while (std::regex_search(code.c_str(), match, pattern)) {
        result += match.str().c_str();
        result += '\n';
        code = match.suffix().first;
    }
    if (result == '\n') return "";
    return result;
}
