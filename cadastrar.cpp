#include "cadastrar.h"
#include "ui_cadastrar.h"
#include "car.h"
#include <QMessageBox>
#include <QVBoxLayout>


cadastrar::cadastrar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cadastrar)
{
    ui->setupUi(this);

    ui->lineEdit->setPlaceholderText("Modelo");
    ui->lineEdit_2->setPlaceholderText("Marca");
    ui->lineEdit_3->setPlaceholderText("Ano");
    ui->lineEdit_4->setPlaceholderText("Volume Porta Mala");
    ui->lineEdit_5->setPlaceholderText("Número de Passageiros");

    ui->pushButton->setIcon(QIcon(":/icons/save.png"));

    this->setWindowTitle("Cadastro de Carros");

    connect(ui->pushButton, &QPushButton::clicked, this, &cadastrar::saveCar);
}

cadastrar::~cadastrar()
{
    delete ui;
}

void cadastrar::saveCar(){
    // Verificar se todos os campos obrigatórios estão preenchidos
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() ||
        ui->lineEdit_3->text().isEmpty() || ui->lineEdit_4->text().isEmpty() ||
        ui->lineEdit_5->text().isEmpty()) {
        QMessageBox::warning(this, "Erro", "Todos os campos devem ser preenchidos.");
        return;
    }

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
