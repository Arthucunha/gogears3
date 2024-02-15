#ifndef CADASTRAR_H
#define CADASTRAR_H

#include <QWidget>
#include "car.h"
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class cadastrar;
}
QT_END_NAMESPACE


class cadastrar : public QWidget
{
    Q_OBJECT


public:
    //explicit
    cadastrar(QWidget *parent = nullptr);
    ~cadastrar();

private slots:
    void saveCar();

private:
    Ui::cadastrar *ui;
};

#endif // CADASTRAR_H

