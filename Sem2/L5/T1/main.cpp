//#include <iostream>
#include "MyQueue/MyQueue.h"
//#include <queue>
#include <QtWidgets>

class CycleTextScroll : public QPlainTextEdit {
public:
    explicit CycleTextScroll(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event) override;

public:
    MyQueue linesQueue;

    void updateText();
};

CycleTextScroll::CycleTextScroll(QWidget *parent) : QPlainTextEdit(parent) {
    setReadOnly(true);
}

void CycleTextScroll::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().ry() < 0) {
        // Прокрутка вверх
        QString line = linesQueue.front();
        linesQueue.pop();
        linesQueue.push(line);
    }

    updateText();
}

void CycleTextScroll::updateText() {
    QString text;
    MyQueue tmp_;
    int t = linesQueue.size();
    for (int i = 0; i < t; i++) {
        QString s = linesQueue.front();
        text += s + "\n";
        linesQueue.pop();
        tmp_.push(s);
    }

    for(int i = 0; i < t; i++) {
        QString s = tmp_.front();
        tmp_.pop();
        linesQueue.push(s);
    }

    setPlainText(text);
}


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CycleTextScroll cycleTextScroll;

    // Вставьте текст программы в виджет
    QStringList programLines = {
            "#include \"MyQueue.h\"\n",
            "\n",
            "size_t MyQueue::size() const {\n",
            "    return size_;\n",
            "}\n",
            "\n",
            "bool MyQueue::empty() const {\n",
            "    return size_ == 0;\n",
            "}\n",
            "\n",
            "template<typename... Args>\n",
            "void MyQueue::emplace(Args &&... args) {\n",
            "\n",
            "}\n",
            "\n",
            "QString &MyQueue::front() {\n",
            "    return startNode->line;\n",
            "}\n",
            "\n",
            "QString &MyQueue::back() {\n",
            "    return endNode->line;\n",
            "}\n",
            "\n",
            "void MyQueue::pop() {\n",
            "    if (size_ > 0) {\n",
            "        startNode->next->prev = std::move(endNode);\n",
            "        endNode->next = std::move(startNode->next);\n",
            "        size_--;\n",
            "        startNode = std::move(endNode->next);\n",
            "    }\n",
            "}\n",
            "\n",
            "void MyQueue::push(QString &line) {\n",
            "    SharedPtr<Node> tmp_ = make_shared<Node>(line);\n",
            "    if (size_ == 0) {\n",
            "        startNode = std::move(tmp_);\n",
            "        endNode = std::move(startNode);\n",
            "        startNode->next = std::move(startNode);\n",
            "        startNode->prev = std::move(startNode);\n",
            "        endNode->prev = std::move(startNode);\n",
            "        endNode->prev = std::move(startNode);\n",
            "        size_++;\n",
            "    } else {\n",
            "        endNode = std::move(tmp_);\n",
            "        startNode->prev->next = std::move(endNode);\n",
            "        endNode->prev = std::move(startNode->prev);\n",
            "        endNode->next = std::move(startNode);\n",
            "        startNode->prev = std::move(endNode);\n",
            "        size_++;\n",
            "    }\n",
            "}\n",
            "\n",
            "void MyQueue::swap(MyQueue a, MyQueue b) {\n",
            "\n",
            "}"
    };

    for (const QString &line: programLines) {
        QString s = line;
        cycleTextScroll.linesQueue.push(s);
    }

    cycleTextScroll.updateText();
    cycleTextScroll.show();

    return app.exec();
}