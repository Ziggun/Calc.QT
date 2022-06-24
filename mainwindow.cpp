#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first; // первое число пользователя

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->p0,SIGNAL(clicked()),this,SLOT(digits_num())); // передаём кнопки через сигналы и слоты
    connect(ui->p1,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p2,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p3,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p4,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p5,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p6,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p7,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p8,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p9,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->pDivision,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pPlus,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pMinus,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pMult,SIGNAL(clicked()),this,SLOT(math()));

    ui->pDivision->setCheckable(true);
    ui->pMult->setCheckable(true);
    ui->pPlus->setCheckable(true);
    ui->pMinus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_num()
{
   QPushButton *button = (QPushButton* )sender(); //метод получения кнопки.
   double all_numbers;
   QString new_label;
   all_numbers = (ui->label->text()+button->text()).toDouble(); // Создаём огромное число
   new_label = QString::number(all_numbers,'g',15); // записываем его в строку, cтиль оставляем, а количество знаков увеличиваем
   ui->label->setText(new_label); // выводим строку
}

void MainWindow::on_pDot_clicked()
{
    if(!(ui->label->text().contains('.'))) // проверяем наличие точки
     ui->label->setText(ui->label->text()+"."); // добавляем её
}

void MainWindow::on_pDelete_clicked()
{
    ui->pPlus->setChecked(false);
    ui->pMult->setChecked(false);
    ui->pDivision->setChecked(false);
    ui->pMinus->setChecked(false);
    ui->label->setText("0");
}

void MainWindow::on_Result_clicked()
{
    double label_num, num_sec;
    QString new_label;
    num_sec = ui->label->text().toDouble();

    if(ui->pPlus->isChecked()) {
        label_num = num_first + num_sec;
        new_label = QString::number(label_num,'g',15);
        ui->label->setText(new_label);
        ui->pPlus->setChecked(false);

    } else if (ui->pMinus->isChecked()) {

               label_num = num_first - num_sec;
               new_label = QString::number(label_num,'g',15);
               ui->label->setText(new_label);
               ui->pMinus->setChecked(false);

    }  else if (ui->pDivision->isChecked()) {
        if(num_sec == 0) {
            ui->label->setText("0");
           }
        else {

                label_num = num_first / num_sec;
                new_label = QString::number(label_num,'g',15);
                ui->label->setText(new_label);
            }
                ui->pDivision->setChecked(false);

    }  else if (ui->pMult->isChecked()) {
                label_num = num_first * num_sec;
                new_label = QString::number(label_num,'g',15);
                ui->label->setText(new_label);
                ui->pMult->setChecked(false);
    }
}

void MainWindow::math()
{
   QPushButton *button = (QPushButton* )sender();
   num_first = ui->label->text().toDouble();
   ui->label->setText("");
   button->setChecked(true); // метод проверки на + или - у числа

}
