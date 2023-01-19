//
// Created by 86156 on 2023/1/7.
//

#ifndef QT_STARTANDEND_H
#define QT_STARTANDEND_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui1 {
    class StartAndEnd;
}
QT_END_NAMESPACE

class StartAndEnd : public QWidget {
Q_OBJECT

public:
    explicit StartAndEnd(QWidget *parent = nullptr);

    ~StartAndEnd() override;

    int get_start() const {
        return this->start;
    }

    int get_end() const {
        return this->end;
    }

private:
    Ui1::StartAndEnd *ui;
    int start{};
    int end{};
};

#endif //QT_STARTANDEND_H
