//приложение, состоящее из двух QLabel и одной кнопки QPushButton.
//По нажатию на кнопку текст в лейблах меняется местами

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
    static bool b = 0;

     if (b) { b=false;
                ui->label_a->setText("hello");
                ui->label_b->setText("");
     }else {
            b=true;
         ui->label_a->setText("");
         ui->label_b->setText("hello");
     }



}


