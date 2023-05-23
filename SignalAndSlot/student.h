#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    //早期slots必须要写在public slots下，高级版本可以写在public或者全局下
    //返回值void，需要声明和实现
    //可以有参数，故可以重载
    void treat();

    void treat(QString foodName);
};

#endif // STUDENT_H
