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

void MainWindow::on_addition_toggled(bool checked)
{
    if(checked){
        taskType = Addition;
    }
}

void MainWindow::on_multiplication_toggled(bool checked)
{
    if(checked){
        taskType = Multiplication;
    }
}

void MainWindow::on_transposition_toggled(bool checked)
{
    if(checked){
        taskType = Transposition;
    }
}

void MainWindow::on_oneUnit_toggled(bool checked)
{
    if(checked){
        taskPerformType = SingleUnit;
    }
}

void MainWindow::on_m1_toggled(bool checked)
{
    if(checked){
        taskPerformType = UnitsWithLocalMemory;
    }
}

void MainWindow::on_m2_toggled(bool checked)
{
    if(checked){
        taskPerformType = UnitsWithSharedMemory;
    }
}

void MainWindow::on_generateA_clicked()
{
    matrixA = IntMatrix(ui->rowsA->value(), ui->columnsA->value());
    matrixA.RandomMatrixGeneration();

    if(matrixA.GetRowCount() < 100 && matrixA.GetColCount() < 100){
        ui->matrixAView->setText(QString::fromStdString(matrixA.ToString()));
    }else{
        ui->matrixAView->setText("Матриця завелика для відображення!");
    }
}

void MainWindow::on_generateB_clicked()
{
    matrixB = IntMatrix(ui->rowsB->value(), ui->columnsB->value());
    matrixB.RandomMatrixGeneration();

    if(matrixB.GetRowCount() < 100 && matrixB.GetColCount() < 100){
        ui->matrixBView->setText(QString::fromStdString(matrixB.ToString()));
    }else{
        ui->matrixBView->setText("Матриця завелика для відображення!");
    }
}

void MainWindow::on_clearA_clicked()
{
    matrixA.Clear();
    ui->rowsA->setValue(matrixA.GetRowCount());
    ui->columnsA->setValue(matrixA.GetColCount());
    ui->matrixAView->setText(QString::fromStdString(matrixA.ToString()));
}

void MainWindow::on_clearB_clicked()
{
    matrixB.Clear();
    ui->rowsB->setValue(matrixB.GetRowCount());
    ui->columnsB->setValue(matrixB.GetColCount());
    ui->matrixBView->setText(QString::fromStdString(matrixB.ToString()));
}

void MainWindow::on_clearC_clicked()
{
    matrixC.Clear();
    ui->rowsC->setText(QString::fromStdString(to_string(matrixC.GetRowCount())));
    ui->columnsC->setText(QString::fromStdString(to_string(matrixC.GetColCount())));
    ui->matrixCView->setText(QString::fromStdString(matrixC.ToString()));
}

void MainWindow::on_start_clicked()
{
    switch(taskPerformType){
    case SingleUnit:
        switch(taskType){
        case Addition:
            matrixC = singleUnitSystem.Add(matrixA, matrixB);
            break;

        case Multiplication:
            matrixC = singleUnitSystem.Multiplicate(matrixA, matrixB);
            break;

        case Transposition:
            matrixC = singleUnitSystem.Transpose(matrixA);
            break;
        }
        break;

    case UnitsWithLocalMemory:
        unitsWithLocalMemory.SetCountOfUnits(10);
        switch(taskType){
        case Addition:
            matrixC = unitsWithLocalMemory.Add(matrixA, matrixB);
            break;
        case Multiplication:
            matrixC = unitsWithLocalMemory.Multiplicate(matrixA, matrixB);
            break;
        case Transposition:
            matrixC = unitsWithLocalMemory.Transpose(matrixA);
            break;
        }

        break;
    case UnitsWithSharedMemory:
        unitsWithSharedMemory.SetCountOfUnits(10);
        switch(taskType){
        case Addition:
            matrixC = unitsWithSharedMemory.Add(matrixA, matrixB);
            break;
        case Multiplication:
            matrixC = unitsWithSharedMemory.Multiplicate(matrixA, matrixB);
            break;
        case Transposition:
            matrixC = unitsWithSharedMemory.Transpose(matrixA);
            break;
        }

        break;
    }

    if(matrixC.GetRowCount() < 100 && matrixC.GetColCount() < 100){
        ui->matrixCView->setText(QString::fromStdString(matrixC.ToString()));
    }else{
        ui->matrixCView->setText("Матриця завелика для відображення!");
    }
}
