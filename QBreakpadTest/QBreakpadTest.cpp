#include "QBreakpadTest.h"

QBreakpadTest::QBreakpadTest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QBreakpadTestClass())
{
    ui->setupUi(this);
    QBreakpadInstance.setDumpPath("E:\Code\Vs\QBreakpadTest\x64\Release");    // 设置生成dump文件路径

    connect(ui->pushButton, &QPushButton::clicked, this, &QBreakpadTest::on_testDump);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &QBreakpadTest::on_test2Dump);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &QBreakpadTest::on_test3Dump);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &QBreakpadTest::on_test4Dump);
}

QBreakpadTest::~QBreakpadTest()
{
    delete ui;
}

/*  触发访问违规崩溃
*/
void QBreakpadTest::on_testDump() {
    int* pTest = NULL;
    (*pTest) = 1;
}

/*  触发除零异常崩溃
*/
void QBreakpadTest::on_test2Dump() {
    int a = 0;
    int x = 1 / a;
}

/*  触发数组越界崩溃
*/
void QBreakpadTest::on_test3Dump() {
    int arr[5] = { 0 };
    arr[10] = 1; //越界访问
}

/*  触发异常未捕获崩溃
*/
void QBreakpadTest::on_test4Dump() {
    throw std::runtime_error("抛出异常");
}