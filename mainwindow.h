#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "3rdParty/qtxlsx/src/xlsx/xlsxdocument.h"
#include "3rdParty/qtxlsx/src/xlsx/xlsxchartsheet.h"
#include "3rdParty/qtxlsx/src/xlsx/xlsxcellrange.h"
#include "3rdParty/qtxlsx/src/xlsx/xlsxchart.h"
#include "3rdParty/qtxlsx/src/xlsx/xlsxrichstring.h"
#include "3rdParty/qtxlsx/src/xlsx/xlsxworkbook.h"
#include <QDebug>
#include <QVariant>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
