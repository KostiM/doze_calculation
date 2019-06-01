#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton_2->isChecked())
    {
        QXlsx::Document xlsx("../doze_calculation/dose calculation 140keV_true.xlsx");

        //xlsx.selectSheet("4x4");

        qDebug() << xlsx.sheetNames();

        int row = xlsx.dimension().lastRow();
        int col = xlsx.dimension().lastColumn();
        qDebug() << "row = " << row << " " << " col = " << col;

        qDebug()<<xlsx.read("A10");
        qDebug()<<xlsx.read("B10");
        qDebug()<<xlsx.read("C10");
    }
    else if (ui->radioButton_4->isChecked())
    {
        QXlsx::Document xlsx("../doze_calculation/dose calculation 180keV_true.xlsx");

        //xlsx.selectSheet("4x4");

        qDebug() << xlsx.sheetNames();

        int row = xlsx.dimension().lastRow();
        int col = xlsx.dimension().lastColumn();
        qDebug() << "row = " << row << " " << " col = " << col;

        qDebug()<<xlsx.read("A10");
        qDebug()<<xlsx.read("B10");
        qDebug()<<xlsx.read("C10");

    }
    else if (ui->radioButton->isChecked())
    {
        QXlsx::Document xlsx("../doze_calculation/dose calculation 200keV_true.xlsx");

        //xlsx.selectSheet("4x4");

        qDebug() << xlsx.sheetNames();

        int row = xlsx.dimension().lastRow();
        int col = xlsx.dimension().lastColumn();
        qDebug() << "row = " << row << " " << " col = " << col;

        qDebug()<<xlsx.read("A10");
        qDebug()<<xlsx.read("B10");
        qDebug()<<xlsx.read("C10");

    }
    else if (ui->radioButton_3->isChecked())
    {
        QXlsx::Document xlsx("../doze_calculation/dose calculation220keV_true.xlsx");

        //xlsx.selectSheet("4x4");

        qDebug() << xlsx.sheetNames();

        int row = xlsx.dimension().lastRow();
        int col = xlsx.dimension().lastColumn();
        qDebug() << "row = " << row << " " << " col = " << col;

        qDebug()<<xlsx.read("A10");
        qDebug()<<xlsx.read("B10");
        qDebug()<<xlsx.read("C10");

    }
}
