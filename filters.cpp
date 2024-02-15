#include "filters.h"
#include "ui_filters.h"
#include <QMessageBox>

filters::filters(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filters)
{
    ui->setupUi(this);

    // Cria o comboBoxFilters
    comboBoxFilters = new QComboBox(this);

    // Adiciona opções aos filtros no menu suspenso
    comboBoxFilters->addItem("Portabilidade");
    comboBoxFilters->addItem("Usabilidade");
    comboBoxFilters->addItem("Desempenho");
    comboBoxFilters->addItem("Segurança");

    // Define a geometria do comboBoxFilters
    comboBoxFilters->setGeometry(40, 60, 211, 26);

    // Conecta o sinal de aplicar filtros ao slot correspondente
    //connect(ui->applyButton, &QPushButton::clicked, this, &filters::on_applyButton_clicked);
}

filters::~filters()
{
    delete ui;
    delete comboBoxFilters; // Deletando o comboBoxFilters
}

void filters::on_applyButton_clicked()
{
    // Coleta o filtro selecionado
    QString selectedFilter = comboBoxFilters->currentText();

    // Verifica se algum filtro foi selecionado
    if (!selectedFilter.isEmpty()) {
        // Emite sinal com o filtro selecionado
        emit filtersApplied(QStringList() << selectedFilter);
    } else {
        QMessageBox::information(this, "Aplicar Filtros", "Por favor, selecione um filtro.");
    }
}
