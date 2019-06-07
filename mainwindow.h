#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

#include <QDebug>
#include <QVariant>
#include <QMainWindow>

using namespace QXlsx;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_RB140_clicked();

    void on_RB180_clicked();

    void on_RB200_clicked();

    void on_RB220_clicked();

private:
    Ui::MainWindow *ui;
    QString fileName;
    QString sheetName;
    int depth;
    double dose;
    double duration;
    double skinDose;
    double doseRate;
    double skinDoseRate;
    int durationM;
};

#endif // MAINWINDOW_H
