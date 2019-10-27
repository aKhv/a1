// программа обмена сообщениями между окнами
//По нажатию на кнопку текст  QTextEdit
// в  меняется местами

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
 QString str_a = ui->textEdit_b->toPlainText();
 QString str_b = ui->textEdit_a->toPlainText();
    ui->textEdit_b->clear();
    ui->textEdit_a->clear();

 ui->textEdit_a->append(str_a);




 ui->textEdit_b->append(str_b);



}
