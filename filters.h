#ifndef FILTERS_H
#define FILTERS_H

#include <QWidget>
#include <QComboBox> // Adicionado para a definição do QComboBox

namespace Ui {
class filters;
}

class filters : public QWidget
{
    Q_OBJECT

public:
    explicit filters(QWidget *parent = nullptr);
    ~filters();

signals:
    void filtersApplied(QStringList filters);

private slots:
    void on_applyButton_clicked();

private:
    Ui::filters *ui;
    QComboBox *comboBoxFilters; // Adicionado o QComboBox
};

#endif // FILTERS_H
