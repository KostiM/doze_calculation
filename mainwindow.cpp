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
  QXlsx::Document xlsx(fileName);
  sheetName = ui->comboBox->currentText();
  xlsx.selectSheet(sheetName);
  depth = ui->spinBox->text().toInt();
  dose = ui->doubleSpinBox->text().toDouble();
  Cell D = *xlsx.cellAt(depth+7,6);
  doseRate = D.value().toDouble();
  duration = dose/doseRate;
  durationM = duration;
  Cell S = *xlsx.cellAt(7,6);
  skinDoseRate = S.value().toDouble();
  skinDose = duration*skinDoseRate;
  ui->DurationM->setText(QString::number(durationM));
  ui->DurationS->setText(QString::number((duration-durationM)*60));
  ui->SkinDose->setText(QString::number(skinDose));

}

void MainWindow::on_RB140_clicked()
{
    fileName = "../doze_calculation/dose calculation 140keV.xlsx";
    QXlsx::Document xlsx(fileName);

    int countSheets = xlsx.sheetNames().size();

    ui->comboBox->clear();

    for(int i = 0; i< countSheets; i++)
    {
        ui->comboBox->addItem(xlsx.sheetNames().takeAt(i));
    }
}

void MainWindow::on_RB180_clicked()
{
    fileName = "../doze_calculation/dose calculation 180keV.xlsx";

    QXlsx::Document xlsx(fileName);

    int countSheets = xlsx.sheetNames().size();

    ui->comboBox->clear();

    for(int i = 0; i< countSheets; i++)
    {
        ui->comboBox->addItem(xlsx.sheetNames().takeAt(i));
    }
}

void MainWindow::on_RB200_clicked()
{
    fileName = "../doze_calculation/dose calculation 200keV.xlsx";

    QXlsx::Document xlsx(fileName);

    int countSheets = xlsx.sheetNames().size();

    ui->comboBox->clear();

    for(int i = 0; i< countSheets; i++)
    {
        ui->comboBox->addItem(xlsx.sheetNames().takeAt(i));
    }
}

void MainWindow::on_RB220_clicked()
{
    fileName = "../doze_calculation/dose calculation 220keV.xlsx";

    QXlsx::Document xlsx(fileName);

    int countSheets = xlsx.sheetNames().size();

    ui->comboBox->clear();

    for(int i = 0; i< countSheets; i++)
    {
        ui->comboBox->addItem(xlsx.sheetNames().takeAt(i));
    }
}
