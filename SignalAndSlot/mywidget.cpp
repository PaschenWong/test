//自定义signal和slot

#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPushButton>

//Teacher类
//Student类
//下课后，老师会发出信号饿了，学生响应信号请吃饭

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);  //ui的代码，不管他就好

    //创建一个老师对象
    this->zt = new Teacher(this);

    //创建一个学生对象
    this->st = new Student(this);

//    //老师饿了就学生请客
//    connect(zt, &Teacher::hungry, st, &Student::treat);

    //连接带参数的信号和槽
    //重载时，要用函数指针指向函数地址
    void (Teacher:: *teacherSignal) (QString) = &Teacher::hungry;  //此时指定参数之后就没有歧义了
    void (Student:: *StudentSlot) (QString) = &Student::treat;
    //这里函数前面的作用域很重要！！因为这个函数是类内的函数，所以指针也必须是类内的指针
    connect(zt, teacherSignal, st, StudentSlot);  //信号重载时，找信号的地址会有歧义

    //点击下课按钮才会下课
    QPushButton *btn = new QPushButton("下课", this);
    this->resize(600, 400);
    btn->move(100, 100);
    connect(btn, &QPushButton::clicked, this, &MyWidget::ClassIsOver);  //注意函数一定要著名作用域

    //无参情况
    void (Teacher:: *teacherSignal2) () = &Teacher::hungry;
    void (Student:: *StudentSlot2) () = &Student::treat;
    connect(zt, teacherSignal2, st, StudentSlot2);

    //信号连接信号（信号会触发另一个信号）
    connect(btn, &QPushButton::clicked, zt, teacherSignal2);

    //断开信号
    //disconnect(zt, teacherSignal2, st, StudentSlot2);
    //PS:这个的底层就是文本查找函数，所以不会对比参数
    connect(zt, SIGNAL(hungry()), st, SLOT(treat()));  //这是4版本以前的连接，和上行作用一样
    //优点就是参数直观，确定是类型不做检测，此时信号参数和槽参数不匹配不会被检测出来的

    //调用下课函数
//    ClassIsOver();
}
void MyWidget::ClassIsOver()
{
    //下课函数，出发hungry
    //emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
    //出发自定义信号要用到emit
}

MyWidget::~MyWidget()
{
    delete ui;
}

