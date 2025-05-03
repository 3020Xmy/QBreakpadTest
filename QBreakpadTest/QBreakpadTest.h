#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QBreakpadTest.h"
#include "QBreakpadHandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QBreakpadTestClass; };
QT_END_NAMESPACE

class QBreakpadTest : public QMainWindow
{
    Q_OBJECT

public:
    QBreakpadTest(QWidget *parent = nullptr);
    ~QBreakpadTest();

public slots:
    void on_testDump();     //触发访问违规崩溃
    void on_test2Dump();    //触发除零异常崩溃
    void on_test3Dump();    //触发数组越界崩溃
    void on_test4Dump();    //触发异常未捕获崩溃

private:
    Ui::QBreakpadTestClass *ui;
};
