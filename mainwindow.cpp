#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), fileName(""), sheetName(""), depth(0), dose(0.0),
    duration(0), skinDose(0), doseRate(0), skinDoseRate(0), durationM(0)
{
    ui->setupUi(this);


    /*Set the first file as initial*/
    ui->RB140->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QXlsx::Document xlsx(fileName);

    sheetName = ui->comboBox->currentText();
    xlsx.selectSheet(sheetName);

    depth = ui->spinBox->text().toInt();

    /*Changed the method to correct data handling on any platform*/
    dose = QString::number(ui->doubleSpinBox->value(), 'f', ui->doubleSpinBox->decimals()).toDouble();

    /*Added & to avoid memory corruption tht depends on QT implementation*/
    QXlsx::Cell& D = *xlsx.cellAt(depth+7,6);
    doseRate = D.value().toDouble();
    duration = dose/doseRate;
    durationM = static_cast<int>(duration); //Added static_cast to avoid warnings

    /*Added & to avoid memory corruption tht depends on QT implementation*/
    QXlsx::Cell& S = *xlsx.cellAt(7,6);
    skinDoseRate = S.value().toDouble();
    skinDose = duration*skinDoseRate;

    ui->DurationM->setText(QString::number(durationM));
    ui->DurationS->setText(QString::number((duration-durationM)*60));
    ui->SkinDose->setText(QString::number(skinDose));
}

void MainWindow::on_RB140_clicked()
{
    fileName = ":/files/dose calculation 140keV.xlsx";
    init(fileName);
}

void MainWindow::on_RB180_clicked()
{
    fileName = ":/files/dose calculation 180keV.xlsx";
    init(fileName);
}

void MainWindow::on_RB200_clicked()
{
    fileName = ":/files/dose calculation 200keV.xlsx";
    init(fileName);
}

void MainWindow::on_RB220_clicked()
{
    fileName = ":/files/dose calculation 220keV.xlsx";
    init(fileName);
}

void MainWindow::init(const QString &fileName)
{
    QXlsx::Document xlsx(fileName);
    QPixmap myPixmap(":/files/radioactive.png" );

    ui->label_2->setPixmap( myPixmap );

    int countSheets = xlsx.sheetNames().size();
    ui->comboBox->clear();

    for(int i = 0; i < countSheets; i++)
    {
        ui->comboBox->addItem(xlsx.sheetNames().takeAt(i));
    }
}
