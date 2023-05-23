#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "teacher.h"
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
    Teacher *zt;
    Student *st;

    void ClassIsOver();

private:
    Ui::MyWidget *ui;
};
#endif // MYWIDGET_H
