#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tasktypes.h"

#include "intmatrix.h"

#include "vector"

#include "singleunitsystem.h"
#include "unitswithlocalmemory.h"
#include "unitswithsharedmemory.h"

using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addition_toggled(bool checked);

    void on_multiplication_toggled(bool checked);

    void on_transposition_toggled(bool checked);

    void on_oneUnit_toggled(bool checked);

    void on_m1_toggled(bool checked);

    void on_m2_toggled(bool checked);

    void on_generateA_clicked();

    void on_generateB_clicked();

    void on_clearA_clicked();

    void on_clearB_clicked();

    void on_clearC_clicked();

    void on_start_clicked();

private:
    Ui::MainWindow *ui;

    TaskTypes taskType = Addition;

    TaskPerformTypes taskPerformType = SingleUnit;

    IntMatrix matrixA;
    IntMatrix matrixB;
    IntMatrix matrixC;

    SingleUnitSystem singleUnitSystem;
    UnitsWithLocalMemorySystem unitsWithLocalMemory;
    UnitsWithSharedMemorySystem unitsWithSharedMemory;

};

#endif // MAINWINDOW_H
