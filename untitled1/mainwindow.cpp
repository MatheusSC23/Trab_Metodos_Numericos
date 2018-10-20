#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Pouso de Foguete");
    QStringList titulos;titulos<<"kº" << "Bissessao"<<"Posicão Falsa"<<"Newton-Rapson";

    ui->daniel->setColumnCount(4);
    ui->daniel->setHorizontalHeaderLabels(titulos);

    ui->daniel->insertRow(ui->daniel->rowCount());
    ui->daniel->setItem(ui->daniel->rowCount()-1 , 0 , new QTableWidgetItem("1"));
    ui->daniel->setItem(ui->daniel->rowCount()-1 , 1 , new QTableWidgetItem("2.5000"));
    ui->daniel->setItem(ui->daniel->rowCount()-1 , 2 , new QTableWidgetItem("2.3622"));
    ui->daniel->setItem(ui->daniel->rowCount()-1 , 3 , new QTableWidgetItem("2.1915"));

    ui->daniel->insertRow(ui->daniel->rowCount());
    ui->daniel->setItem(ui->daniel->rowCount()-1 , 0 , new QTableWidgetItem("2"));
    ui->daniel->setItem(ui->daniel->rowCount()-1 , 1 , new QTableWidgetItem("2.2500"));
    ui->daniel->setItem(ui->daniel->rowCount()-1 , 2 , new QTableWidgetItem("2.1811"));
    ui->daniel->setItem(ui->daniel->rowCount()-1 , 3 , new QTableWidgetItem("2.0821"));


}

MainWindow::~MainWindow()
{
    delete ui;
}
