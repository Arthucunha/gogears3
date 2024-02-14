#include "cadastrar.h"
#include "ui_cadastrar.h"
#include "car.h"
#include <QMessageBox>

cadastrar::cadastrar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastrar)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &cadastrar::saveCar);
}

cadastrar::~cadastrar()
{
    delete ui;
}

void cadastrar::saveCar(){
    Car car;

    car.model = ui->lineEdit->text();
    car.brand = ui->lineEdit_2->text();
    car.year = ui->lineEdit_3->text().toInt();
    car.trunkVolume = ui->lineEdit_4->text().toDouble();
    car.numPassengers = ui->lineEdit_5->text().toInt();

    QFile file("cars.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << car.model << ","
            << car.brand << ","
            << car.year << ","
            << car.trunkVolume << ","
            << car.numPassengers << "\n";

        file.close();
    }
    QMessageBox::information(this, "Sucesso", "Carro salvo com sucesso!");

ui->lineEdit->clear();
ui->lineEdit_2->clear();
ui->lineEdit_3->clear();
ui->lineEdit_4->clear();
ui->lineEdit_5->clear();
}
